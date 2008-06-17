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
      
    private:
        Vector<3,float> origDir;
        
    public:
        TransformationEmitter(int sp) : PointEmitter<T>(sp) {
            
        }

        void SetPrototype(T* p) {
            origDir = p->direction;
            PointEmitter<T>::SetPrototype(p);
        }

        virtual int Emit(T* particles, int count) {
            Vector<3,float> position;
            Quaternion<float> rotation;
            GetAccumulatedTransformations(&position, &rotation);
            PointEmitter<T>::prototype->pos = position;
            PointEmitter<T>::prototype->direction = rotation.RotateVector(origDir);
            return PointEmitter<T>::Emit(particles, count);
        }

    };

  }
}

#endif
