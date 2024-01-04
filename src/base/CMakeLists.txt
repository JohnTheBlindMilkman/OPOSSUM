set(INCLUDES
GenericResult.h
Particle.h
Analyser.h
Analysis.h
EventMixer.h
analyses/FemtoAnalysis.h
analyses/QAAnalysis.h
analyses/SpectraAnalysis.h
femto/CF.h
femto/CF1D.h
femto/FemtoConstants.hxx
femto/LCMS.h
femto/TPIWeightGenerator.h
femto/WeightGenerator.h
)

set(SOURCES
GenericResult.cxx
Particle.cxx
Analyser.cxx
EventMixer.cxx
analyses/FemtoAnalysis.cxx
analyses/QAAnalysis.cxx
analyses/SpectraAnalysis.cxx
femto/LCMS.cxx
femto/TPIWeightGenerator.cxx
)

root_generate_dictionary(Base_Dict ${INCLUDES} BaseLinkDef.h)

add_library(Base SHARED ${SOURCES} Base_Dict.cxx)
target_include_directories(Base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Base PUBLIC Readers ${ROOT_LIBRARIES})

add_executable(analyse_events analyse_events.cxx)
target_link_libraries(analyse_events Base)

add_executable(femto_analysis femto_analysis.cxx)
target_link_libraries(femto_analysis Base)