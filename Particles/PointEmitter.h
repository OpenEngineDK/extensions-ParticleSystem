#ifndef _PARTICLES_POINTEMITTER_H_
#define _PARTICLES_POINTEMITTER_H_

#include <Particles/IEmitter.h>

namespace OpenEngine {
namespace Particles {

    template <class T> class PointEmitter : public IEmitter<T> {

    public:
        T* prototype;
        int speed;
        PointEmitter(int sp) : speed(sp) {
            prototype = new T();
        }
        ~PointEmitter() {}
        
        virtual int Emit(T* particles, int count) {
            int num = max(min(count, speed),0);
            for (int i =0;i<num; i++) {
                particles[i] = *prototype;
                //             particles[i].pos = Vector<3,float>(1,4,2);
                //             particles[i].energy = 42.0f;
            }
            return num;
        }
        void SetPrototype(T* p) {
            delete prototype;
            prototype = p;
        }
        //     bool Emit(T& particle) {
        //         particle.pos = Vector<3,float>(1,2,3);
        //         return true;
        //     }
    };


}
}

#endif // _PARTICLES_POINTEMITTER_H_
