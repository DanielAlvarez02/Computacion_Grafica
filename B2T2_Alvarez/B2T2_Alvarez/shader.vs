#version 330 core

layout (location = 0) in vec3 aPos; //Posicion
layout (location = 1) in vec3 aColor; //Color
layout (location = 2) in vec2 aTex; //Coordenadas de textura
layout (location = 3) in float aNum; //Numero de textura

//Outputs
out vec3 color;
out vec2 texCoord;
out float numOfTex;

void main()
{
	gl_Position = vec4(aPos, 1.0);
	color = aColor;
	texCoord = aTex;
	numOfTex = aNum;
}