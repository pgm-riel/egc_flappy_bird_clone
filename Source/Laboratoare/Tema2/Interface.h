#pragma once

#include <string>
#include <Core/Engine.h>

class Interface
{
public:

	Interface();
	~Interface();
	// map for storing the mesh
	std::unordered_map<std::string, Mesh*> meshes_interface;

	// function for creating the hearts
	Mesh * CreateHearts();
	// function for creating the hearts shattered, first frame
	Mesh * CreateHeartsShatterFirst();
	// function for creating the hearts shattered, second frame
	Mesh * CreateHeartsShatterMid();
	// function for creating the hearts shattered, last frame
	Mesh * CreateHeartsEnd();
	// function for creating the background fuelbar
	Mesh * CreateBgFuelBar();
	// function for creating the foreground fuelbar
	Mesh * CreateFgFuelBar();
	

private:

	// function for creating the mesh
	Mesh * CreateMesh(const char *name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

protected:

	glm::vec3 initpos = glm::vec3(0, 0, 0);


};