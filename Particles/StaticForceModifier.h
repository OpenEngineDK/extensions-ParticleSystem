#ifndef _PARTICLES_MODIFIER_STATIC_FORCE_H_
#define _PARTICLES_MODIFIER_STATIC_FORCE_H_

#include <Particles/IModifier.h>
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Particles {

    template <class T> 
    class StaticForceModifier : public IModifier<T> {
    private:
        Vector<3,float> force;
    public:
        StaticForceModifier(Vector<3,float> force) : force(force) {}
        ~StaticForceModifier() {}
        
        virtual void Update(T* particles, int count) {
            for (int i = 0; i< count; i++) {
                //logger.info << particles[i].pos << logger.end;
                particles[i].SetPos(particles[i].pos+force);
            }
        }

    };

}
}

#endif // _PARTICLES_MODIFIER_STATIC_FORCE_H_
