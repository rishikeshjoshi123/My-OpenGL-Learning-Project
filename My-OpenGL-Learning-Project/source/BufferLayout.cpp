#include"BufferLayout.h"

BufferLayout::BufferLayout()
	:m_stride(0) { }

void BufferLayout:: PushLayout(unsigned int count, unsigned int type)
{
	m_stride += count;
	switch (type) 
	{
	case GL_FLOAT:
		E.push_back({ count, GL_FLOAT,false });
		break;

	case GL_UNSIGNED_INT:
		E.push_back({ count, GL_UNSIGNED_INT,false });
		break;

	case GL_UNSIGNED_BYTE:
		E.push_back({ count, GL_UNSIGNED_BYTE,true });
		break;
	}
}

std::vector<Elements> BufferLayout::GetElements()
{
	return  E;
}

unsigned int BufferLayout::GetStride()
{
	switch (E.back().m_datatype)
	{
	case GL_FLOAT:
		return m_stride * sizeof(GL_FLOAT);

	case GL_UNSIGNED_INT:
		return m_stride * sizeof(GL_UNSIGNED_INT);

	case GL_UNSIGNED_BYTE:
		return m_stride * sizeof(GL_UNSIGNED_BYTE);
	//default:
		//ASSERT(false);
		//return 0;
	}
}


