
# Create the extension library
ADD_LIBRARY(Extensions_ParticleSystem
    Particles/ParticleSystem.cpp
    Particles/ParticleSystem.h
    Particles/BillboardParticle.h
    Particles/EnergyParticle.h
    Particles/StaticFieldModifier.h
    Particles/PointerFieldModifier.h
    Particles/LineParticle.h
    Particles/StaticenergyModifier.h
    Particles/Modifiers.h
    Particles/Particles.h

)
TARGET_LINK_LIBRARIES(Extensions_ParticleSystem
	OpenEngine_Resources	
)
