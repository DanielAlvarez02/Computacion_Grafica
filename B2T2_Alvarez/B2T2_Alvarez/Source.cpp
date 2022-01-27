#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <chrono>
#include <ctime> 
#include <cmath>

#include"shaderClass.h"
#include"VBO.h"
#include"VAO.h"
#include"EBO.h"
#include"Texture.h"

const unsigned int width = 500;
const unsigned int height = 500;


// coordenadas de un triángulo equilatero
GLfloat vertices[] =
{
	-0.5f, 0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 0.0f,	1.0f,//A 0
	-0.5f, -0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 1.0f,	1.0f,//B 2
	0.5f, 0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 0.0f,	1.0f,//C 1
	0.5f, -0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 1.0f,	1.0f,//D 3

	- 0.5f, 0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 0.0f,	0.0f,//A 0
	-0.5f, 0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 1.0f,	0.0f,//C 2
	0.5f, 0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 1.0f,	0.0f,//D 3
	0.5f, 0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 0.0f,	0.0f,//B 1

	0.5f, -0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 0.0f,	1.0f,//A 0
	0.5f, -0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 1.0f,	1.0f,//C 2
	0.5f, 0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 1.0f,	1.0f,//D 3
	0.5f, 0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 0.0f,	1.0f,//B 1

	-0.5f, -0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 0.0f,	0.0f,//A 0
	-0.5f, -0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 1.0f,	0.0f,//C 2
	-0.5f, 0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 1.0f,	0.0f,//D 3
	-0.5f, 0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 0.0f,	0.0f,//B 1

	-0.5f, -0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 0.0f,	1.0f,//A 0
	-0.5f, -0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 1.0f,	1.0f,//C 2
	0.5f, -0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 1.0f,	1.0f,//D 3
	0.5f, -0.5f, 0.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 0.0f,	1.0f,//B 1

	- 0.5f, 0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 0.0f,	0.0f,//A 0
	0.5f, 0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 0.0f,	0.0f,//B 1
	-0.5f, -0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		0.0f, 1.0f,	0.0f,//C 2
	0.5f, -0.5f, 1.0f,		255.0f / 255.0f, 102.0f / 255.0f, 102.0f / 255.0f,		1.0f, 1.0f,	0.0f//D 3
};

GLuint indices[] =
{
	0,1,2,2,1,3,
	4,5,6,6,5,7,
	8,9,10,10,9,11,
	12,13,14,14,13,15,
	16,17,18,18,17,19,
	20,21,22,22,21,23,
	24,25,26,26,25,27
};

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
int spinDirection = 1;


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
	GLFWwindow* window = glfwCreateWindow(width, height, "Juan Alvarez 1750688887", NULL, NULL);
	glfwSetKeyCallback(window, keyCallback );

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


	glViewport(0, 0, width, height);

	//Se crea el shaderProgram
	Shader shaderProgram("shader.vs", "shader.fs");
	VAO VAO1;
	VAO1.Bind();
	
	//Variables: Vertex Array Object y Vertex Buffer Object 
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices,sizeof(indices));

	//Se configura el VBO
	VAO1.LinkVBO(VBO1, 0, 3, 9 * sizeof(float), (void*)0);
	VAO1.LinkVBO(VBO1, 1, 3,  9 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkVBO(VBO1, 2, 2, 9 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkVBO(VBO1, 3, 1, 9 * sizeof(float), (void*)(8 * sizeof(float)));

	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();
	//Se cargan las texturas 1 y 2
	Texture tex0("textura1.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	tex0.texUnit(shaderProgram, "tex0", 0);

	Texture tex1("textura2.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	tex1.texUnit(shaderProgram, "tex1", 1);

	//Se busca el uniform "alpha"
	GLuint id = glGetUniformLocation(shaderProgram.ID, "alpha");
	
	// Tiempo inicial
	auto timeInitial = std::chrono::system_clock::now();

	glEnable(GL_DEPTH_TEST);
	double prevTime = glfwGetTime();
	float timePassed = 0;

	// continua el programa solo cuando se haya cerrado la ventana
	while (!glfwWindowShouldClose(window)) {

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glClear(GL_COLOR_BUFFER_BIT);
		
		//Se activa el shader program
		shaderProgram.Activate();

		double currentTime = glfwGetTime();
		if (currentTime - prevTime >= 1 / 3600) {
			timePassed+=0.001*spinDirection;
			currentTime = 0.0;
			prevTime = currentTime;
		}

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		model = glm::rotate(model, glm::radians(timePassed * 60), glm::vec3(1.0f, 1.0, 1.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
		proj = glm::perspective(glm::radians(60.0f), (float)(width/ height), 0.1f, 100.0f);

		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		int projlLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projlLoc, 1, GL_FALSE, glm::value_ptr(proj));

		//Se calcula el tiempo actual
		

		//Se le asigna el seno del tiemp actual al uniform "alpha"
		glUniform1f(id, sin(timePassed));
		
		//Se cargan las dos texturas
		tex0.Bind(GL_TEXTURE0);
		tex1.Bind(GL_TEXTURE1);

		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(GLuint), GL_UNSIGNED_INT, 0 );


		model = glm::translate(model, glm::vec3(-1.0f, -1.0f, 1.0f));
		float scale = sin(timePassed);
		model = glm::scale(model, glm::vec3(scale, scale, scale));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, 0);

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

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_RELEASE) {
		spinDirection *= -1;
	}
}