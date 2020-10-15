cmake_minimum_required (VERSION 3.5)

set (P_NAME "nn")

project (${P_NAME})
#find_package(OpenCV REQUIRED)
#find_package(Boost REQUIRED regex date_time system filesystem thread graph)


set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (include_dir "${PROJECT_SOURCE_DIR}/include/")

include_directories(${include_dir})
#include_directories(${OpenCV_INCLUDE_DIRS})
#include_directories(${BOOST_INCLUDE_DIRS})

file (GLOB source_files "${source_dir}/*.cpp")
file (GLOB include_files "${include_dir}/*.h")


add_executable (${P_NAME} ${source_files} ${include_files})
#target_link_libraries(prepareTrainData ${OpenCV_LIBS} ${Boost_LIBRARIES})