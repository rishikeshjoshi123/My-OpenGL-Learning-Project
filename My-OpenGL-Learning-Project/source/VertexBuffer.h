#pragma once

class VertexBuffer
{
private:
	unsigned int m_bufferID;
	unsigned int m_size;
public:
	VertexBuffer(unsigned int size, void * data);
	~VertexBuffer();
	void Bind();
	void Unbind();
	unsigned int GetBufferSize() const;
};