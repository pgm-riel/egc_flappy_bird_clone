#pragma once

#include <string>
#include <Core/Engine.h>

class Clouds
{
public:

	Clouds();
	~Clouds();
	// map for storing the mesh
	std::unordered_map<std::string, Mesh*> meshes_clouds;

	// function for creating the cloud
	Mesh * CreateClouds();
	


protected:

	glm::vec3 initpos = glm::vec3(0, 0, 0);


};