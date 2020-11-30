#pragma once
#include"VertexBuffer.h"
#include"BufferLayout.h"

class VertexArray
{
private:
	unsigned int ID;
public:
	VertexArray(VertexBuffer vbo, BufferLayout layout);
	~VertexArray();
	void Bind();
	void Unbind();
};