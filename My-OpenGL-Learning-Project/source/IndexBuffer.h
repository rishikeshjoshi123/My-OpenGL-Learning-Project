#pragma once

class IndexBuffer
{
private:
	unsigned int m_IbufferID;
public:
	IndexBuffer(unsigned int count, unsigned int* data);
	~IndexBuffer();
	void Bind();
	void Unbind();
};