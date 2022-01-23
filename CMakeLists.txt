cmake_minimum_required(VERSION 3.5)
project(bt_example)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav2_msgs REQUIRED)
find_package(behaviortree_cpp_v3 REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

include_directories(
  include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

set(dependencies
  rclcpp
  rclcpp_action
  std_msgs
  geometry_msgs
  nav2_msgs
  behaviortree_cpp_v3
)

add_executable(tutorial_1
  src/tutorial_1.cpp
)
ament_target_dependencies(tutorial_1
	${dependencies}
)

add_executable(tutorial_2
  src/tutorial_2.cpp
)
ament_target_dependencies(tutorial_2
	${dependencies}
)

add_executable(tutorial_3
  src/tutorial_3.cpp
)
ament_target_dependencies(tutorial_3
	${dependencies}
)

add_executable(tutorial_4
  src/tutorial_4.cpp
)
ament_target_dependencies(tutorial_4
	${dependencies}
)

add_executable(tutorial_4_reactive_sequence
  src/tutorial_4_reactive_sequence.cpp
)
ament_target_dependencies(tutorial_4_reactive_sequence
	${dependencies}
)

add_executable(tutorial_5
  src/tutorial_5.cpp
  src/crossdoor_nodes.cpp
)
ament_target_dependencies(tutorial_5
	${dependencies}
)

add_executable(tutorial_6
  src/tutorial_6.cpp
  src/crossdoor_nodes.cpp
)
ament_target_dependencies(tutorial_6
	${dependencies}
)

add_executable(tutorial_7
  src/tutorial_7.cpp
  src/crossdoor_nodes.cpp
)
ament_target_dependencies(tutorial_7
	${dependencies}
)

add_executable(coroutine_recap
  src/coroutine_recap.cpp
  src/crossdoor_nodes.cpp
)
ament_target_dependencies(coroutine_recap
	${dependencies}
)

add_executable(tutorial_8
  src/tutorial_8.cpp
  src/crossdoor_nodes.cpp
)
ament_target_dependencies(tutorial_8
	${dependencies}
)

add_executable(tutorial_9
  src/tutorial_9.cpp
  src/crossdoor_nodes.cpp
)
ament_target_dependencies(tutorial_9
	${dependencies}
)

install (TARGETS
  tutorial_1
  tutorial_2
  tutorial_3
  tutorial_4
  tutorial_4_reactive_sequence
  tutorial_5
  tutorial_6
  tutorial_7
  coroutine_recap
  tutorial_8
  tutorial_9
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY bt_xml include
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
