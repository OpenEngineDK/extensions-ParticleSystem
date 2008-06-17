#ifndef _PARTICLES_TRANSEMITTER_H_
#define _PARTICLES_TRANSEMITTER_H_

#include <Particles/PointEmitter.h>
#include <Scene/TransformationNode.h>

using OpenEngine::Scene::TransformationNode;

namespace OpenEngine {
  namespace Particles {
    
      template <class T> class TransformationEmitter : public PointEmitter<T>,
                                                       public TransformationNode
    {
      

    public:
        TransformationEmitter(int sp) : PointEmitter<T>(sp) {
            
        }

        virtual int Emit(T* particles, int count) {
            Vector<3,float> position;
            Quaternion<float> rotation;
            GetAccumulatedTransformations(&position, &rotation);
            PointEmitter<T>::prototype->pos = position;
            return PointEmitter<T>::Emit(particles, count);
        }

    };

  }
}

#endif
