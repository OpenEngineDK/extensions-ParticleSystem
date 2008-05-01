#ifndef _PARTICLES_IMODIFIER_H_
#define _PARTICLES_IMODIFIER_H_

#include <Particles/IParticle.h>

#include <list>

using namespace std;


namespace OpenEngine {
namespace Particles {

    template <class T> class IModifier {
    public:
		bool active;
		
        IModifier() : active(true) {}; 
        virtual ~IModifier() {};

        //virtual void Update(list<T*> particles) {};
        virtual void Update(T* particles, int count) {};
    };

}
}

#endif // _PARTICLES_IMODIFIER_H_
