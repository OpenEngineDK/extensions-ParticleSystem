#ifndef _PARTICLES_ENERGY_GROUP_H_
#define _PARTICLES_ENERGY_GROUP_H_


#include <Particles/IParticleGroup.h>
#include <Particles/IModifier.h>
#include <Particles/IEmitter.h>
#include <Logging/Logger.h>
#include <list>


using namespace std;

namespace OpenEngine {
namespace Particles {

    template <class T> class EnergyParticleGroup : public IParticleGroup {
    private:
        T* particles;
        int activeCount;
        list<IModifier<T>*> modifiers;
        int totalCount;
        IEmitter<T>* emitter;
        
    public:
        EnergyParticleGroup(int size, IEmitter<T>* emit) : totalCount(size), emitter(emit) {
            particles = new T[size];
            activeCount = 0;
        }
        ~EnergyParticleGroup() {}
        
        virtual void AddModifier(IModifier<T>* mof) {
            modifiers.push_back(mof);
        };


        virtual void Process(const float delta, const float perc) {
            EmitParticles();
            for(typename list<IModifier<T>* >::iterator itr = modifiers.begin();
                itr != modifiers.end();
                itr++) {
                (*itr)->Update(particles, activeCount);
            }
            KillDeadParticles();
        }

        void SetEmitter(IEmitter<T>* emit) {
            emitter = emit;
        }
        
        void EmitParticles() {
            if (emitter)
                activeCount += emitter->Emit(&(particles[activeCount]),
                                             totalCount-activeCount);
        }
        
        void KillDeadParticles() {
            for(int i=0;i<activeCount;i++) {
                if (particles[i].energy <= 0.0f) {
                    // found a dead particle, replace it with the last one
                    particles[i] = particles[activeCount-1];
                    activeCount--;
                }
            }
        }
        int ActiveCount() {return activeCount;}
        virtual T* GetParticles() {return particles;}

    };
        
}
}

#endif // _PARTICLES_ENERGY_GROUP_H_
