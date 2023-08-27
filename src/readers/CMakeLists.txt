set(INCLUDES
UEvent.h
UParticle.h
UnigenEventCandidate.h
UnigenParticleCandidate.h
UnigenReader.h
)

set(SOURCES
UEvent.cxx
UParticle.cxx
UnigenEventCandidate.cxx
UnigenParticleCandidate.cxx
UnigenReader.cxx
)

root_generate_dictionary(Readers_Dict ${INCLUDES} ReadersLinkDef.h)

add_library(Readers SHARED ${SOURCES} Readers_Dict.cxx)
target_include_directories(Readers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Readers PUBLIC Base Selection ROOT::Core)