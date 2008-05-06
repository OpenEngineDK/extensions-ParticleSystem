/*
 *  InterpolatingFieldModifier.h
 *  OpenEngine
 *
 *  Created by Peter Kristensen on 02/05/08.
 *  Copyright 2008 Lucky Software. All rights reserved.
 *
 */

#ifndef _PARTICLES_MODIFIER_INTERPOL_FIELD_H_
#define _PARTICLES_MODIFIER_INTERPOL_FIELD_H_

#include <Particles/IModifier.h>
#include <Math/IInterpolator.h>
#include <Logging/Logger.h>

namespace OpenEngine {
    namespace Particles {
        
        template <class T, class F, class I> 
        class InterpolatingFieldModifier : public IModifier<T> {
        private:
            void (T::*memberFunc)(F);
            I* interpol;
            
        public:
            InterpolatingFieldModifier(void (T::*ptr)(F), I* interp) 
            : memberFunc(ptr), interpol(interp) {}
            InterpolatingFieldModifier() {}
            
            virtual void Update(T* particles, int count) {
                for (int i = 0; i< count; i++) {
                    //logger.info << particles[i].pos << logger.end;
                    float span = particles[i].lifespan;
                    float energy = particles[i].energy;
                    (particles[i].*memberFunc)(interpol->Interpolate((span-energy)/span));
                }
            }
            
        };
        
    }
}

#endif // _PARTICLES_MODIFIER_INTERPOL_FIELD_H_
