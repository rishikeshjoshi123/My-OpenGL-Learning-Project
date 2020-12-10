#include"VertexArray.h"
#include"BufferLayout.h"

VertexArray::VertexArray()
	:m_stridecount(0)
{
	glGenVertexArrays(1, &ID);
}

void VertexArray::AddBufferLayout(VertexBuffer &vbo, BufferLayout &layout)
{
	m_stridecount = layout.GetStrideCount();
	m_buffersize = vbo.GetBufferSize();
	Bind();

	const std::vector<Elements>& e = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < e.size(); i++)
	{
		glVertexAttribPointer(i, e[i].m_count, e[i].m_datatype, e[i].m_normalised, layout.GetStride(), (void*)(offset));
		glEnableVertexAttribArray(i);
		offset += e[i].m_count*GetSize(e[i].m_datatype);
	}
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &ID);
}

void VertexArray::Bind() const
{
	glBindVertexArray(ID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

unsigned int VertexArray::GetStrideCount() const
{
	return m_stridecount;
}

unsigned int VertexArray::GetBufferSize() const
{
	return m_buffersize;
}

