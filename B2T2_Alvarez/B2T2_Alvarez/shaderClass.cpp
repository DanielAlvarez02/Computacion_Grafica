#include "shaderClass.h"

//Obtiene los contenidos de un archivo de texto
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

// Construye un nuevo shader, tomando como entrada el código fuente de un vertex y un fragment shader
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	// Lee los shaders y los guarda como strings
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	// Convierte los string a arrays de caracteres
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Se crea el vertex shader y se compila su código
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Se crea el fragment shader y se compila su código
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Se crea el Shader program y se obtiene el ID
	ID = glCreateProgram();

	// Se agregan los vertex y fragment shaders al programa
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	// Se hace un link
	glLinkProgram(ID);

	// se eliminan los shaders que ya están en el programa
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


}

// Activa el shader
void Shader::Activate()
{
	glUseProgram(ID);
}

// Elimina el shader
void Shader::Delete()
{
	glDeleteProgram(ID);
}