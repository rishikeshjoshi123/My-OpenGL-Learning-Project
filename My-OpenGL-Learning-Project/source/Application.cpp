
#include"Shader.h"
#include"VertexBuffer.h"
#include"IndexBuffer.h"

const unsigned int width = 800;
const unsigned int height = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}
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

	Shaders Source = GetShaders();
	unsigned int program = CreateShaderProgram(Source.vs, Source.fs);
	
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

	unsigned int  vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	VertexBuffer vbo(20 * sizeof(float), vertices);
	//for vertex draw
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(0));
	glEnableVertexAttribArray(0);
	//for color filling
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);

	IndexBuffer ibo(6, indices);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window))
	{
		PressESCtoClose(window);
		glClearColor(0.4f, 0.4f, 0.5f,1.0f );
		glClear(GL_COLOR_BUFFER_BIT);

		
		glUseProgram(program);
	    glBindVertexArray(vao);
		ibo.Bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
	   
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}