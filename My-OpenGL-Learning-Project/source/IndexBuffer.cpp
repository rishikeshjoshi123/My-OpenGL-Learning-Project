#include"IndexBuffer.h"
#include"Renderer.h"

IndexBuffer::IndexBuffer(unsigned int count, unsigned int* data)
{
	glGenBuffers(1, &m_IbufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IbufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * (sizeof(unsigned int)), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_IbufferID);
}

void IndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IbufferID);
}

void IndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
