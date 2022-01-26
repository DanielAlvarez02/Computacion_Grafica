#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include <iostream>
#include <chrono>
#include <ctime> 
#include <cmath>

#include"shaderClass.h"
#include"VBO.h"
#include"VAO.h"
#include"EBO.h"
#include"Texture.h"

// coordenadas de un triángulo equilatero
GLfloat vertices[] =
{
	-0.9f, 0.0f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.05f, 0.5f,	0.0f,//A 0
	-0.7f, -0.2f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.15f, 0.4f,	0.0f,//C 2
	-0.7f, 0.2f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.15f, 0.6f,	0.0f,//B 1
	-0.7f, 0.2f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.15f, 0.6f,	0.0f,//B 1
	-0.7f, -0.2f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.15f, 0.4f,	0.0f,//C 2
	-0.5f, 0.0f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.25f, 0.5f,	0.0f,//D 3
	-0.6f, -0.1f, 0.0f,		255.0f / 255.0f, 153.0f / 255.0f, 51.0f / 255.0f,		0.2f, 0.45f,	0.0f,//E 4
	-0.4f, -0.3f, 0.0f,		255.0f / 255.0f, 153.0f / 255.0f, 51.0f / 255.0f,		0.3f, 0.35f,	0.0f,//G 6
	-0.2f, -0.1f, 0.0f,		255.0f / 255.0f, 153.0f / 255.0f, 51.0f / 255.0f,		0.4f, 0.45f,	0.0f,//F 5
	-0.4f, -0.3f, 0.0f,		51.0f / 255.0f, 153.0f / 255.0f, 255.0f / 255.0f,		0.3f, 0.35f,	0.0f,//G 6
	0.0f, -0.3f, 0.0f,		51.0f / 255.0f, 153.0f / 255.0f, 255.0f / 255.0f,		0.5f, 0.35f,	0.0f,//H 7
	-0.2f, -0.1f, 0.0f,		51.0f / 255.0f, 153.0f / 255.0f, 255.0f / 255.0f,		0.4f, 0.45f,	0.0f,//F 5
	-0.2f, -0.1f, 0.0f,		255.0f / 255.0f, 204.0f / 255.0f, 0.0f / 255.0f,		0.4f, 0.45f,	0.0f,//F 5
	0.2f, -0.5f, 0.0f,		255.0f / 255.0f, 204.0f / 255.0f, 0.0f / 255.0f,		0.6f, 0.25f,	0.0f,//J 9
	0.2f, 0.3f, 0.0f,		255.0f / 255.0f, 204.0f / 255.0f, 0.0f / 255.0f,		0.6f, 0.65f,	0.0f,//I 8
	0.2f, 0.3f, 0.0f,		51.0f / 255.0f, 204.0f / 255.0f, 102.0f / 255.0f,		0.6f, 0.65f,	1.0f,//I 8
	0.2f, -0.5f, 0.0f,		51.0f / 255.0f, 204.0f / 255.0f, 102.0f / 255.0f,		0.6f, 0.25f,	1.0f,//J 9
	0.6f, -0.1f, 0.0f,		51.0f / 255.0f, 204.0f / 255.0f, 102.0f / 255.0f,		0.8f, 0.45f,	1.0f,//K 10
	0.2f, 0.3f, 0.0f,		102.0f / 255.0f, 102.0f / 255.0f, 204.0f / 255.0f,		0.6f, 0.65f,	1.0f,//I 8
	0.6f, 0.3f, 0.0f,		102.0f / 255.0f, 102.0f / 255.0f, 204.0f / 255.0f,		0.8f, 0.65f,	1.0f,//M 12
	0.4f, 0.5f, 0.0f,		102.0f / 255.0f, 102.0f / 255.0f, 204.0f / 255.0f,		0.7f, 0.75f,	1.0f,//L 11
	0.6f, 0.3f, 0.0f,		102.0f / 255.0f, 102.0f / 255.0f, 204.0f / 255.0f,		0.8f, 0.65f,	1.0f,//M 12
	0.8f, 0.5f, 0.0f,		102.0f / 255.0f, 102.0f / 255.0f, 204.0f / 255.0f,		0.9f, 0.75f,	1.0f,//N 13
	0.4f, 0.5f, 0.0f,		102.0f / 255.0f, 102.0f / 255.0f, 204.0f / 255.0f,		0.7f, 0.75f,	1.0f,//L 11
	-0.4f, 0.3f, 0.0f,		153.0f / 255.0f, 204.0f / 255.0f, 51.0f / 255.0f,		0.3f, 0.65f,	1.0f,//P 15
	0.2f, 0.3f, 0.0f,		153.0f / 255.0f, 204.0f / 255.0f, 51.0f / 255.0f,		0.6f, 0.65f,	1.0f,//I 8
	-0.1f, 0.6f, 0.0f,		153.0f / 255.0f, 204.0f / 255.0f, 51.0f / 255.0f,		0.45f, 0.8f,	1.0f,//O 14
};

