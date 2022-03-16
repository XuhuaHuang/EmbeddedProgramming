/*****************************************************************//**
 * \file   3_write_a_shader.cpp
 * \brief  contains code to write a shader in OpenGL
 *
 * \author Xuhua Huang
 * \date   June 2021
 *********************************************************************/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

static unsigned int compileShader(unsigned int type, const std::string source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str(); // src = &source[0];
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	/* Error handling */
	int result = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) // shader does not compile successfully
	{
		using namespace std;

		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca((int)length * sizeof(char));
		// char message[50] = {};
		glGetShaderInfoLog(id, length, &length, message);

		/* Print error message in the console */
		cout << "\n___________________________________________________" << endl
			 << "Failed to compile shader!" << endl
			 << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment") << " compilation failed" << endl
			 << message
			 << "\n___________________________________________________" << endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

static unsigned int createShader(const std::string& vertexShader, const std::string fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	/* Delete both shaders after validating */
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello OpenGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// X.H. added the following line to initialize glew
	glewInit();
	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

	// create a float array to contain information to draw a triangle
	float position[6] = {
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};

	// generate a buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), position, GL_STATIC_DRAW);

	/**
	 * glVertexAttribPointer(index, size, type, normalized, stride, const void *pointer);
	 * index start from INDEX 0.
	 * GROUP 2 attributes together as one vertex
	 * data TYPE of float
	 * whether or not to normalize them TRUE/FALSE: FL_FALSE
	 * stride - total bytes of each vertex / offset to jump to next vertex attribute
	 * pointer - the offset of the first component in the first vertex
	 *
	 * stride, pointer are both 0 if data are strictly packed aand no offset
	 * UPCOMING: a struct to represent each vertex
	 */
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0); // call this function to show the shape
	// note: this code is going to run if and only if the GPU supports default dhader without manually creating one in the code

	std::string vertexShader = 
		"#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;"
		"void main()\n"
		"{\n"
		"	gl_Position = position;\n"
		"}\n";

	std::string fragmentShader =
		"#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;"
		"void main()\n"
		"{\n"
		"	color = vec4(1.0, 0.0, 0.0, 1.0);\n" // red triangle
		"}\n";

	unsigned int shader = createShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	glEnd();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Commented out in the second increment of the file
		 * Replaced by an array named 'position' of type float
		// X.H. added the following line to draw a triangle with vertex specified
		// drawing a triangle with legacy opengl
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f); // 'f' indicates float number
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		*/

		// automatically select array buffer
		// currently binded, i.e. selected
		glDrawArrays(GL_TRIANGLES, 0, 5);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}