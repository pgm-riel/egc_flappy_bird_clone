#include "Pipes.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
using namespace std;

Pipes::Pipes()
{
}

Pipes::~Pipes()
{
}

// function for creating mesh
Mesh * Pipes::CreateMesh(const char * name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
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

	meshes_pipes[name] = new Mesh(name);
	meshes_pipes[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	return meshes_pipes[name];
}

// function for drawing top pipe
Mesh * Pipes::CreateTopPipes(const char *name)
{
	vector<VertexFormat> vertices2
	{
		VertexFormat(initpos + glm::vec3(0.f, 0.1f,  0), glm::vec3(0.3f, 0.3f, 0.1f)), //0
		VertexFormat(initpos + glm::vec3(0.40f, 0.1f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 1
		VertexFormat(initpos + glm::vec3(0.40f, 2,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 2
		VertexFormat(initpos + glm::vec3(0.f, 2,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 3
		VertexFormat(initpos + glm::vec3(-0.01f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 4
		VertexFormat(initpos + glm::vec3(0.41f, 0.f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 5
		VertexFormat(initpos + glm::vec3(-0.01f, 0.1f,  0), glm::vec3(0.3f, 0.3f, 0.1f)), // 6
		VertexFormat(initpos + glm::vec3(0.41f, 0.1f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 7
	};

	vector<unsigned short> indices2 =
	{
		0, 1, 2,	
		0, 3, 2,
		4, 5, 6,
		5, 6, 7,
	};


	Mesh * top = Pipes::CreateMesh(name, vertices2, indices2);

	return top;
}

// function for drawing bottom pipe
Mesh * Pipes::CreateBottomPipes(const char *name)
{
	vector<VertexFormat> vertices2
	{
		VertexFormat(initpos + glm::vec3(0, 0.2f,  0), glm::vec3(0, 0, 0)), // 0
		VertexFormat(initpos + glm::vec3(0.40f, 0.2f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 1
		VertexFormat(initpos + glm::vec3(0.40f, 1.9f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 2
		VertexFormat(initpos + glm::vec3(0, 1.9f,  0), glm::vec3(0.3f, 0.3f, 0.28f)), // 3
		VertexFormat(initpos + glm::vec3(-0.01f, 1.9f,  0), glm::vec3(0.3f, 0.3f, 0.1f)), // 4
		VertexFormat(initpos + glm::vec3(0.41f, 1.9f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 5
		VertexFormat(initpos + glm::vec3(-0.01f, 2.f,  0), glm::vec3(0.0f, .0f, 0.0f)), // 6
		VertexFormat(initpos + glm::vec3(0.41f, 2.f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 7
		VertexFormat(initpos + glm::vec3(-0.01f, 0,  0), glm::vec3(0, 0, 0)), // 8
		VertexFormat(initpos + glm::vec3(0.41f, 0,  0), glm::vec3(0.3f, 0.3f, 0.28f)), // 9
		VertexFormat(initpos + glm::vec3(-0.01f, 0.2f,  0), glm::vec3(0, 0, 0)), // 10
		VertexFormat(initpos + glm::vec3(0.41f, 0.2f,  0), glm::vec3(1.0f, 1.0f, 0.78f)), // 11

	};

	vector<unsigned short> indices2 =
	{
		0, 1, 2,
		0, 3, 2,
		4, 5, 6,
		5, 6, 7,
		8, 9, 10,
		9, 10, 11,
	};

	
	Mesh * bottom = Pipes::CreateMesh(name, vertices2, indices2);

	return bottom;
}

