#ifndef _PARTICLES_IPARTICLE_H_
#define _PARTICLES_IPARTICLE_H_

#include<Math/Vector.h>

using namespace OpenEngine::Math;

namespace OpenEngine {
namespace Particles {

struct IParticle {
    Vector<3,float> pos;

    IParticle() : pos(Vector<3,float>(0,0,0)){}
    inline void SetPos(Vector<3,float> p) {pos = p;}
    inline void AddToPos(Vector<3,float> p) {
        SetPos(pos + p);
    }
};

}
}

#endif
