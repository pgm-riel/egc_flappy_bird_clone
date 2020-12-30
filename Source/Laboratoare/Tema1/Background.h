#pragma once

#include <string>
#include <Core/Engine.h>

class Background
{
public:

	Background();
	~Background();
	// map for storing the mesh 
	std::unordered_map<std::string, Mesh*> meshes_bg;

	// function for drawing ground
	Mesh * CreateGround(const char *name);
	// function for drawing sky
	Mesh * CreateSky(const char *name);
	// function for drawing block boundaries in case the game window is resized 
	Mesh * CreateBlocks(const char *name);

private:

	// function for creating mesh
	Mesh * CreateMesh(const char *name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

protected:

	glm::vec3 initpos = glm::vec3(0, 0, 0);


};