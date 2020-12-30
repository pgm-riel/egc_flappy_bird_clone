#pragma once

#include <string>
#include <Core/Engine.h>

class Items
{
public:

	Items();
	~Items();
	// map for storing the mesh
	std::unordered_map<std::string, Mesh*> meshes_items;

	// function for creating the bomb
	Mesh * CreateBombs();
	// function for creating the bomb shattered second frame
	Mesh * CreateBombsShatterMid();
	// function for creating the bomb shattered last frame
	Mesh * CreateBombsShatterEnd();
	// function for creating the fuel
	Mesh * CreateFuel();
	// function for creating the fuel shattered second frame
	Mesh * CreateFuelShatterMid();
	// function for creating the fuel shattered last frame
	Mesh * CreateFuelShatterEnd();

private:


	// function for creating the mesh
	Mesh * CreateMesh(const char *name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

protected:

	glm::vec3 initpos = glm::vec3(0, 0, 0);


};