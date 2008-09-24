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

    template <class T> class EnergyParticleGroup : public
    ParticleGroup<T> {
    public:
        enum RespawnMode {
            NONE,
            ALL,
            CONTINUOUS
        };

    private:
//        T* particles;
//        int activeCount;
//        list<IModifier<T>*> modifiers;
//        int totalCount;
//        IEmitter<T>* emitter;
        int deadCount;
    public:
        bool active;
        RespawnMode mode;


        EnergyParticleGroup(int size, Emitter<T>* emit) 
            : ParticleGroup<T>(size, emit), 
              deadCount(0),
              active(false),
              mode(CONTINUOUS) {}
        ~EnergyParticleGroup() {}
        
        void SetMode(RespawnMode m) {
            mode = m;
        }

        void Spawn() {
            active = true;
            deadCount = 0;
        }

        virtual int EmitParticles() {
            switch (mode) {
            case CONTINUOUS:
                return ParticleGroup<T>::EmitParticles();
                break;
            
            case ALL:
                if (deadCount <
                    ParticleGroup<T>::totalCount)  {
                    int emittet = 
                        ParticleGroup<T>::EmitParticles();
                deadCount += emittet;
                return emittet;
                }
                break;
                
            default:
                ;
            }
            return 0;
        }

        virtual void Process(const float delta, const float perc) {
			if (active) {
                
                ParticleGroup<T>::Process(delta, perc);
                KillDeadParticles();
            }
        }

        void KillDeadParticles() {
            for(int i=0;i<ParticleGroup<T>::activeCount;i++) {
                
                if (ParticleGroup<T>::particles[i].energy <= 0.0f) {
                    // found a dead particle, replace it with the last one
                    ParticleGroup<T>::particles[i] = ParticleGroup<T>::particles[ParticleGroup<T>::activeCount-1];
                    ParticleGroup<T>::activeCount--;

                }
            }
        }
    };
        
}
}

#endif // _PARTICLES_ENERGY_GROUP_H_
