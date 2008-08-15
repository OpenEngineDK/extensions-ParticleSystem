#include <Particles/ParticleSystem.h>
#include <Logging/Logger.h>

namespace OpenEngine {
  namespace Particles {

    ParticleSystem::ParticleSystem() {}

    ParticleSystem::~ParticleSystem() {}

    void ParticleSystem::Handle(OpenEngine::Core::InitializeEventArg arg) {}

    void ParticleSystem::Handle(OpenEngine::Core::ProcessEventArg arg) {

      float delta = 1;
      float perc = 1;
      using namespace OpenEngine::Logging;
      logger.error << "Timing Broken in ParticleSystem" << logger.end;

      for(list<IParticleGroup*>::iterator itr = groups.begin();
          itr != groups.end();
          itr++) {
        (*itr)->Process(delta,perc);
      }
    }
  
    void ParticleSystem::Handle(OpenEngine::Core::DeinitializeEventArg arg) {}
  
    void ParticleSystem::AddGroup(IParticleGroup* group) {
      if (group != NULL)
        groups.push_back(group);
    }
  
  }
}


