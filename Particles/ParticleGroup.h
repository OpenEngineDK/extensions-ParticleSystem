#ifndef _PARTICLES_GROUP_H_
#define _PARTICLES_GROUP_H_


#include <Particles/IParticleGroup.h>
#include <Particles/IModifier.h>
#include <Particles/IEmitter.h>
#include <Logging/Logger.h>
#include <list>


using namespace std;

namespace OpenEngine {
namespace Particles {

    template <class T> class ParticleGroup : public IParticleGroup {
        
	protected:
        T* particles;
        int activeCount;
        list<IModifier<T>*> modifiers;
        int totalCount;
        IEmitter<T>* emitter;
        
    public:
        ParticleGroup(int size, IEmitter<T>* emit) : totalCount(size), emitter(emit) {
            particles = new T[size];
            activeCount = 0;
        }
        ~ParticleGroup() {}
        
        virtual void AddModifier(IModifier<T>* mof) {
            modifiers.push_back(mof);
        };


        virtual void Process(const float delta, const float perc) {
            EmitParticles();
            for(typename list<IModifier<T>* >::iterator itr = modifiers.begin();
                itr != modifiers.end();
                itr++) {
				IModifier<T>* mof = *itr;
				if (mof->active)
					mof->Update(particles, activeCount);
            }
        }

        void SetEmitter(IEmitter<T>* emit) {
            emitter = emit;
        }
        
        void EmitParticles() {
            if (emitter)
                activeCount += emitter->Emit(&(particles[activeCount]),
                                             totalCount-activeCount);
        }
        int ActiveCount() {return activeCount;}
        virtual T* GetParticles() {return particles;}

    };
        
}
}

#endif // _PARTICLES_GROUP_H_
