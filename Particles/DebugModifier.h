#ifndef _PARTICLES_MODIFIER_DEBUG_H_
#define _PARTICLES_MODIFIER_DEBUG_H_

#include <Particles/IModifier.h>
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Particles {

    template <class T> class DebugModifier : public IModifier<T> {
    public:
        DebugModifier() {}
        ~DebugModifier() {}
        
        virtual void Update(T* particles, int count) {
            for (int i = 0; i< count; i++) {
                //logger.info << particles[i].pos << logger.end;
                particles[i].pos = Vector<3,float>(random() % 42,
                                                   random() % 42,
                                                   random() % 42);
            }

//         virtual void Update(list<T*> particles) {
//             for (typename list<T*>::iterator itr = particles.begin();
//                  itr != particles.end();
//                  itr++) {
//                 logger.info << (*itr)->pos << logger.end;
//             }
        }

    };

}
}

#endif // _PARTICLES_MODIFIER_DEBUG_H_
