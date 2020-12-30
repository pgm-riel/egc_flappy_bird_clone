#include "LettersNDigits.h"


#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

LettersNDigits::LettersNDigits()
{
}

LettersNDigits::~LettersNDigits()
{
}

// function for creating mesh
Mesh * LettersNDigits::CreateMesh(const char * name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
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

	meshes_ld[name] = new Mesh(name);
	meshes_ld[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	return meshes_ld[name];
}

// function for drawing message GAME OVER
Mesh * LettersNDigits::CreateLetters(const char * letters)
{
		vector<VertexFormat> vertices2
		{
			// G
			VertexFormat(initpos, glm::vec3(0.f, 0.f, 0.f)), // 0
			VertexFormat(initpos + glm::vec3(0.20f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 1
			VertexFormat(initpos + glm::vec3(0.20f, 0.05f,  0), glm::vec3(0, 0, 0)), // 2
			VertexFormat(initpos + glm::vec3(0, 0.05f,  0), glm::vec3(0, 0, 0)), // 3
			VertexFormat(initpos + glm::vec3(0, 0.20f,  0), glm::vec3(0, 0, 0)), // 4
			VertexFormat(initpos + glm::vec3(0.20f, 0.10f,  0), glm::vec3(0, 0, 0)), // 5
			VertexFormat(initpos + glm::vec3(0.05f, 0.05f,  0), glm::vec3(0, 0, 0)), // 6
			VertexFormat(initpos + glm::vec3(0.06f, 0.10f,  0), glm::vec3(0, 0, 0)), // 7
			VertexFormat(initpos + glm::vec3(0.20f, 0.20f,  0), glm::vec3(0, 0, 0)), // 8
			VertexFormat(initpos + glm::vec3(0.f, 0.15f,  0), glm::vec3(0, 0, 0)), // 9
			// A
			VertexFormat(initpos + glm::vec3(0.25f, 0,  0), glm::vec3(0.0f, 0.f, 0.f)), // 10
			VertexFormat(initpos + glm::vec3(0.45f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 11
			VertexFormat(initpos + glm::vec3(0.35f, 0.20,  0), glm::vec3(0.f, 0.f, 0.f)), // 12
			VertexFormat(initpos + glm::vec3(0.29f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 13
			VertexFormat(initpos + glm::vec3(0.41f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 14
			// M
			VertexFormat(initpos + glm::vec3(0.50f, 0,  0), glm::vec3(0.0f, 0.f, 0.f)), // 15
			VertexFormat(initpos + glm::vec3(0.70f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 16
			VertexFormat(initpos + glm::vec3(0.60f, 0.20,  0), glm::vec3(0.f, 0.f, 0.f)), // 17
			VertexFormat(initpos + glm::vec3(0.54f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 18
			VertexFormat(initpos + glm::vec3(0.66f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 19

			VertexFormat(initpos + glm::vec3(0.70f, 0,  0), glm::vec3(0.0f, 0.f, 0.f)), // 20
			VertexFormat(initpos + glm::vec3(0.90f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 21
			VertexFormat(initpos + glm::vec3(0.80f, 0.20,  0), glm::vec3(0.f, 0.f, 0.f)), // 22
			VertexFormat(initpos + glm::vec3(0.74f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 23
			VertexFormat(initpos + glm::vec3(0.86f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 24
			// E
			VertexFormat(initpos + glm::vec3(0.95f, 0,  0), glm::vec3(0.0f, 0.f, 0.f)), // 25
			VertexFormat(initpos + glm::vec3(1.15f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 26
			VertexFormat(initpos + glm::vec3(0.95f, 0.20f,  0), glm::vec3(0.f, 0.f, 0.f)), // 27
			VertexFormat(initpos + glm::vec3(0.95f, 0.07f,  0), glm::vec3(0.f, 0.f, 0.f)), // 28
			VertexFormat(initpos + glm::vec3(0.95f, 0.13f,  0), glm::vec3(0.f, 0.f, 0.f)), // 29
			VertexFormat(initpos + glm::vec3(1.15f, 0.20f,  0), glm::vec3(0.f, 0.f, 0.f)), // 30
			VertexFormat(initpos + glm::vec3(1.15f, 0.10f,  0), glm::vec3(0.f, 0.f, 0.f)), // 31
			//O
			VertexFormat(initpos + glm::vec3(1.3f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 32
			VertexFormat(initpos + glm::vec3(1.5f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 33
			VertexFormat(initpos + glm::vec3(1.3f, 0.2f,  0), glm::vec3(0.f, 0.f, 0.f)), // 34
			VertexFormat(initpos + glm::vec3(1.5f, 0.2f,  0), glm::vec3(0.f, 0.f, 0.f)), // 35
			VertexFormat(initpos + glm::vec3(1.4f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 36
			VertexFormat(initpos + glm::vec3(1.4f, 0.2f,  0), glm::vec3(0.f, 0.f, 0.f)), // 37
			//V
			VertexFormat(initpos + glm::vec3(1.55f, 0.2f,  0), glm::vec3(0.f, 0.f, 0.f)), // 38
			VertexFormat(initpos + glm::vec3(1.75f, 0.2f,  0), glm::vec3(0.f, 0.f, 0.f)), // 39
			VertexFormat(initpos + glm::vec3(1.59f, 0.2f,  0), glm::vec3(0.f, 0.f, 0.f)), // 40
			VertexFormat(initpos + glm::vec3(1.71f, 0.2f,  0), glm::vec3(0.f, 0.f, 0.f)), // 41
			VertexFormat(initpos + glm::vec3(1.65f, 0.f,  0), glm::vec3(0.f, 0.f, 0.f)), // 42
			//E
			VertexFormat(initpos + glm::vec3(1.8f, 0,  0), glm::vec3(0.0f, 0.f, 0.f)), // 43
			VertexFormat(initpos + glm::vec3(2.f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 44
			VertexFormat(initpos + glm::vec3(1.8f, 0.20f,  0), glm::vec3(0.f, 0.f, 0.f)), // 45
			VertexFormat(initpos + glm::vec3(1.8f, 0.07f,  0), glm::vec3(0.f, 0.f, 0.f)), // 46
			VertexFormat(initpos + glm::vec3(1.8f, 0.13f,  0), glm::vec3(0.f, 0.f, 0.f)), // 47
			VertexFormat(initpos + glm::vec3(2.f, 0.20f,  0), glm::vec3(0.f, 0.f, 0.f)), // 48
			VertexFormat(initpos + glm::vec3(2.f, 0.10f,  0), glm::vec3(0.f, 0.f, 0.f)), // 49

			//R
			VertexFormat(initpos + glm::vec3(2.05f, 0,  0), glm::vec3(0.0f, 0.f, 0.f)), // 50
			VertexFormat(initpos + glm::vec3(2.25f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 51
			VertexFormat(initpos + glm::vec3(2.05f, 0.20f,  0), glm::vec3(0.f, 0.f, 0.f)), // 52
			VertexFormat(initpos + glm::vec3(2.05f, 0.10f,  0), glm::vec3(0.f, 0.f, 0.f)), // 53
			VertexFormat(initpos + glm::vec3(2.21f, 0,  0), glm::vec3(0.f, 0.f, 0.f)), // 54
			VertexFormat(initpos + glm::vec3(2.09f, 0,  0), glm::vec3(0.0f, 0.f, 0.f)), // 55
			VertexFormat(initpos + glm::vec3(2.25f, 0.20f,  0), glm::vec3(0.f, 0.f, 0.f)), // 56
		};

		vector<unsigned short> indices2 =
		{
			// G
			0, 1, 2,	
			0, 3, 2,
			3, 5, 2,
			3, 4, 6,
			2, 5, 7,
			4, 8, 9,
			// A
			10, 13, 12,
			11, 14, 12,
			// M
			15, 18, 17,
			16, 23, 17,
			20, 19, 22,
			21, 24, 22,
			// E
			25, 26, 28,
			27, 29, 30,
			29, 28, 31,
			//O
			32, 36, 34,
			36, 33, 35,
			32, 34, 37,
			33, 35, 37,
			//V
			38, 40, 42,
			39, 41, 42,
			//E
			43, 44, 46,
			45, 47, 48,
			47, 46, 49,
			//R
			50, 55, 53,
			51, 54, 53,
			52, 53, 56,

		};

		Mesh * message = LettersNDigits::CreateMesh(letters, vertices2, indices2);

		return message;
}
