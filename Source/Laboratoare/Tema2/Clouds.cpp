#include "Clouds.h"
#include <vector>
#include <iostream>
#include <math.h>

#include <Core/Engine.h>
using namespace std;


Clouds::Clouds()
{
}

Clouds::~Clouds()
{
}

Mesh * Clouds::CreateClouds()
{
	Mesh* cloud_mesh = new Mesh("cloud_mesh");
	cloud_mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
	meshes_clouds[cloud_mesh->GetMeshID()] = cloud_mesh;

	return cloud_mesh;
}
