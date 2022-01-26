#include"VAO.h"

//Crea un VAO
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

//Vincula un VBO on un VAO
void VAO::LinkVBO(VBO VBO, GLuint layout, GLuint numOfData, GLfloat size, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numOfData, GL_FLOAT, GL_FALSE, size, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

//Selecciona el VAO
void VAO::Bind()
{
	glBindVertexArray(ID);
}

//Deselecciona el VAO
void VAO::Unbind()
{
	glBindVertexArray(0);
}

//Elimina el VAO
void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);
}

