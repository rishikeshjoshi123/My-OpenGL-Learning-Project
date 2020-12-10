#pragma once
#include<string>
#include<glew.h>
#include"vendor/stb_image/stb_image.h"
class Texture
{
private:
	unsigned int m_ID;
	std::string m_filepath;
	unsigned char* m_LocalBuffer; //stored data from image will be in this in bytes format !
	int m_width, m_height, m_BPP;
public:
	Texture(const std::string& Filepath);
	~Texture();

	void Bind(unsigned int slot ) const;
	void Unbind() const;

	inline unsigned int GetWidth() const ;
	inline unsigned int GetHeight() const;

};