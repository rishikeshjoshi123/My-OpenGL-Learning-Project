#pragma once

#include<glew.h>
#include<glfw3.h>
#include<iostream>
#include<string>

#include"VertexArray.h"
#include"IndexBuffer.h"
#include"Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak();

//we will wrap every function with errlog ,ex: errlog(function name()). 
//It will break if error occurs , and will give us error log
#define errlog(func) GLClearError();\
                    func;\
                    ASSERT(GLLogCall(#func,__FILE__,__LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, const int line);
void PressESCtoClose(GLFWwindow * window);

class Renderer
{
public:
    void Draw(const VertexArray& vao, const  Shader& ShaderProgram) const;
    void Draw(const VertexArray& vao, const Shader &shader,const IndexBuffer& ibo) const;
    void Clear() const;
};