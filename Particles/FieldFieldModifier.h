#ifndef _PARTICLES_MODIFIER_FIELD_FIELD_H_
#define _PARTICLES_MODIFIER_FIELD_FIELD_H_

#include <Particles/IModifier.h>
#include <Logging/Logger.h>

namespace OpenEngine {
    namespace Particles {
        
        template <class T, class F> 
        class FieldFieldModifier : public IModifier<T> {
        private:
            void (T::*setFunc)(F);
            F (T::*getFunc)();
        public:
            FieldFieldModifier(void (T::*ptr)(F), F (T::*ptr2)()) 
            : setFunc(ptr),getFunc(ptr2) {}
            ~FieldFieldModifier() {}
            
            virtual void Update(T* particles, int count) {
                for (int i = 0; i< count; i++) {
                    //logger.info << particles[i].pos << logger.end;
                    F v = (particles[i].*getFunc)();
                    (particles[i].*setFunc)(v);
                }
            }
            
        };
        
    }
}

#endif // _PARTICLES_MODIFIER_FIELD_FIELD_H_