int main(void)
{
	//Se inicia GLFW
	glfwInit();

	//Se asignan los parametros para la ventana de opengl
	// Versión mayor [3].3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// version menor 3,[3]
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// El profile core tiene todas las nuevas funcionalidades, el compatibility acepta funciones viejas
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	//dimensiones y nomvre de la ventana
	GLFWwindow* window = glfwCreateWindow(500, 500, "Juan Alvarez 1750688887", NULL, NULL);


	// si hay un error, reportar el error a consola
	if (window == NULL) {
		std::cout << "Failed to crteate GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}


	// Asigna el contexto actual a "ventana"
	glfwMakeContextCurrent(window);

	// carga glad
	gladLoadGL();


	glViewport(0, 0, 500, 500);

	//Se crea el shaderProgram
	Shader shaderProgram("shader.vs", "shader.fs");
	VAO VAO1;
	VAO1.Bind();
	
	//Variables: Vertex Array Object y Vertex Buffer Object 
	VBO VBO1(vertices, sizeof(vertices));

	//Se configura el VBO
	VAO1.LinkVBO(VBO1, 0, 3, 9 * sizeof(float), (void*)0);
	VAO1.LinkVBO(VBO1, 1, 3,  9 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkVBO(VBO1, 2, 2, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkVBO(VBO1, 3, 1, 9 * sizeof(float), (void*)(8 * sizeof(float)));

	VAO1.Unbind();
	VBO1.Unbind();

	//Se cargan las texturas 1 y 2
	Texture tex0("textura1.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	tex0.texUnit(shaderProgram, "tex0", 0);

	Texture tex1("textura2.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	tex1.texUnit(shaderProgram, "tex1", 1);

	//Se busca el uniform "alpha"
	GLuint id = glGetUniformLocation(shaderProgram.ID, "alpha");
	
	// Tiempo inicial
	auto timeInitial = std::chrono::system_clock::now();

	// continua el programa solo cuando se haya cerrado la ventana
	while (!glfwWindowShouldClose(window)) {

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Se activa el shader program
		shaderProgram.Activate();

		//Se calcula el tiempo actual
		auto timeNow = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = timeNow - timeInitial;

		//Se le asigna el seno del tiemp actual al uniform "alpha"
		glUniform1f(id, abs(sin(elapsed_seconds.count())));
		
		//Se cargan las dos texturas
		tex0.Bind(GL_TEXTURE0);
		tex1.Bind(GL_TEXTURE1);

		VAO1.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 27);

		//carga en pantalla lo almacenado en el buffer
		glfwSwapBuffers(window);
		// Termina de procesar los eventos en la cola para que no se congele la pantalla
		glfwPollEvents();
	}

	// Se elimina lo que se dejó de usar
	tex0.Delete();
	VAO1.Delete();
	VBO1.Delete();
	shaderProgram.Delete();


	// elimina de opengl la ventana y su contexto
	glfwDestroyWindow(window);

	//Se termina glfw
	glfwTerminate();
	return 0;
}