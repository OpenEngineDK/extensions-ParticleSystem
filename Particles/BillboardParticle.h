#ifndef _PARTICLES_BILLBOARDPARTICLE_H_
#define _PARTICLES_BILLBOARDPARTICLE_H_

#include <Particles/IParticle.h>
#include <Resources/ResourceManager.h>
#include <Renderers/OpenGL/TextureLoader.h>


using namespace OpenEngine::Renderers::OpenGL;
using namespace OpenEngine::Resources;

namespace OpenEngine {
namespace Particles {

     
    template <class T> struct BillBoardParticle : T {
        ITextureResourcePtr texr;
        float size;
        Vector<4,float> color;
        float rotation;
        int blendSrc,blendDst;
        //bool glow;
        
        BillBoardParticle() : T() {
            texr = ResourceManager<ITextureResource>::Create("particle.tga");
            size = 1.0f;
            rotation = 0.0f;
            color = Vector<4,float>(1,0,0,1);
            blendSrc = 4;
            blendDst = 1;
        }
        inline void SetColor(Vector<4,float> c) {
            color = c;
        }
        inline void AddToColor(Vector<4,float> c) {
            color += c;
        }
        inline void AddToRotation(float d) {
            rotation += d;
        }
        inline void AddToSize(float d) {
            size += d;
        }
        inline void SetSize(float s) {
            size = s;
        }
    };

    template <class T, class G> class BillBoardRenderNode : public RenderNode {
        G* group;
    public:
        BillBoardRenderNode(G* pg) 
  : group(pg) {}
        virtual void Apply(IRenderingView *rv) {
            static GLenum blendFnc[] = {
                GL_ZERO, // 0
                GL_ONE,
                GL_DST_COLOR,
                GL_ONE_MINUS_DST_COLOR,
                GL_SRC_ALPHA,  // 4
                GL_ONE_MINUS_SRC_ALPHA,
                GL_DST_ALPHA,
                GL_ONE_MINUS_DST_ALPHA,
                GL_SRC_ALPHA_SATURATE,
                GL_SRC_COLOR,
                GL_ONE_MINUS_SRC_COLOR // 10
            };
            
            
            
            glPushAttrib(GL_LIGHTING);    
            glDisable(GL_LIGHTING);
            glDepthMask(GL_FALSE);
            //glClearColor(1.0f,1.0f,1.0f,0.5f);
            glEnable(GL_BLEND);
            glEnable(GL_TEXTURE_2D);

            //glBlendFunc(GL_ONE,GL_ONE_MINUS_SRC_ALPHA);

            GLenum curBlendSrc = GL_SRC_ALPHA, curBlendDst = GL_ONE;
            glBlendFunc(curBlendSrc,curBlendDst);
            int lastTex = 0;

            //glBegin(GL_LINES);
            for (int i=0;i<group->ActiveCount();i++) {
                T& pat = (group->GetParticles()[i]);
                if (curBlendSrc != blendFnc[pat.blendSrc] ||
                    curBlendDst != blendFnc[pat.blendDst]) {
                    curBlendSrc = blendFnc[pat.blendSrc];
                    curBlendDst = blendFnc[pat.blendDst];
                    glBlendFunc(curBlendSrc, curBlendDst);
                }
                ITextureResourcePtr texr = pat.texr;
                if (texr != NULL) {
                    if (texr->GetID() == 0) {
                        OpenGL::TextureLoader* tl = new OpenGL::TextureLoader();
                        tl->LoadTextureResource(texr);
                        logger.info << texr->GetID() << logger.end;
                    }
                    if (lastTex != texr->GetID()) {
                        glBindTexture(GL_TEXTURE_2D, texr->GetID());
                        lastTex = texr->GetID();
                    }
                    
                } else {
                    glBindTexture(GL_TEXTURE_2D, 0);
                    lastTex = 0;
                }

                glPushMatrix();
                

                glTranslatef(pat.pos[0], pat.pos[1], pat.pos[2]);
                
                // billboard
                float modelview[16];
                glGetFloatv(GL_MODELVIEW_MATRIX, modelview);
                for( int i=0; i<3; i++ ) 
                    for( int j=0; j<3; j++ ) {
                        if ( i==j )
                            modelview[i*4+j] = 1.0;
                        else
                            modelview[i*4+j] = 0.0;
                    }
                
                glLoadMatrixf(modelview);


                glRotatef(pat.rotation, 0,0,1);

                float c[4];
                pat.color.ToArray(c);
                glColor4fv(c);
                
                float s = pat.size/2.0;
                
                glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0);
                glVertex3f(-1.0*s, -1.0*s, 0.0);
                glTexCoord2f(0.0, 1.0);
                glVertex3f(-1.0*s, s*1.0f, 0);
                glTexCoord2f(1.0, 1.0);
                glVertex3f(s*1, s*1, 0);
                glTexCoord2f(1.0, 0.0);
                glVertex3f(s*1, -1*s, 0);

                glEnd();

                glPopMatrix();
            }
            
    //if (l) glEnable(GL_LIGHTING);
    glDisable(GL_BLEND);
    //glDepthMask(GL_TRUE);
    glPopAttrib();

        }
    };


}
}

#endif
