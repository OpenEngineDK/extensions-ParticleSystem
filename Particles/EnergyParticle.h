#ifndef _PARTICLES_ENERGYPARTICLE_H_
#define _PARTICLES_ENERGYPARTICLE_H_

#include <Math/Vector.h>

using namespace OpenEngine::Math;
using namespace std;

namespace OpenEngine {
namespace Particles {
    
    template <class T>
    struct EnergyParticle : T {
        float energy;
        float lifespan;
        
        EnergyParticle() : T(), energy(0.0f), lifespan(0.0f) {}
        void AddToEnergy(float e) {energy += e;}
        
//        template <typename F> static pair<void (T::*)(F),int> AddMethodForField(string field);
//        template <float&> pair<void (T::*)(float&),int> AddMethodForField(string field) {
//            if (field == "energy")
//                return &T::AddToEnergy;
//            return make_pair<void (T::*)(float),int>(NULL,0);
//        }
//        
};

}
}

#endif
