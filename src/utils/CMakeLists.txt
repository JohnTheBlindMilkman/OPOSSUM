set(INCLUDES 
argparse.hpp
ArgumentParser.h
ConfigParser.h
CutEntry.h
CutParser.h
json.hpp
Logger.h
ProgressBar.h
)

set(SOURCES 
ArgumentParser.cxx
ConfigParser.cxx
CutEntry.cxx
CutParser.cxx
Logger.cxx
ProgressBar.cxx
)

add_library(Utils SHARED ${SOURCES})
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})