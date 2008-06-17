#ifndef _PARTICLES_EMITTER_H_
#define _PARTICLES_EMITTER_H_

#include <Particles/IEmitter.h>

namespace OpenEngine {
namespace Particles {

    template <class T> class Emitter : public IEmitter {
    public:
        Emitter() {}
        virtual ~Emitter() {}
        
        virtual int Emit(T* particles, int count) { return 0;}
    };

}
}

#endif // _PARTICLES_EMITTER_H_
