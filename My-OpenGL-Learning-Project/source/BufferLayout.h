#pragma once

#include"Renderer.h"

#include<vector>
#include<glew.h>

struct Elements
{
	unsigned int m_count;
	unsigned int m_datatype;
	bool m_normalised;
};
class BufferLayout
{
private:
	std::vector<Elements> E;
	unsigned int m_stride;
public:
	BufferLayout();

	//This function will take count(no of vertices) and data type of vertex
	//to initialise vertexAttribPointer() funciton to specify GPU
	//how to use the given buffer data
	void PushLayout(unsigned int count, unsigned int type);

	std::vector<Elements> GetElements();
	unsigned int GetStride();
};