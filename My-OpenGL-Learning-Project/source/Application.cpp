#include<glew.h>
#include<glfw3.h>

#include"Shader.h"
#include"VertexBuffer.h"
#include"IndexBuffer.h"
#include"Renderer.h"
#include"VertexArray.h"
#include"BufferLayout.h"
#include"Texture.h"
#include"stb_image/stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
		//near
		 -0.5f, 0.5f, 0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f,   //top left
		 -0.5f,-0.5f, 0.5f ,  0.0f,0.0f,1.0f,  0.0f,0.0f,   //bottom left
		  0.5f,-0.5f, 0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		  0.5f,-0.5f, 0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		  0.5f, 0.5f, 0.5f ,  0.9f,0.4f,1.0f,  1.0f,1.0f,   //top right
		 -0.5f, 0.5f, 0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f,   //top left
		
		 //far
		  0.5f, 0.5f, -0.5f ,  1.0f, 0.0f, 0.0f,  0.0f,1.0f,   //top left
		  0.5f,-0.5f, -0.5f ,  0.0f, 0.0f, 1.0f,  0.0f,0.0f,   //bottom left
		 -0.5f,-0.5f, -0.5f ,  0.0f, 1.0f, 0.0f,  1.0f,0.0f,   //bottom right
		 -0.5f,-0.5f, -0.5f ,  0.0f, 1.0f, 0.0f,  1.0f,0.0f,   //bottom right
		 -0.5f, 0.5f, -0.5f ,  0.9f, 0.4f, 1.0f,  1.0f,1.0f,   //top right
		  0.5f, 0.5f, -0.5f ,  1.0f, 0.0f, 0.0f,  0.0f,1.0f,   //top left

		//right
		 0.5f, 0.5f,  0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f,   //top left
		 0.5f,-0.5f,  0.5f ,  0.0f,0.0f,1.0f,  0.0f,0.0f,   //bottom left
		 0.5f,-0.5f, -0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		 0.5f,-0.5f, -0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		 0.5f, 0.5f, -0.5f ,  0.9f,0.4f,1.0f,  1.0f,1.0f,   //top right
		 0.5f, 0.5f,  0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f,   //top left

		 //left
		 -0.5f, 0.5f,  0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f,   //top left
		 -0.5f,-0.5f,  0.5f ,  0.0f,0.0f,1.0f,  0.0f,0.0f,   //bottom left
		 -0.5f,-0.5f, -0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		 -0.5f,-0.5f, -0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		 -0.5f, 0.5f, -0.5f ,  0.9f,0.4f,1.0f,  1.0f,1.0f,   //top right
		 -0.5f, 0.5f,  0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f,   //top left

		 //top
		 -0.5f, 0.5f, -0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f,   //top left
		 -0.5f, 0.5f,  0.5f ,  0.0f,0.0f,1.0f,  0.0f,0.0f,   //bottom left
		  0.5f, 0.5f,  0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		  0.5f, 0.5f,  0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		  0.5f, 0.5f, -0.5f ,  0.9f,0.4f,1.0f,  1.0f,1.0f,   //top right
		 -0.5f, 0.5f, -0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f,   //top left

		 //bottom
		 -0.5f, -0.5f, -0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f,   //top left
		 -0.5f, -0.5f,  0.5f ,  0.0f,0.0f,1.0f,  0.0f,0.0f,   //bottom left
		  0.5f, -0.5f,  0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		  0.5f, -0.5f,  0.5f ,  0.0f,1.0f,0.0f,  1.0f,0.0f,   //bottom right
		  0.5f, -0.5f, -0.5f ,  0.9f,0.4f,1.0f,  1.0f,1.0f,   //top right
		 -0.5f, -0.5f, -0.5f ,  1.0f,0.0f,0.0f,  0.0f,1.0f    //top left
	};
	unsigned int indices[] =
	{ 
	  1,3,0,
	  1,3,2
	};

    //+++++++++++++++++++++++++++++++++++++++//
	VertexBuffer vbo(sizeof(vertices), vertices);
	BufferLayout Layout;
	Layout.PushLayout(3, GL_FLOAT); //for drawing figure
	Layout.PushLayout(3, GL_FLOAT); //for color
	Layout.PushLayout(2, GL_FLOAT);// for texture
	
	
	VertexArray vao;
	vao.AddBufferLayout(vbo, Layout);
	vao.Unbind();
	
	IndexBuffer ibo(6, indices);
	ibo.Unbind();
	//+++++++++++++++++++++++++++++++++++++++++++++++++//
	
	//+++++++++++++TEXTURES++++++++++++
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	ShaderProgram.SetUniform1i("TS2", 1);
	Texture texture("source/images/happy.png");
	texture.Bind(1);

   // +++++++++++++++++++++++++++++++++++++
	glEnable(GL_DEPTH_TEST);

	//todo: see how to properly use this perspective function
	//glm::mat4 proj = glm::perspective(glm::radians(100.0f), (float)width / (float)height, 1.0f, -1.0f);
	
	
	glm::vec3 translate_to[] = 
	{
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(-1.0f,0.0f,0.0f),
		glm::vec3(-1.0f,-1.0f,0.0f),
		glm::vec3(1.0f,-1.0f,0.0f),
		glm::vec3(1.0f,1.0f,0.0f)
	};

	Renderer renderer;
	while (!glfwWindowShouldClose(window))
	{
		renderer.Clear();
		for (int i = 0; i < 5; ++i)
		{
			glm::mat4 shift = glm::translate(glm::mat4(1.0f), translate_to[i]);
			glm::mat4 model2 = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.5f));
			glm::mat4 proj2 = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, 1.0f, -1.0f);
			glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians((float)glfwGetTime() * (10*i+5)), glm::vec3(0.5f, 1.0f, 0.5f));
			ShaderProgram.SetUniform_mat4("u_MVP", proj2 * shift * model * model2);

			renderer.Draw(vao, ShaderProgram);
		}
		PressESCtoClose(window);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}