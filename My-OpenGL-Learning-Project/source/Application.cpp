#include<glew.h>
#include<glfw3.h>

#include"Shader.h"
#include"VertexBuffer.h"
#include"IndexBuffer.h"
#include"Renderer.h"
#include"VertexArray.h"
#include"BufferLayout.h"

const unsigned int width = 800;
const unsigned int height = 600;

int main()
{
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(width, height, "Display box", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Can't create window " << "\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glewInit();

	
	std::string path2 = "Shader/Source.shader";
	Shader ShaderProgram(path2);


	float vertices[] =
	{
		//pos          //color
		 -0.5,0.5 , 1.0f,0.0f,0.0f, 
		 -0.5,-0.5, 0.0f,0.0f,1.0f, //1
		  0.5,-0.5, 0.0f,1.0f,0.0f,
		  0.5,0.5 , 0.9f,0.4f,1.0f  //3
	};
	unsigned int indices[] =
	{ 1,3,0,
	  1,3,2
	};

//+++++++++++++++++++++++++++++++++++++++//
	VertexBuffer vbo(sizeof(vertices), vertices);
	BufferLayout Layout;
	Layout.PushLayout(2, GL_FLOAT); //for drawing figure
	Layout.PushLayout(3, GL_FLOAT);// for colouring
	
	VertexArray vao;
	vao.AddBufferLayout(vbo, Layout);
	vao.Unbind();
	
	IndexBuffer ibo(6, indices);
	ibo.Unbind();
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window))
	{
		PressESCtoClose(window);
		glClearColor(0.9f, 0.4f, 0.5f,1.0f );
		glClear(GL_COLOR_BUFFER_BIT);

		
		ShaderProgram.Bind();
		
		vao.Bind();
		ibo.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
	   
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}