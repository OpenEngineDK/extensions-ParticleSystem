#ifndef _PARTICLES_IEMITTER_H_
#define _PARTICLES_IEMITTER_H_

namespace OpenEngine {
namespace Particles {

    template <class T> class IEmitter {
    public:
        IEmitter() {}
        virtual ~IEmitter() {}
        
        virtual int Emit(T* particles, int count) { return 0;}
    };

}
}

#endif // _PARTICLES_IEMITTER_H_
