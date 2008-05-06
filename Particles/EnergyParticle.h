#ifndef _PARTICLES_ENERGYPARTICLE_H_
#define _PARTICLES_ENERGYPARTICLE_H_

#include<Math/Vector.h>

using namespace OpenEngine::Math;

namespace OpenEngine {
namespace Particles {
    
    template <class T>
    struct EnergyParticle : T {
        float energy;
        float lifespan;
        
        EnergyParticle() : T(), energy(0.0f), lifespan(0.0f) {}
        void AddToEnergy(float e) {energy += e;}
};

}
}

#endif
