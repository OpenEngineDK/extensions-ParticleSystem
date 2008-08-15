#ifndef _PARTICLES_SYSTEM_H_
#define _PARTICLES_SYSTEM_H_

#include <Core/IModule.h>
#include <Particles/ParticleGroup.h>
#include <Particles/IParticle.h>

#include <list>

using OpenEngine::Core::IModule;
using namespace std;

namespace OpenEngine {
namespace Particles {

    class ParticleSystem : public IModule {
    private:
        list<IParticleGroup* > groups;
        
    public:
        ParticleSystem();
        ~ParticleSystem();

        void Handle(OpenEngine::Core::InitializeEventArg arg);
        void Handle(OpenEngine::Core::ProcessEventArg arg);
        void Handle(OpenEngine::Core::DeinitializeEventArg arg);

        void AddGroup(IParticleGroup* group);

    };

}
}


#endif // _PARTICLES_SYSTEM_H_

