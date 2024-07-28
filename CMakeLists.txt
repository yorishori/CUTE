cmake_minimum_required(VERSION 3.30.1)
project(CUTE VERSION 0.1)

#Add executable
add_executable(${PROJECT_NAME} src/main.cpp)

#Set up OpenGL
find_package(OpenGL REQUIRED)
message(STATUS "OpenGL (${OPENGL_FOUND}): ${OPENGL_INCLUDE_PATH}  ${OPENGL_LIBRARY}")
target_include_directories(${PROJECT_NAME} PRIVATE ${OPENGL_INCLUDE_PATH})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY})

#Set up GLEW Library
find_package(GLEW REQUIRED)
message(STATUS "GLEW (${GLEW_FOUND}): ${GLEW_INCLUDE_DIRS}  ${GLEW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})

#Set up GLFW Library
set(GLFW3_INCLUDE_DIR "C:/msys64/ucrt64/include/GLFW")
set(GLFW3_LIBRARIES "C:/msys64/ucrt64/lib/libglfw3.a")

IF(EXISTS "${GLFW3_INCLUDE_DIR}" AND EXISTS "${GLFW3_LIBRARIES}")
	message(STATUS "GLFW3 (TRUE): ${GLFW3_INCLUDE_DIR}  ${GLFW3_LIBRARIES}")
	target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW3_INCLUDE_DIR})
	target_link_libraries(${PROJECT_NAME} ${GLFW3_LIBRARIES})
ELSE()
	message(FATAL_ERROR "GLFW3 was not found ans is REQUIRED")
ENDIF()










