#include <Particles/ParticleSystem.h>

namespace OpenEngine {
namespace Particles {

    ParticleSystem::ParticleSystem() {}

    ParticleSystem::~ParticleSystem() {}

    void ParticleSystem::Initialize() {}
    void ParticleSystem::Deinitialize() {}
    
    bool ParticleSystem::IsTypeOf(const std::type_info& inf) {
        return (typeid(ParticleSystem) == inf);
    }

    void ParticleSystem::Process(const float delta, const float perc) {
        for(list<IParticleGroup*>::iterator itr = groups.begin();
            itr != groups.end();
            itr++) {
            (*itr)->Process(delta,perc);
        }
    }

    void ParticleSystem::AddGroup(IParticleGroup* group) {
        if (group != NULL)
            groups.push_back(group);
    }

}
}


