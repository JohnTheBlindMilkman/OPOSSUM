set(INCLUDES
Result.h
Particle.h
Analyser.h
Analysis.h
)

set(SOURCES
Result.cxx
Particle.cxx
Analyser.cxx
Analysis.cxx
)

#root_generate_dictionary(Readers_Dict ${INCLUDES} ReadersLinkDef.h)

add_library(Base SHARED ${SOURCES})
target_include_directories(Base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Base PUBLIC Readers)
