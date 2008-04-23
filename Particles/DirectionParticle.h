#ifndef _PARTICLES_DIRECTION_PARTICLE_H_
#define _PARTICLES_DIRECTION_PARTICLE_H_

#include <Math/Vector.h>

using namespace OpenEngine::Math;

namespace OpenEngine {
    namespace Particles {
        
        template <class T>
        struct DirectionParticle : T {
            Vector<3,float> direction;
            
            DirectionParticle() : T(), direction(Vector<3,float>(0,0,0)) {}
            inline void AddToDirection(Vector<3,float> v) {
                direction += v;
            }
            inline Vector<3,float> GetDirection() {
                return direction;
            }
        };
        
    }
}

#endif
