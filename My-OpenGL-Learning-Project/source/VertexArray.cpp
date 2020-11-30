#include"VertexArray.h"

VertexArray::VertexArray(VertexBuffer vbo, BufferLayout layout)
{
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);

	std::vector<Elements> E = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < E.size(); i++)
	{
		glVertexAttribPointer(i, E[i].m_count, E[i].m_datatype, E[i].m_normalised, layout.GetStride(), (void*)(offset));
		glEnableVertexAttribArray(i);
		offset += E[i].m_count;
	}
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &ID);
}

void VertexArray::Bind()
{
	glBindVertexArray(ID);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}
