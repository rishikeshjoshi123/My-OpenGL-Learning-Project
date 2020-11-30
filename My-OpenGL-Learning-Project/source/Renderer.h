#pragma once

#include<iostream>
#include<glew.h>
#define ASSERT(x) if(!(x)) __debugbreak();

//we will wrap every function with errlog ,ex: errlog(function name()). 
//It will break if error occurs , and will give us error log
#define errlog(func) GLClearError();\
                    func;\
                    ASSERT(GLLogCall(#func,__FILE__,__LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, const int line);
