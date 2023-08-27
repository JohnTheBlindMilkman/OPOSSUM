add_library(Base SHARED Analysis.cxx Particle.cxx)
install(TARGETS Base DESTINATION lib)