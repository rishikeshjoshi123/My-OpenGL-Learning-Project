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