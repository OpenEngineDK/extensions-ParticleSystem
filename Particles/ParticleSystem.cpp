#include <Particles/ParticleSystem.h>
#include <Logging/Logger.h>

namespace OpenEngine {
  namespace Particles {

    ParticleSystem::ParticleSystem() {}

    ParticleSystem::~ParticleSystem() {}

    void ParticleSystem::Handle(OpenEngine::Core::InitializeEventArg arg) {}

    void ParticleSystem::Handle(OpenEngine::Core::ProcessEventArg arg) {

      float delta = arg.approx / 1000.0;
      for(list<IParticleGroup*>::iterator itr = groups.begin();
          itr != groups.end();
          itr++) {
        (*itr)->Process(delta,1);
      }
    }
  
    void ParticleSystem::Handle(OpenEngine::Core::DeinitializeEventArg arg) {}
  
    void ParticleSystem::AddGroup(IParticleGroup* group) {
      if (group != NULL)
        groups.push_back(group);
    }
  
  }
}


