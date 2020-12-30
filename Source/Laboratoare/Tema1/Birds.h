#pragma once

#include <string>
#include <Core/Engine.h>

class Birds
{
public :

	Birds();
	~Birds();
	// map for storing the mesh
	std::unordered_map<std::string, Mesh*> meshes_birds;

	// function for drawing the bird's body
	Mesh * CreateBody();
	// function for drawing the bird's wing
	Mesh * CreateWings();
	// function for drawing the bird's eye
	Mesh * CreateEye();

private:

	// function for creating the mesh
	Mesh * CreateMesh(const char *name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

protected:
	
	glm::vec3 initpos = glm::vec3(0.001, 0.001, 0);
	

};