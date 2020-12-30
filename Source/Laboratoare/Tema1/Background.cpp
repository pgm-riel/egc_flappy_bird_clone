#include "Background.h"


#include <vector>
#include <iostream>

#include <Core/Engine.h>
using namespace std;

Background::Background()
{
}

Background::~Background()
{
}

// function for creating mesh
Mesh * Background::CreateMesh(const char * name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
{
	unsigned int VAO = 0;
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	unsigned int VBO = 0;
	GLuint VBO_ID = VBO;
	glGenBuffers(1, &VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	
	unsigned int IBO_ID = 0;
	glGenBuffers(1, &IBO_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);
	
	// set vertex position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

	// set vertex normal attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	// set texture coordinate attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	// set vertex color attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));

	glBindVertexArray(0);
	// Check for OpenGL errors
	CheckOpenGLError();

	// Mesh information is saved into a Mesh object

	meshes_bg[name] = new Mesh(name);
	meshes_bg[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	return meshes_bg[name];
}

// function for drawing ground
Mesh * Background::CreateGround(const char * name)
{

	vector<VertexFormat> vertices2
	{
		VertexFormat(initpos + glm::vec3(0.f, 0.f,  0), glm::vec3(0.0f, 0.0f, 0.0f)), //0
		VertexFormat(initpos + glm::vec3(3.6f, 0.f,  0), glm::vec3(0.0f, 0.0f, 0.0f)), // 1
		VertexFormat(initpos + glm::vec3(7.2f, 0.f,  0), glm::vec3(0.0f, 0.0f, 0.0f)), // 2
		VertexFormat(initpos + glm::vec3(10.8f, 0.f,  0), glm::vec3(0.0f, 0.0f, 0.0f)), // 3
		VertexFormat(initpos + glm::vec3(0.f, 0.05f,  0), glm::vec3(0.0f, 0.0f, 0.0f)), // 4
		VertexFormat(initpos + glm::vec3(2.4f, 0.05f,  0),glm::vec3(0.0f, 0.0f, 0.0f)), // 5
		VertexFormat(initpos + glm::vec3(6.f, 0.05f,  0), glm::vec3(0.0f, 0.0f, 0.0f)), // 6
		VertexFormat(initpos + glm::vec3(8.4f, 0.05f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 7
		VertexFormat(initpos + glm::vec3(10.8f, 0.05f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 8

	};

	vector<unsigned short> indices2 =
	{
		0, 1, 4,	
		1, 4, 5,
		1, 5, 6,
		1, 6, 2,
		2, 6, 7,
		2, 7, 8,
		2, 8, 3,
	};


	Mesh * ground = Background::CreateMesh(name, vertices2, indices2);

	return ground;
}

// function for drawing sky
Mesh * Background::CreateSky(const char * name)
{

	vector<VertexFormat> vertices2
	{
		VertexFormat(initpos + glm::vec3(0.f, 2.f,  0), glm::vec3(0.70196f, 0.830980f, 0.92588f)), //0
		VertexFormat(initpos + glm::vec3(0.4f, 2.01f,  0), glm::vec3(0.96196f, 0.950980f, 0.79588f)), // 1
		VertexFormat(initpos + glm::vec3(0.f, 3.f,  0), glm::vec3(0.70196f, 0.830980f, 0.92588f)), // 2
		VertexFormat(initpos + glm::vec3(0.4f, 3.2f,  0), glm::vec3(0.70196f, 0.830980f, 0.92588f)), // 3

	};

	vector<unsigned short> indices2 =
	{
		0, 1, 2,	
		1, 2, 3,
	};

	Mesh * sky = Background::CreateMesh(name, vertices2, indices2);

	return sky;
}

// function for drawing block boundaries in case the game window is resized 
Mesh * Background::CreateBlocks(const char * name)
{

	vector<VertexFormat> vertices2
	{
		VertexFormat(initpos + glm::vec3(0.f, 0.f,  0), glm::vec3(0.3f, 0.3f, 0.1f)), //0
		VertexFormat(initpos + glm::vec3(1.f, 0.f,  0), glm::vec3(0.3f, 0.1f, 1.f)), // 1
		VertexFormat(initpos + glm::vec3(0.f, 1.f,  0), glm::vec3(0.3f, 0.3f, 0.1f)), // 2
		VertexFormat(initpos + glm::vec3(1.f, 1.f,  0), glm::vec3(0.3f, 0.1f, 1.f)), // 3



	};

	vector<unsigned short> indices2 =
	{
		0, 1, 2,	
		1, 2, 3,
	};


	Mesh * block = Background::CreateMesh(name, vertices2, indices2);

	return block;
}
