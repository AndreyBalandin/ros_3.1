cmake_minimum_required(VERSION 2.8.3)
project(converter)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  visualization_msgs
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES my_server
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(converter src/converter.cpp)
target_link_libraries(converter ${catkin_LIBRARIES})
