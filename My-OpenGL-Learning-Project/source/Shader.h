#pragma once
#include<glew.h>
#include<glfw3.h>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

struct Shaders
{
    std::string vs;
    std::string fs;
};

void PressESCtoClose(GLFWwindow* window);
Shaders GetShaders();
unsigned int CreateShaderProgram(std::string, std::string);
unsigned int CompileShader(unsigned int, std::string&);
