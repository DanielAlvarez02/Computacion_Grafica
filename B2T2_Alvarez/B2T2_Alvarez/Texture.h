#ifndef Texture_CLASS_H
#define Texture_CLASS_H

#include<glad/glad.h>
#include<stb/stb_image.h>

#include"shaderClass.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixeltype);

	void texUnit(Shader shader, const char* uniform, GLuint uint);
	void Bind(GLenum texNumber);
	void Unbind();
	void Delete();
};

#endif
