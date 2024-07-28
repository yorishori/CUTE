cmake_minimum_required(VERSION 3.30.1)
project(CUTE VERSION 0.1)

#Add executable
add_executable(${PROJECT_NAME} src/main.cpp)


#Set up GLFW Library
find_package(GLFW3 REQUIRED)
set(GLFW3_INCLUDE_DIR "C:/msys64/ucrt64/include/GLFW")
set(GLFW3_LIBRARIES "C:/msys64/ucrt64/lib/libglfw3.a")
message(STATUS "GLEW (${GLFW3_FOUND}): ${GLFW3_INCLUDE_DIR}  ${GLFW3_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW3_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${GLFW3_LIBRARIES})

#Set up GLEW Library
find_package(GLEW REQUIRED)
message(STATUS "GLEW (${GLEW_FOUND}): ${GLEW_INCLUDE_DIRS}  ${GLEW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})






