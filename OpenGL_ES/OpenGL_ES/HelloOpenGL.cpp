/*****************************************************************//**
 * \file   HelloOpenGL.cpp
 * \brief  Create a simple application to render a window
 * For testing dependencies located in the current directory.
 * 
 * \author Xuhua Huang
 * \date   October 22, 2022
 *********************************************************************/

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

void init(GLFWwindow* window) {}

void display(GLFWwindow* window, double currentTime) {
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    return;
}

int main(void) {

    // Check if the GLFW initialization is successful
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Create a new GLFWwindow pointer from the factory method
    // glfwCreateWindow()
    GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter 1 Simple Application", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Check if the GLEW initialization is successful
    // unresolved external symbol __imp_glewInit referenced in function main
    //if (glewInit() != GLEW_OK) {
    //    exit(EXIT_FAILURE);
    //}

    glfwSwapInterval(1);

    init(window);

    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
