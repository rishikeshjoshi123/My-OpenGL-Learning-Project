#pragma once
#include<glew.h>
#include<glfw3.h>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<unordered_map>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct ShaderSource
{
	std::string vs;
	std::string fs;
};


class Shader
{
private:
	unsigned int m_ID;
	std::string m_filepath;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;
	void SetUniform_mat4(const std::string &name, const glm::mat4& matrix);
	void SetUniform4f(std::string  name, float v1, float v2, float v3, float v4) const;
	void SetUniform1i(std::string name, int value);
};
ShaderSource GetShaders(std::string path);
unsigned int CreateShaderProgram(std::string, std::string);
unsigned int CompileShader(unsigned int, std::string&);
