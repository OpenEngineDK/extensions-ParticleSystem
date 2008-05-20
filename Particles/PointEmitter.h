#ifndef _PARTICLES_POINTEMITTER_H_
#define _PARTICLES_POINTEMITTER_H_

#include <Particles/IEmitter.h>

namespace OpenEngine {
namespace Particles {

    template <class T> class PointEmitter : public IEmitter<T> {

    public:
        T* prototype;
        int speed;
        list<IModifier<T>*> modifiers;

        PointEmitter(int sp) : speed(sp) {
            prototype = new T();
        }
        ~PointEmitter() {}
        
        virtual void AddModifier(IModifier<T>* mof) {
            modifiers.push_back(mof);
        }

        virtual int Emit(T* particles, int count) {
            int num = max(min(count, speed),0);
            for (int i =0;i<num; i++) {
                particles[i] = *prototype;

            }
            
            for(typename list<IModifier<T>* >::iterator itr = modifiers.begin();
                itr != modifiers.end();
                itr++) {
				IModifier<T>* mof = *itr;
                //logger.info << "running modifier : "<< mof << logger.end;
				if (mof->active)
					mof->Update(particles, count);
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
