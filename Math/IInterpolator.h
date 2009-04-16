/*
 *  IInterpolator.h
 *  OpenEngine
 *
 *  Created by Peter Kristensen on 02/05/08.
 *  Copyright 2008 Lucky Software. All rights reserved.
 *
 */

#ifndef _PARTICLE_IINTERPOLATOR_H_
#define _PARTICLE_IINTERPOLATOR_H_

namespace OpenEngine {
    namespace Math {
        template <typename T> 
        class IInterpolator {
        public:    
            T Interpolate(float dt);
            
            
        };
    }
}

#endif
