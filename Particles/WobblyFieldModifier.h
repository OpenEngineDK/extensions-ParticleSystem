#ifndef _PARTICLES_MODIFIER_WOBBLY_FIELD_H_
#define _PARTICLES_MODIFIER_WOBBLY_FIELD_H_

#include <Particles/IModifier.h>
#include <Logging/Logger.h>

template <typename V> static V Randomz(V val);

template <> static float Randomz<float>(float val) {
    return val*(1.0-(2.0*random() / float(RAND_MAX)));
}

template <> static Vector<3,float> Randomz<Vector<3,float> >(Vector<3,float> val) {
    return Vector<3,float>(Randomz<float>(val[0]) ,
                           Randomz<float>(val[1]),
                           Randomz<float>(val[2]));
}

template <> static Vector<4,float> Randomz<Vector<4,float> >(Vector<4,float> val) {
    return Vector<4,float>(Randomz<float>(val[0]) ,
                           Randomz<float>(val[1]),
                           Randomz<float>(val[2]),
                           Randomz<float>(val[3]));
}


namespace OpenEngine {
namespace Particles {

    template <class T, class F> 
    class WobblyFieldModifier : public IModifier<T> {
    private:
        void (T::*memberFunc)(F);
        F value;
        
    public:
        WobblyFieldModifier(void (T::*ptr)(F), F val) 
            : memberFunc(ptr),value(val) {}
        ~WobblyFieldModifier() {}
        
        virtual void Update(T* particles, int count) {
            for (int i = 0; i< count; i++) {
                //logger.info << particles[i].pos << logger.end;
                (particles[i].*memberFunc)(Randomz<F >(value));
            }
        }
        


    };

}
}

#endif // _PARTICLES_MODIFIER_WOBBLY_FIELD_H_
