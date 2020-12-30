#include "Interface.h"
#include <vector>
#include <iostream>
#include <math.h>

#include <Core/Engine.h>
using namespace std;

Interface::Interface()
{
}

Interface::~Interface()
{
}
// function for creating the hearts
Mesh * Interface::CreateHearts()
{
	Mesh* heart_mesh = new Mesh("heart_mesh");
	heart_mesh->LoadMesh(RESOURCE_PATH::MODELS + "My_models", "heart.obj");
	meshes_interface[heart_mesh->GetMeshID()] = heart_mesh;

	return heart_mesh;


}
// function for creating the hearts shattered, first frame
Mesh * Interface::CreateHeartsShatterFirst()
{
	Mesh* heart_mesh = new Mesh("heart_mesh_1");
	heart_mesh->LoadMesh(RESOURCE_PATH::MODELS + "My_models", "heart_shatter_first.obj");
	meshes_interface[heart_mesh->GetMeshID()] = heart_mesh;

	return heart_mesh;
}
// function for creating the hearts shattered, second frame
Mesh * Interface::CreateHeartsShatterMid()
{
	Mesh* heart_mesh = new Mesh("heart_mesh_2");
	heart_mesh->LoadMesh(RESOURCE_PATH::MODELS + "My_models", "heart_shatter_second.obj");
	meshes_interface[heart_mesh->GetMeshID()] = heart_mesh;

	return heart_mesh;
}
// function for creating the hearts shattered, last frame
Mesh * Interface::CreateHeartsEnd()
{
	Mesh* heart_mesh = new Mesh("heart_mesh_3");
	heart_mesh->LoadMesh(RESOURCE_PATH::MODELS + "My_models", "heart_shatter_end.obj");
	meshes_interface[heart_mesh->GetMeshID()] = heart_mesh;

	return heart_mesh;
}
// function for creating the background fuelbar
Mesh * Interface::CreateBgFuelBar()
{
	vector<VertexFormat> vertices
	{
		VertexFormat(initpos + glm::vec3(0, 0, 0), glm::vec3(0.f, 0.f, 0.f)), // 0
		VertexFormat(initpos + glm::vec3(0, 0.5f, 0), glm::vec3(0.f, 0.f, 0.f)), // 1
		VertexFormat(initpos + glm::vec3(1, 0, 0), glm::vec3(0.f, 0.f, 0.f)), // 2
		VertexFormat(initpos + glm::vec3(1, 0.5f, 0), glm::vec3(0.f, 0.f, 0.f)), // 3
		
	};

	vector<unsigned short> indices =
	{
		0, 1, 2,
		1, 3, 2,
	};

	Mesh * bg_fuel = Interface::CreateMesh("bg_fuel", vertices, indices);

	return bg_fuel;



}
// function for creating the foreground fuelbar
Mesh * Interface::CreateFgFuelBar()
{
	vector<VertexFormat> vertices
	{
		VertexFormat(initpos + glm::vec3(0.02f, 0.02f, 0), glm::vec3(1, 1, 1)), // 0
		VertexFormat(initpos + glm::vec3(0.02f, 0.48f, 0), glm::vec3(1, 1, 1)), // 1
		VertexFormat(initpos + glm::vec3(0.98f, 0.02f, 0), glm::vec3(1, 1, 1)), // 2
		VertexFormat(initpos + glm::vec3(0.98f, 0.48f, 0), glm::vec3(1, 1, 1)), // 3

	};

	vector<unsigned short> indices =
	{
		0, 1, 2,
		1, 3, 2,
	};


	Mesh * fg_fuel = Interface::CreateMesh("fg_fuel", vertices, indices);

	return fg_fuel;


}

Mesh * Interface::CreateMesh(const char * name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
{
	unsigned int VAO = 0;
	// TODO: Create the VAO and bind it
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// TODO: Create the VBO and bind it
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// TODO: Send vertices data into the VBO buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	// TODO: Crete the IBO and bind it
	unsigned int IBO;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	// TODO: Send indices data into the IBO buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// ========================================================================
	// This section describes how the GPU Shader Vertex Shader program receives data

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
	// ========================================================================

	// Unbind the VAO
	glBindVertexArray(0);

	// Check for OpenGL errors
	CheckOpenGLError();

	// Mesh information is saved into a Mesh object
	meshes_interface[name] = new Mesh(name);
	meshes_interface[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	meshes_interface[name]->vertices = vertices;
	meshes_interface[name]->indices = indices;
	return meshes_interface[name];
}
