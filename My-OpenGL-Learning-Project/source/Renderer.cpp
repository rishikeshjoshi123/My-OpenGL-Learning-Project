#include"Renderer.h"


void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, const int line)
{
	if (GLenum error = glGetError())
	{
		std::cout << "Error Details :\n";
		std::cout << "Error code :" << error << "\n";
		std::cout << "Function name :" << function << "\n";
		std::cout << "File name :" << file << "\n";
		std::cout << "Line no :" << line << "\n";
		return false;
	}
	return true;
}

void PressESCtoClose(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void Renderer::Draw(const VertexArray& vao, const  Shader& ShaderProgram) const
{
	ShaderProgram.Bind();
	vao.Bind();
	
	glDrawArrays(GL_TRIANGLES, 0, vao.GetBufferSize() / vao.GetStrideCount());

}

void Renderer::Draw(const VertexArray& vao, const  Shader& ShaderProgram, const IndexBuffer& ibo) const
{
	ShaderProgram.Bind();
	vao.Bind();
	ibo.Bind();
	glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, NULL);

}

void Renderer::Clear() const
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
