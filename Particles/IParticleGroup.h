#ifndef _PARTICLES_IGROUP_H_
#define _PARTICLES_IGROUP_H_

namespace OpenEngine {
namespace Particles {

    class IParticleGroup {
    public:
        IParticleGroup() {}; 
        virtual ~IParticleGroup() {};

        virtual void Process(const float, const float) {};
        
    };

}
}

#endif // _PARTICLES_IGROUP_H_
