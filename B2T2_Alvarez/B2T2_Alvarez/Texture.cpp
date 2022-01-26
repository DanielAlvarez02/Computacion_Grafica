#include "Texture.h"
//Crea una textura nueva
Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
	//Se guarda el tipo de textura en la variable type
	type = texType;

	//Se crean el ancho w, alto h y numero de canales de color numColCh
	int w, h, numColCh;
	
	//Se invierte la imagen para que tenga sentido
	stbi_set_flip_vertically_on_load(true);

	//Se carga la imagen
	unsigned char* bytes = stbi_load(image, &w, &h, &numColCh, 0);

	//Se genera una textura
	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(texType, ID);

	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(texType, 0, GL_RGBA, w, h, 0, format, pixelType, bytes);
	glGenerateMipmap(texType);

	stbi_image_free(bytes);
	glBindTexture(texType, 0);
}

void Texture::texUnit(Shader shader, const char* uniform, GLuint uint)
{
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	shader.Activate();
	glUniform1i(texUni, uint);
}

void Texture::Bind(GLenum texNumber)
{
	glActiveTexture(texNumber);
	glBindTexture(type, ID);
}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}