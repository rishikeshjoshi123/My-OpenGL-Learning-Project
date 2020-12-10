#include"Texture.h"
#include<glew.h>

Texture::Texture(const std::string& Filepath)
	:m_ID(0), m_filepath(Filepath),m_LocalBuffer(nullptr),m_width(0),m_height(0),m_BPP(0)
{
	glGenTextures(1, &m_ID);
	glBindTexture(GL_TEXTURE_2D, m_ID);

	stbi_set_flip_vertically_on_load(true);
	//Loading image data and storing in m_LocalBuffer variable
	m_LocalBuffer = stbi_load(Filepath.c_str(), &m_width, &m_height, &m_BPP, 4);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (m_LocalBuffer)
		stbi_image_free(m_LocalBuffer);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_ID);
}

void Texture::Bind(unsigned int slot=0) const
{
	glActiveTexture(slot);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

inline unsigned int Texture::GetWidth() const
{
	return m_width;
}

inline unsigned int Texture::GetHeight() const
{
	return m_height;
}
