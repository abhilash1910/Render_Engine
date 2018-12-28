#ifndef renderengine_h
#define renderengine_h
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

using namespace std;


namespace renderengine {


	class render_engine {

	protected:
		const char* vertex = "#version 330 core\n"
			"layout (location=0) in vec3 aPos;\n"
			"layout (location=1) in vec3 aColor;\n"
			"out vec3 color;\n"
			"void main()\n"
			"{\n"
			"gl_Position= vec4(aPos.x,aPos.y,aPos.z,1.0f);\n"
			"color= aColor;\n"
			"}\0";
		const char* fragment="#version 330 core\n"
			"in vec3 color;\n"
			"out vec4 frag;\n"
			"void main()\n"
			"{\n"
			"frag= vec4(color,1.0f);\n"
			"}\0";;


	public:
		

		inline unsigned int vertcompile(render_engine const &);
		inline unsigned int fragcompile(render_engine const &);
		inline unsigned int program(render_engine const &);



	};

	unsigned int render_engine::vertcompile(render_engine const &a)
	{
		const char* avertex = a.vertex;
		unsigned int vshad = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vshad, 1, &avertex, NULL);
		glCompileShader(vshad);
		int success;
		char infolog[512];
		glGetShaderiv(vshad,GL_COMPILE_STATUS,&success);
		if (!success)
		{

			
			glGetShaderInfoLog(vshad,512,NULL,infolog);
			std::cout << "Error in vertex shader" << std::endl;
			return -1;

		}


		return vshad;
	}

	unsigned int render_engine::fragcompile(render_engine const &b)
	{

		const char* afragment = b.fragment;
		unsigned int fshad = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fshad,1,&afragment,NULL);
		glCompileShader(fshad);
		int success;
		char infolog[512];
		glGetShaderiv(fshad,GL_COMPILE_STATUS,&success);
		if (!success)
		{
			
			glGetShaderInfoLog(fshad,512,NULL,infolog);
			std::cout << "Error in fragment shader" << std::endl;
			return -1;

		}

		return fshad;


	}

	unsigned int render_engine::program(render_engine const &a)
	{

		unsigned int program = glCreateProgram();
		unsigned int x = vertcompile(a);
		unsigned int y = fragcompile(a);
		glAttachShader(program,x);
		glAttachShader(program, y);
		glLinkProgram(program);
		int success;
		char infolog[512];
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			std::cout << "Error in program" << std::endl;
			glGetProgramInfoLog(program,512,NULL,infolog);
			return -1;

		}

		return program;






	}

	class buffer {

	
		
	public:


		inline void allocate_buffers(float size,const void* vertices,float size_index,const void* vert_index);
		






	};

	void buffer::allocate_buffers(float size,const void* vertices,float size_index,const void* vert_index)
	{
		unsigned int vao;
		unsigned int vbo;
		unsigned int ebo;

		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER,vbo);
		glBufferData(GL_ARRAY_BUFFER,size,vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,size_index,vert_index,GL_STATIC_DRAW);


		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6* sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3*sizeof(float)));
		glEnableVertexAttribArray(1);
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);



	}

	class windowgl:public buffer{

	public:
		GLFWwindow *window;
		//inline void open_window(int width, int height);
		inline void initgl();
		//inline void display(unsigned int program, unsigned int size, int width, int height);
		
  };



	void windowgl::initgl()
	{

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


	}

	
}































#endif