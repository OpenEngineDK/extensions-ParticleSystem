#ifndef _PARTICLES_MODIFIER_STATIC_FIELD_H_
#define _PARTICLES_MODIFIER_STATIC_FIELD_H_

#include <Particles/IModifier.h>
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Particles {

    template <class T, class F> 
    class StaticFieldModifier : public IModifier<T> {
    private:
        void (T::*memberFunc)(F);
        F value;
    public:
        StaticFieldModifier(void (T::*ptr)(F), F val) 
            : memberFunc(ptr),value(val) {}
        ~StaticFieldModifier() {}
        
        virtual void Update(T* particles, int count) {
            for (int i = 0; i< count; i++) {
                //logger.info << particles[i].pos << logger.end;
                (particles[i].*memberFunc)(value);
            }
        }

    };

}
}

#endif // _PARTICLES_MODIFIER_STATIC_FIELD_H_
