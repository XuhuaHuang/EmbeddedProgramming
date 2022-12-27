/*****************************************************************//**
 * \file   DebugUtility.hpp
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   November 02, 2022
 *********************************************************************/

#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

namespace learn_opengl::debug_util {

    void printShaderLog(GLuint shader) {
        int len = 0;
        int chWrittn = 0;
        char* log;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
        if (len > 0) {
            log = (char*)malloc(len);
            glGetShaderInfoLog(shader, len, &chWrittn, log);
            std::cout << "Shader Info Log: " << log << "\n";
            free(log);
        }
    }

    void printProgramLog(int prog) {
        int len = 0;
        int chWrittn = 0;
        char* log;
        glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
        if (len > 0) {
            log = (char*)malloc(len);
            glGetProgramInfoLog(prog, len, &chWrittn, log);
            std::cout << "Program Info Log: " << log << "\n";
            free(log);
        }
    }

    bool checkOpenGLError() {
        bool foundError = false;
        // TODO: refactor the following while loop to a do-while loop
        int glErr = glGetError();
        while (glErr != GL_NO_ERROR) {
            std::cout << "glError: " << glErr << "\n";
            foundError = true;
            glErr = glGetError();
        }
        return foundError;
    }
}
