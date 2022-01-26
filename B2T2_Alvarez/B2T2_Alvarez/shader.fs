#version 330 core

// Output en RGBA
out vec4 FragColor;

in vec3 color; // color
in vec2 texCoord; // coordenadas de textura
in float numOfTex; //Numero de textura (puede ser la textura 0 o la 1)

// Texturas 1 y 2
uniform sampler2D tex0;
uniform sampler2D tex1;

//determina si está visible el color o la textura
uniform float alpha;

void main()
{	
	//Si el numero de textura es 0 se escoge la textura 0, caso contrario la textura 1
	vec4 texColor = texture(tex0, texCoord);
	if(numOfTex == 1.0f){
		texColor = texture(tex1, texCoord);
	}

	// Se Combinan la textura con el color
	FragColor = mix(vec4(color,1.0f),texColor,alpha);
}