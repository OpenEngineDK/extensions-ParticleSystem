#ifndef _PARTICLES_MODIFIER_STATIC_ENERGY_H_
#define _PARTICLES_MODIFIER_STATIC_ENERGY_H_

#include <Particles/IModifier.h>
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Particles {

    template <class T> 
    class StaticEnergyModifier : public IModifier<T> {
    private:
        float energy;
    public:
        StaticEnergyModifier(float e) : energy(e) {}
        ~StaticEnergyModifier() {}
        
        virtual void Update(T* particles, int count) {
            for (int i = 0; i< count; i++) {
                //logger.info << particles[i].pos << logger.end;
                particles[i].energy += energy;
            }
        }

    };

}
}

#endif // _PARTICLES_MODIFIER_STATIC_ENERGY_H_
