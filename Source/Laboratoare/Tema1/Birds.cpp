#include "Birds.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
using namespace std;

Birds::Birds()
{
}

Birds::~Birds()
{
}

// function for creating the mesh
Mesh * Birds::CreateMesh(const char * name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
{
	unsigned int VAO = 0;
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	unsigned int VBO = 0;
	GLuint VBO_ID = VBO;
	glGenBuffers(1, &VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	// TODO: Crete the IBO and bind it
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
	meshes_birds[name] = new Mesh(name);
	meshes_birds[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	return meshes_birds[name];
}

// function for drawing the bird's body
Mesh * Birds::CreateBody()
{
	
		vector<VertexFormat> vertices2
		{
			VertexFormat(initpos + glm::vec3(0.f, 0.03f,  0), glm::vec3(0, 0,  0)), // 0
			VertexFormat(initpos + glm::vec3(0.15f, 0.02f,  0), glm::vec3(0, 0, 0.001f)), // 1
			VertexFormat(initpos + glm::vec3(0.15f, 0.15f,  0), glm::vec3(0.7f, 0, 0)), // 2
			VertexFormat(initpos + glm::vec3(0, 0.15f,  0), glm::vec3(0.6f, 0, 0)), // 3

			
			VertexFormat(initpos + glm::vec3(0.3f, 0.04f,  0), glm::vec3(0, 0, 0)), // 4
			VertexFormat(initpos + glm::vec3(0.3f, 0.15f,  0), glm::vec3(1, 0, 0)), // 5
			
			VertexFormat(initpos + glm::vec3(0.37f, 0.06f,  0), glm::vec3(0, 0, 0)), // 6
			VertexFormat(initpos + glm::vec3(0.44f, 0.15f,  0), glm::vec3(0, 0, 0)), // 7
			VertexFormat(initpos + glm::vec3(0.3f, 0.07f,  0), glm::vec3(0, 0, 0)), // 8

			VertexFormat(initpos + glm::vec3(0.f, 0.3f,  0), glm::vec3(1, 0, 0)), // 9
			VertexFormat(initpos + glm::vec3(0.15f, 0.3f,  0), glm::vec3(1, 0, 0)), // 10
			VertexFormat(initpos + glm::vec3(0.3f, 0.3f,  0), glm::vec3(1, 0, 0)), // 11
			VertexFormat(initpos + glm::vec3(0.45f, 0.29f,  0), glm::vec3(0.37f, 0.39f, 0.39f)), // 12
			VertexFormat(initpos + glm::vec3(0.6f, 0.27f,  0), glm::vec3(0.5f, 0.5f, 0.5f)), // 13

			VertexFormat(initpos + glm::vec3(0.3f, 0.365f,  0), glm::vec3(0.6f, 0, 1)), // 14
			VertexFormat(initpos + glm::vec3(0.26f, 0.37f,  0), glm::vec3(1, 0.64f, 1.f)), // 15
			VertexFormat(initpos + glm::vec3(0.22f, 0.375f,  0), glm::vec3(1, 0.241f, 0.1877f)), // 16
			VertexFormat(initpos + glm::vec3(0.15f, 0.37f,  0), glm::vec3(1, 0.39f, 0.45f)), // 17

			VertexFormat(initpos + glm::vec3(0.44f, 0.32f,  0), glm::vec3(1, 1.0f, 1)), // 18
			
			VertexFormat(initpos + glm::vec3(0.12f, 0.37f,  0), glm::vec3(1, 0.3f, 0.2f)), // 19
			VertexFormat(initpos + glm::vec3(0.09f, 0.36f,  0), glm::vec3(1, 0.56f, 0.22f)), // 20
			VertexFormat(initpos + glm::vec3(0.06f, 0.34f,  0), glm::vec3(1, 0, 0)), // 21
			VertexFormat(initpos + glm::vec3(0.03f, 0.33f,  0), glm::vec3(1, 0, 0)), // 22

			VertexFormat(initpos + glm::vec3(-0.12f, 0.15f,  0), glm::vec3(1, 0, 0)), // 23
			VertexFormat(initpos + glm::vec3(-0.045f, 0.07f,  0), glm::vec3(0, 0, 0)), // 24

			VertexFormat(initpos + glm::vec3(-0.06f, 0.15f,  0), glm::vec3(1, 0, 0)), // 25
			VertexFormat(initpos + glm::vec3(-0.06f, 0.285f,  0), glm::vec3(0, 0, 0)), // 26

			VertexFormat(initpos + glm::vec3(-0.10f, 0.28f,  0), glm::vec3(0, 0, 0)), // 27
			VertexFormat(initpos + glm::vec3(-0.11f, 0.23f,  0), glm::vec3(0, 0, 0)), // 28
			VertexFormat(initpos + glm::vec3(-0.17f, 0.22f,  0), glm::vec3(0, 0, 0)), // 29

			// copies
			VertexFormat(initpos + glm::vec3(0.f, 0.03f,  0), glm::vec3(0, 0,  0)), // 30
			VertexFormat(initpos + glm::vec3(0.3f, 0.15f,  0), glm::vec3(0, 0, 0)), // 31
			VertexFormat(initpos + glm::vec3(0.3f, 0.07f,  0), glm::vec3(0, 0, 0)), // 32

			VertexFormat(initpos + glm::vec3(0.33f, 0.29f,  0), glm::vec3(1.f, 1, 1)), // 32



		};

		vector<unsigned short> indices2 =
		{
			0, 1, 2,	// indices for first triangle
			0, 3, 2,
			1, 2, 5,
			1, 5, 8,
			1, 4, 8,
			4, 6, 7,
			4, 8, 7,
			5, 8, 7,
			3, 2, 9,
			2, 9, 10,
			2, 5, 10,
			10, 5, 11,
			5, 7, 11,
			11, 7, 12,
			7, 12, 13,
			11, 12, 18,
			11, 18, 14,
			11, 14, 15,
			11, 15, 16,
			10, 11, 16,
			10, 16, 17,
			10, 17, 19,
			10, 19, 20,
			10, 20, 21,
			10, 21, 22,
			10, 9, 22,
			0, 23, 3,
			0, 23, 24,
			3, 9, 26,
			3, 25, 26,
			25, 26, 27,
			25, 27, 28,
			23, 25, 28,
			23, 28, 29,
			
		};
		
		
		Mesh * body = Birds::CreateMesh("body", vertices2, indices2);
	
	return body;
}

// function for drawing the bird's wing
Mesh * Birds::CreateWings()
{
	
	vector<VertexFormat> vertices2
	{
		VertexFormat(initpos + glm::vec3(0.3f, 0.2f,  0), glm::vec3(1, 0, 0)), // 0
		VertexFormat(initpos + glm::vec3(0.12f, 0.21f,  0), glm::vec3(1, 0, 0)), // 1
		VertexFormat(initpos + glm::vec3(0.24f, 0.13f,  0), glm::vec3(0, 0, 0)), // 2
		VertexFormat(initpos + glm::vec3(0.12f, 0.19f,  0), glm::vec3(1, 0, 0)), // 3
		VertexFormat(initpos + glm::vec3(0.17f, 0.08f,  0), glm::vec3(0, 0, 0)), // 4
		VertexFormat(initpos + glm::vec3(0.08f, 0.17f,  0), glm::vec3(1, 0, 0)), // 5
		VertexFormat(initpos + glm::vec3(0.0f, 0.12f,  0), glm::vec3(1, 0, 0)), // 6
		VertexFormat(initpos + glm::vec3(0.11f, 0.04f,  0), glm::vec3(0, 0, 0)), // 7
		VertexFormat(initpos + glm::vec3(-0.05f, 0.02f,  0), glm::vec3(0, 0, 0)), // 8
		VertexFormat(initpos + glm::vec3(-0.10f, 0.10f,  0), glm::vec3(0, 0, 0)), // 9
		VertexFormat(initpos + glm::vec3(-0.16f, 0.07f,  0), glm::vec3(0, 0, 0.4f)), // 10
		VertexFormat(initpos + glm::vec3(-0.21f, 0.0f,  0), glm::vec3(0, 0, 0.4f)), // 11
	};

	vector<unsigned short> indices2 =
	{
		0, 1, 2,
		1, 2, 3,
		2, 3, 4,
		3, 4, 5,
		4, 5, 6,
		4, 6, 7,
		6, 7, 8,
		6, 8, 9,
		8, 9, 10,
		8, 10, 11,
	};

	Mesh * wings = Birds::CreateMesh("wings", vertices2, indices2);

	return wings;
}

// function for drawing the bird's eye
Mesh * Birds::CreateEye()
{
	vector<VertexFormat> vertices2
	{
		// eye
		VertexFormat(initpos + glm::vec3(0.34f, 0.27f,  0), glm::vec3(1.f, 1.f, 1.0f)), // 0
		VertexFormat(initpos + glm::vec3(0.34f, 0.29f,  0), glm::vec3(1, 1, 1.f)), // 1
		VertexFormat(initpos + glm::vec3(0.32f, 0.285f,  0), glm::vec3(1.f, 1.f, 1.f)), // 2
		VertexFormat(initpos + glm::vec3(0.3f, 0.28f,  0), glm::vec3(1.f, 1, 1)), // 3
		VertexFormat(initpos + glm::vec3(0.31f, 0.2825f,  0), glm::vec3(1.f, 1, 1)), // 4
		VertexFormat(initpos + glm::vec3(0.32f, 0.265f,  0), glm::vec3(1.f, 1, 1)), // 5
		VertexFormat(initpos + glm::vec3(0.33f, 0.255f,  0), glm::vec3(1.f, 1, 1)), // 6
		VertexFormat(initpos + glm::vec3(0.335f, 0.265f,  0), glm::vec3(1.f, 1, 1)), // 7

	};

	vector<unsigned short> indices2 =
	{
		
		0, 1, 2,
		0, 2, 3,
		0, 3, 4,
		0, 4, 5,
		0, 5, 6,
		0, 6, 7,
		
	};

	Mesh * eye = Birds::CreateMesh("eye", vertices2, indices2);

	return eye;
}


