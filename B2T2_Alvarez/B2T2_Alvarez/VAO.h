#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include"VBO.h"

#include<glad/glad.h>

class VAO
{
public:
	GLuint ID;
	VAO();

	void LinkVBO(VBO VBO, GLuint layout, GLuint numOfData, GLfloat size, void* offset);
	void Bind();
	void Unbind();
	void Delete();
};

#endif