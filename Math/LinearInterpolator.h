/*
 *  LinearInterpolator.h
 *  OpenEngine
 *
 *  Created by Peter Kristensen on 02/05/08.
 *  Copyright 2008 Lucky Software. All rights reserved.
 *
 */

#ifndef _PARTICLES_LINEAR_INTERPOLATOR_H_
#define _PARTICLES_LINEAR_INTERPOLATOR_H_

#include <Math/IInterpolator.h>

namespace OpenEngine {
    namespace Math {
        template <typename T> 
        class LinearInterpolator : public IInterpolator<T> {
        public:
            pair<float,T> *points;
            int size;
            
            LinearInterpolator(int size) : size(size) {
                points = new pair<float,T>[size];
            }
            
            void AddPoint(int i, float t, T v) {
                if (i >= size) throw i;
                points[i] = make_pair(t, v);
            }
            
            T Interpolate(float dt) {
                int i = 1;
                while (points[i].first < dt && i < size)
                    i++;
                
                float x1 = points[i-1].first;
                float x2 = points[i].first;
                float diff1 = x2-x1;
                float diff2 = dt - x1;
                
                T y1 = points[i-1].second;
                T y2 = points[i].second;
                
                
                return y1 + (y2 - y1)*(diff2/diff1);
            }
            
        };
    }
}

#endif
