include(${ROOT_USE_FILE})
#include_directories(${ROOT_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})
#link_directories(${ROOT_LIBRARY_DIR})

set(INCLUDES 
ParticleSelector.h
EventCandidate.h
TrackCandidate.h
PairCandidate.h
GenericCandidate.h
ObservableList.h
)

set(SOURCES
ParticleSelector.cxx
EventCandidate.cxx
TrackCandidate.cxx
PairCandidate.cxx
)

root_generate_dictionary(ParticleSelector_Dict  ${INCLUDES} LINKDEF ParticleSelectorLinkDef.h)

add_library(Selection SHARED ${SOURCES} ParticleSelector_Dict.cxx)
target_include_directories(Selection PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Selection PUBLIC Utils ROOT::Core)

add_executable(select_events select_events.cxx)
target_link_libraries(select_events PRIVATE Selection)