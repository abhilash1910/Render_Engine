#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include<cmath>
#include "stb_image.h"
#include "C:/Users/User/source/repos/engine_math/engine_math/matrix.h"
#include "C:/Users/User/source/repos/engine_math/engine_math/degree_radian.h"
#include<GL/GLU.h>
#include "render_engine.h"
using namespace std;

using namespace renderengine;

int main(int argc, char** argv) {
	

	GLFWwindow* window;
	if (!glfwInit())
	{
		return -1;
	}
	window = glfwCreateWindow(1400, 1400, "Render_engine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	 
	glfwMakeContextCurrent(window);

	if (glewInit() == GLEW_OK)
	{
		cout << "Yeah" << endl;
	}
	


	

	render_engine ren;
unsigned int vertexsh=ren.vertcompile(ren);
unsigned int fragsh = ren.fragcompile(ren);
unsigned int prog = ren.program(ren);



	
	float vertices[] = {
		0.0f,0.0f,0.0f, 1.0f,0.0f,1.0f,
		0.5f, 0.0f, 0.0f,1.0f,0.0f,0.0f,  
		0.0f, 0.5f, 0.0f, 0.0f,0.5f,1.0f, 
		 0.0f,  -0.5f, 0.0f,1.0f,1.0f,0.0f,
		 -0.5f,0.0f,0.0f,0.0f,1.0f,1.0f, 

		 
		 -1.0f,0.0f,0.0f,1.0f,0.0f,1.0f,
		-0.5f, 0.0f, 0.0f,1.0f,0.0f,0.0f,
		-1.0f, 0.5f, 0.0f, 0.0f,0.5f,1.0f,
		 -1.0f,-0.5f, 0.0f,1.0f,1.0f,0.0f,
		 -1.5f,0.0f,0.0f,0.0f,1.0f,1.0f,

		 1.0f,0.0f,0.0f,1.0f,0.0f,1.0f,
		1.5f, 0.0f, 0.0f,1.0f,0.0f,0.0f,
		1.0f, 0.5f, 0.0f, 0.0f,0.5f,1.0f,
		 1.0f,  -0.5f, 0.0f,1.0f,1.0f,0.0f,
		 0.5f,0.0f,0.0f,0.0f,1.0f,1.0f,

		 0.0f,0.5f,0.0f,1.0f,0.0f,1.0f,
		0.0f, 1.0f, 0.0f,1.0f,0.0f,0.0f,
		0.0f, 1.5f, 0.0f, 0.0f,0.5f,1.0f,
		 -0.5f,  1.0f, 0.0f,1.0f,1.0f,0.0f,
		 0.5f,1.0f,0.0f,0.0f,1.0f,1.0f,

		  0.0f,-0.5f,0.0f,1.0f,0.0f,1.0f,
		0.0f, -1.0f, 0.0f,1.0f,0.0f,0.0f,
		0.0f, -1.5f, 0.0f, 0.0f,0.5f,1.0f,
		 -0.5f, -1.0f, 0.0f,1.0f,1.0f,0.0f,
		 0.5f,-1.0f,0.0f,0.0f,1.0f,1.0f,

		 -1.0f,0.5f,0.0f,1.0f,0.0f,1.0f,
		-1.0f, 1.0f, 0.0f,1.0f,0.0f,0.0f,
		-1.0f, 1.5f, 0.0f, 0.0f,0.5f,1.0f,
		 -1.5f,  1.0f, 0.0f,1.0f,1.0f,0.0f,
		- 0.5f,1.0f,0.0f,1.0f,1.0f,0.0f,

		-1.0f,-0.5f,0.0f,1.0f,0.0f,1.0f,
		-1.0f, -1.0f, 0.0f,1.0f,0.0f,0.0f,
		-1.0f, -1.5f, 0.0f, 0.0f,0.5f,1.0f,
		 -1.5f,  -1.0f, 0.0f,1.0f,1.0f,0.0f,
		-0.5f,-1.0f,0.0f,1.0f,1.0f,0.0f,

		1.0f,-0.5f,0.0f,1.0f,0.0f,1.0f,
		1.0f, -1.0f, 0.0f,1.0f,0.0f,0.0f,
		1.0f, -1.5f, 0.0f, 0.0f,0.5f,1.0f,
		 1.5f,  -1.0f, 0.0f,1.0f,1.0f,0.0f,
		0.5f,-1.0f,0.0f,0.0f,1.0f,1.0f,

		1.0f,0.5f,0.0f,1.0f,0.0f,1.0f,
		1.0f, 1.0f, 0.0f,1.0f,0.0f,0.0f,
		1.0f, 1.5f, 0.0f, 0.0f,0.5f,1.0f,
		 1.5f,  1.0f, 0.0f,1.0f,1.0f,0.0f,
		0.5f,1.0f,0.0f,0.0f,1.0f,1.0f,


	};

	unsigned int indices[] = {
		0,1,2,
		0,1,3,
		0,3,4,
		0,2,4,

        4,5,7,
		4,5,8,
		5,8,9,
		5,7,9,

		1,10,12,
		1,10,13,
		10,11,12,
		10,11,13,

		2,16,19,
		2,16,18,
		16,17,18,
		16,17,19,

		3,21,23,
		3,21,24,
		21,22,23,
		21,22,24,
		
		7,26,28,
		7,26,29,
		26,27,28,
		26,27,29,
		

		8,31,34,
		8,31,33,
		31,32,33,
		31,32,34,

		13,36,39,
		13,36,38,
		36,37,38,
		36,37,39,

		12,41,44,
		12,41,43,
		41,42,43,
		41,42,44


	};
	
	windowgl gl;
	
	
	unsigned int size = sizeof(vertices);
	const void* data;
	data = vertices;
	unsigned int size_index = sizeof(indices);
	const void* data_index;
	data_index = indices;

	buffer buf;
	buf.allocate_buffers(size,data,size_index,data_index);
	

	gl.initgl();
	// Our own OpenGL initialization
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear the color buffer with current clearing color
		glUseProgram(prog);
		// render the triangle
		//glTranslatef(0.5f, 0.4f, 0.0f);
		glDrawElements(GL_TRIANGLES,size_index, GL_UNSIGNED_INT, 0);
		glDrawElements(GL_TRIANGLES, size_index, GL_UNSIGNED_INT, 0);


		glFlush();



		glfwSwapBuffers(window);
		glfwPollEvents();


	}

		glfwTerminate();
		return 0;
}
