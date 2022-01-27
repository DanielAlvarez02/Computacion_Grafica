#include"EBO.h"

//Crea un nuevo EBO tomando un array de vertices y un tamaño
EBO::EBO(GLuint* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

//Selecciona el EBO
void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

//Deselecciona el EBO
void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//Elimina el EBO
void EBO::Delete()
{
	glDeleteBuffers(1, &ID);
}