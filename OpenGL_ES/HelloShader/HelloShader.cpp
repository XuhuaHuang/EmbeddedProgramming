/*****************************************************************//**
 * \file   HelloShader.cpp
 * \brief  Introduction to OpenGL shader.
 * 
 * \author Xuhua Huang
 * \date   October 23, 2022
 *********************************************************************/

#define GLEW_STATIC

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

constexpr int numVAOs = 1;

GLuint renderingProgram;
GLuint vao[numVAOs];

GLuint createShaderProgram(void) {
    /* Vertex Shader Source with GLSL syntax */
    const char* vshaderSource = \
        "#version 430 \n"
        "void main(void) \n"
        "{gl_Position = vec4(0.0, 0.0, 0.0, 1.0);}";

    /* Fragement Shader Source with GLSL syntax */
    const char* fshaderSource = \
        "#version 430 \n"
        "out vec4 color; \n"
        "void main(void) \n"
        //"{color = vec4(0.0, 0.0, 1.0, 1.0);}";
        "{if (gl_FragCoord.x < 200) color = vec4(1.0, 0.0, 0.0, 1.0); else color = vec4(0.0, 0.0, 1.0, 1.0);}";

    /**
     * 1. Create preliminary shaders.
     * 2. Attach shader source from const char* variables.
     * 3. Compile shders.
     * \return 
     */
    GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vShader, 1, &vshaderSource, NULL);
    glShaderSource(fShader, 1, &fshaderSource, NULL);

    glCompileShader(vShader);
    glCompileShader(fShader);

    GLuint vfProgram = glCreateProgram();
    glAttachShader(vfProgram, vShader);
    glAttachShader(vfProgram, fShader);
    glLinkProgram(vfProgram);

    return vfProgram;
}

void init(GLFWwindow* window) {
    renderingProgram = createShaderProgram();
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);

    return;
}

void display(GLFWwindow* window, double currentTime) {
    glUseProgram(renderingProgram);
    glPointSize(30.0f);
    glDrawArrays(GL_POINTS, 0, 1);

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
    GLFWwindow* window = glfwCreateWindow(600, 600, "Hello Shader", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Check if the GLEW initialization is successful
    // unresolved external symbol __imp_glewInit referenced in function main
    if (glewInit() != GLEW_OK) {
        exit(EXIT_FAILURE);
    }

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
