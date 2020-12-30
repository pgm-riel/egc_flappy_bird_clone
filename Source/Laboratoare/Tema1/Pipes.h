#pragma once

#include <string>
#include <Core/Engine.h>

class Pipes
{
public:

	Pipes();
	~Pipes();
	// map for storing the mesh
	std::unordered_map<std::string, Mesh*> meshes_pipes;

	// function for drawing top pipe
	Mesh * CreateTopPipes(const char *name);
	// function for drawing bottom pipe
	Mesh * CreateBottomPipes(const char *name);

private:

	// function for creating mesh
	Mesh * CreateMesh(const char *name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

protected:

	glm::vec3 initpos = glm::vec3(0, 0, 0);


};