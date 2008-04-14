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

        void Initialize();
        void Process(const float, const float);
        void Deinitialize();
        bool IsTypeOf(const std::type_info& inf);

        void AddGroup(IParticleGroup* group);

    };

}
}


#endif // _PARTICLES_SYSTEM_H_

