#pragma once

#include <string>
#include <Core/Engine.h>

class LettersNDigits
{
public:

	LettersNDigits();
	~LettersNDigits();
	// map for storing the mesh 
	std::unordered_map<std::string, Mesh*> meshes_ld;

	// function for drawing message GAME OVER
	Mesh * CreateLetters(const char * letters);

private:

	// function for creating mesh
	Mesh * CreateMesh(const char *name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

protected:

	glm::vec3 initpos = glm::vec3(0, 0, 0);

};