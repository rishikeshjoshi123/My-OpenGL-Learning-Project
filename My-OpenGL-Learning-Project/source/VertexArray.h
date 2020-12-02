#pragma once
#include"VertexBuffer.h"

class BufferLayout;

class VertexArray
{
private:
	unsigned int ID;
public:
	VertexArray();
	void AddBufferLayout( VertexBuffer& vbo, BufferLayout& layout);
	~VertexArray();
	void Bind()const ;
	void Unbind()const ;
};