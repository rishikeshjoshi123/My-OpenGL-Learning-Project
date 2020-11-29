#pragma once

class VertexBuffer
{
private:
	unsigned int m_bufferID;
public:
	VertexBuffer(unsigned int size, void * data);
	~VertexBuffer();
	void Bind();
	void Unbind();
};