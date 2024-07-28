#include <iostream>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;
void error_callback(int error, const char* description);
void close_window(GLFWwindow* window);

int main(int argc, char* argv[])
{
    if(!glfwInit())
    {
        cout << "An error ocurred initializing GLFW";
    }

    glfwSetErrorCallback(error_callback);


    GLFWwindow* window = glfwCreateWindow(500, 500, "Test", NULL, NULL);
    if (!window)
    {
        cout << "An error ocurred creating window";
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowCloseCallback(window, close_window);


     // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll for and process events
        glfwPollEvents();

        // Rendering code would go here

        // Swap front and back buffers
        glfwSwapBuffers(window);
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;



}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void close_window(GLFWwindow* window)
{
    glfwDestroyWindow(window);
}
