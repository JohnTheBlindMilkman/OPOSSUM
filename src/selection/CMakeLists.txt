add_executable(select_events select_events.cxx EventCandidate.cxx TrackCandidate.cxx ParticleSelector.cxx)
target_link_libraries(select_events base)
link_directories(${ROOT_LIBRARY_DIR})
include_directories(${ROOT_INCLUDE_DIR})