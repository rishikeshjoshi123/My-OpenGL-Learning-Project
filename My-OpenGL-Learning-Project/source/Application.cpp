
#include"Shader.h"

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
		-1.0f,-0.5f,  1.0f,0.0f,0.0f,   0.0f,-0.5f,   0.0f,1.0f,0.0f,
		0.0f,-0.5f,   0.0f,0.0f,1.0f,   1.0f,-0.5f,	  0.0f,0.0f,1.0f,
		-0.5f,0.5f,   0.0f,1.0f,0.0f,   0.5f ,0.5f,   1.0f,0.0f,0.0f,
	};
	unsigned int VBO[2], VAO[2];
	glGenVertexArrays(1, &VAO[1]);
	glBindVertexArray(VAO[1]);

	glGenBuffers(1, &VBO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, 30 * sizeof(float), vertices, GL_STATIC_DRAW);
	//for vertex draw
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(5*sizeof (float)));
	glEnableVertexAttribArray(0);
	//for color filling
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);


	glGenVertexArrays(1, &VAO[0]);
	glBindVertexArray(VAO[0]);
	glGenBuffers(1, &VBO[0]);
	glBindBuffer(GL_ARRAY_BUFFER,VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, 30 * sizeof(float), vertices, GL_STATIC_DRAW);
	//for vertex draw
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 10 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);
	//for color fill
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(2*sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);

	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!glfwWindowShouldClose(window))
	{
		PressESCtoClose(window);
		glClearColor(0.4f, 0.4f, 0.5f,1.0f );
		glClear(GL_COLOR_BUFFER_BIT);

		
		glUseProgram(program);
	    glBindVertexArray(VAO[0]);
	    glDrawArrays(GL_TRIANGLES, 0, 3);
		
		//glBindVertexArray(VAO[1]);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}