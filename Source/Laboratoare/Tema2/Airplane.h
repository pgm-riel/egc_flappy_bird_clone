#pragma once

#include <string>
#include <Core/Engine.h>

class AirPlane
{
public:

	AirPlane();
	~AirPlane();
	
	// map for storing the mesh
	std::unordered_map<std::string, Mesh*> meshes_airplane;

	// function for creating the plane
	Mesh * CreatePlane();
	// function for creating the propeller
	Mesh * CreatePropeller();	

private:

	// function for creating the mesh
	Mesh * CreateMesh(const char *name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

protected:

	glm::vec3 initpos = glm::vec3(0, 0, 0);


};