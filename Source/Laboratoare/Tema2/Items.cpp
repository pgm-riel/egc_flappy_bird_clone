#include "Items.h"
#include <vector>
#include <iostream>
#include <math.h>

#include <Core/Engine.h>
using namespace std;


Items::Items()
{
}

Items::~Items()
{
}
// function for creating the bomb
Mesh * Items::CreateBombs()
{
	Mesh* bombs_mesh = new Mesh("bombs_mesh");
	bombs_mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
	meshes_items[bombs_mesh->GetMeshID()] = bombs_mesh;

	return bombs_mesh;
}

// function for creating the bomb shattered second frame
Mesh * Items::CreateBombsShatterMid()
{
	Mesh* bombs_mesh = new Mesh("bombs_mesh_shatter_mid");
	bombs_mesh->LoadMesh(RESOURCE_PATH::MODELS + "My_models", "sphere_shatter_mid.obj");
	meshes_items[bombs_mesh->GetMeshID()] = bombs_mesh;

	return bombs_mesh;
}

// function for creating the bomb shattered last frame
Mesh * Items::CreateBombsShatterEnd()
{
	Mesh* bombs_mesh = new Mesh("bombs_mesh_shatter_end");
	bombs_mesh->LoadMesh(RESOURCE_PATH::MODELS + "My_models", "sphere_shatter_end.obj");
	meshes_items[bombs_mesh->GetMeshID()] = bombs_mesh;

	return bombs_mesh;
}
// function for creating the fuel
Mesh * Items::CreateFuel()
{

	Mesh* fuel_mesh = new Mesh("fuel_mesh");
	fuel_mesh->LoadMesh(RESOURCE_PATH::MODELS + "My_models", "fuel.obj");
	meshes_items[fuel_mesh->GetMeshID()] = fuel_mesh;

	return fuel_mesh;


}
// function for creating the fuel shattered second frame
Mesh * Items::CreateFuelShatterMid()
{

	Mesh* fuel_mesh = new Mesh("fuel_mesh_shatter_mid");
	fuel_mesh->LoadMesh(RESOURCE_PATH::MODELS + "My_models", "fuel_shatter_mid.obj");
	meshes_items[fuel_mesh->GetMeshID()] = fuel_mesh;

	return fuel_mesh;


}
// function for creating the fuel shattered last frame
Mesh * Items::CreateFuelShatterEnd()
{

	Mesh* fuel_mesh = new Mesh("fuel_mesh_shatter_end");
	fuel_mesh->LoadMesh(RESOURCE_PATH::MODELS + "My_models", "fuel_shatter_end.obj");
	meshes_items[fuel_mesh->GetMeshID()] = fuel_mesh;

	return fuel_mesh;


}


Mesh * Items::CreateMesh(const char * name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
{
	return nullptr;
}
