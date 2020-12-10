#pragma once
#include"VertexBuffer.h"

class BufferLayout;

class VertexArray
{
private:
	unsigned int ID;
	unsigned int m_stridecount;
	unsigned int m_buffersize;
public:
	VertexArray();
	void AddBufferLayout( VertexBuffer& vbo, BufferLayout& layout);
	~VertexArray();
	void Bind()const ;
	void Unbind()const ;
	unsigned int GetStrideCount() const;
	unsigned int GetBufferSize() const;
};