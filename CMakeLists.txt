
# Create the extension library
ADD_LIBRARY(Extensions_ParticleSystem
    Particles/ParticleSystem.cpp    
)
TARGET_LINK_LIBRARIES(Extensions_ParticleSystem
	OpenEngine_Resources	
)
