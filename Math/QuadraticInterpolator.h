/*
 *  QuadraticInterpolator.h
 *  OpenEngine
 *
 *  Created by Peter Kristensen on 02/05/08.
 *  Copyright 2008 Lucky Software. All rights reserved.
 *
 */

#ifndef _PARTICLES_QUADRATIC_INTERPOLATOR_H_
#define _PARTICLES_QUADRATIC_INTERPOLATOR_H_

#include <Math/IInterpolator.h>

namespace OpenEngine {
    namespace Math {
        template <typename T, int N> 
        class QuadraticInterpolator : public IInterpolator<T> {
        public:
            T points[N];
            
            QuadraticInterpolator() {
                for (int i=0;i<N;i++)
                    points[i] = 0;
            }
            
            T Interpolate(float dt) {
                T ret;
                for (int i=0; i<N; i++) {
                    ret += points[i]*powf(dt, N);
                }
                return ret;
            }
            
        };
    }
}

#endif
