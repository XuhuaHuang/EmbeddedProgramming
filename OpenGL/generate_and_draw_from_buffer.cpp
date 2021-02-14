/*****************************************************************//**
 * \file   generate_and_draw_from_buffer.cpp
 * \brief  Generate a buffer, bind it into OpenGL's state machine,
 *		   and draw from most recent selected buffer
 * 
 * \author Xuhua HUANG
 * \date   February 2021
 *********************************************************************/

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
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
	 * group 2 attributes together as one vertex
	 * data TYPE of float
	 * whether or not to normalize them TRUE/FALSE
	 * stride - total bytes of each vertex / offset to jump to next vertex attribute
	 * pointer - the offset of the first component in the first vertex
	 * 
	 * stride, pointer are both 0 if data are strictly packed aand no offset
	 */
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0); // call this function to show the shape
	glEnd();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* commented out in the second increment of the file
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

	glfwTerminate();
	return 0;
}
