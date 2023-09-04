include(${ROOT_USE_FILE})
#include_directories(${ROOT_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR})
#link_directories(${ROOT_LIBRARY_DIR})

set(INCLUDES 
ParticleSelector.h
EventCandidate.h
TrackCandidate.h
cuts/EventCut.h
cuts/TrackCut.h
cuts/PairCut.h
cuts/trackCuts/JJTrackCut.h
cuts/eventCuts/JJEventCut.h
cuts/pairCuts/JJPairCut.h
)

set(SOURCES
ParticleSelector.cxx
EventCandidate.cxx
TrackCandidate.cxx
cuts/EventCut.cxx
cuts/TrackCut.cxx
cuts/PairCut.cxx
cuts/trackCuts/JJTrackCut.cxx
cuts/eventCuts/JJEventCut.cxx
cuts/pairCuts/JJPairCut.cxx
)

root_generate_dictionary(ParticleSelector_Dict  ${INCLUDES} LINKDEF ParticleSelectorLinkDef.h)

add_library(Selection SHARED ${SOURCES} ParticleSelector_Dict.cxx)
target_include_directories(Selection PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Selection PUBLIC ROOT::Core ROOT::ROOTVecOps)

add_executable(select_events select_events.cxx)
target_link_libraries(select_events PRIVATE Selection)