#pragma once

class IndexBuffer
{
private:
	unsigned int m_IbufferID;
	unsigned int m_count;
public:
	IndexBuffer(unsigned int count, unsigned int* data);
	~IndexBuffer();
	void Bind() const;
	void Unbind() const;
	unsigned int GetCount() const;
};