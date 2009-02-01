#ifndef _PARTICLES_LINEPARTICLE_H_
#define _PARTICLES_LINEPARTICLE_H_

#include <Particles/ParticleGroup.h>
#include <Particles/IParticle.h>
#include <Scene/RenderNode.h>
#include <Renderers/IRenderingView.h>
#include <Particles/PointEmitter.h>
#include <Meta/OpenGL.h>
#include <Logging/Logger.h>

using namespace OpenEngine::Renderers;
using namespace OpenEngine::Scene;

namespace OpenEngine {
namespace Particles {

    template <class T> struct LineParticle : T {
        Vector<3,float> prevPos;

        LineParticle() : T(), prevPos(Vector<3,float>(0,0,0)) {}
        inline void SetPos(Vector<3,float> p) {
            prevPos = T::pos;
            T::SetPos(p);
        }
        inline void AddToPos(Vector<3,float> p) {
            SetPos(T::pos + p);
        }
    };

    template <class T, class G> class LineRenderNode : public RenderNode {
        G* group;
    public:
        LineRenderNode(G* pg) 
  : group(pg) {}
        virtual void Apply(IRenderingView *rv) {
            GLboolean t = glIsEnabled(GL_TEXTURE_2D);
            GLboolean l = glIsEnabled(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
            glDisable(GL_LIGHTING);


            glColor3f(0.0f, 0.0f, 1.0f);
            glBegin(GL_LINES);
            glLineWidth(4.0f);
            for (int i=0;i<group->ActiveCount();i++) {
                T lp = group->GetParticles()[i];
                glVertex3f(lp.pos[0], lp.pos[1], lp.pos[2]);
                glVertex3f(lp.prevPos[0], lp.prevPos[1], lp.prevPos[2]);
            }
            glEnd();
            
            if (t) glEnable(GL_TEXTURE_2D);
            if (l) glEnable(GL_LIGHTING);

        }
    };

}
}



#endif // _PARTICLES_LINEPARTICLE_H_
