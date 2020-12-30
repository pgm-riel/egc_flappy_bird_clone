#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <Core/Engine.h>

#include <Laboratoare/Tema1/Birds.h>
#include <Laboratoare/Tema1/Pipes.h>
#include <Laboratoare/Tema1/LettersNDigits.h>
#include <Laboratoare/Tema1/Background.h>


using namespace std;

class Tema1 : public SimpleScene
{
public:
	// the real space 
	struct ViewportSpace
	{
		ViewportSpace() : x(0), y(0), width(1), height(1) {}
		ViewportSpace(int x, int y, int width, int height)
			: x(x), y(y), width(width), height(height) {}
		int x;
		int y;
		int width;
		int height;
	};

	// the logic space 
	struct LogicSpace
	{
		LogicSpace() : x(0), y(0), width(1), height(1) {}
		LogicSpace(float x, float y, float width, float height)
			: x(x), y(y), width(width), height(height) {}
		float x;
		float y;
		float width;
		float height;
	};


public:
	Tema1();
	~Tema1();

	void Init() override;
	// restart function
	void Restart();

private:

	// struct describing rectangle coordinates for collisions
	struct BoxColl {

		float minX;
		float minY;
		float maxX;
		float maxY;			
	};

	// struct describing circle coordinates for collisions
	struct CircleColl {

		float x;
		float y;
	};
	
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	// collision function - determines whether a collision takes place or not
	bool Collision(CircleColl cColl, BoxColl bcoll);


	void DrawScene(glm::mat3 visMatrix, float deltaTimeSeconds);

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

	// Sets the logic space and view space
	// logicSpace: { x, y, width, height }
	// viewSpace: { x, y, width, height }
	glm::mat3 VisualizationTransf2DUnif(const LogicSpace &logicSpace, const ViewportSpace &viewSpace);

	void SetViewportArea(const ViewportSpace &viewSpace, glm::vec3 colorColor = glm::vec3(0), bool clear = true);


protected:
	
	// bird object for rendering the bird
	Birds * birds = new Birds();
	// pipes object for rendering pipes
	Pipes * pipes = new Pipes();
	// letterNDigits object for rending "GAME OVER" message
	LettersNDigits * letNdig = new LettersNDigits();
	// background object for rendering background elements
	Background * backgr = new Background();
	
	// modelMatrices for the models
	glm::mat3 birdMatrix;
	glm::mat3 wingMatrix;
	glm::mat3 topPipeMatrix;
	glm::mat3 bottomPipeMatrix;
	glm::mat3 msgMatrix;
	glm::mat3 groundMatrix;
	glm::mat3 blockMatrix;
	glm::mat3 skyMatrix;

	// vector of tuples representing a pool of variables for rendering pipes at different scales and heights
	vector< tuple<float, float, float>> pipesVars = { 
			{1.f, 0.5f,0.f} ,
			{0.7f, 0.97f, 0.4f},
			{0.5f, 1.1f, 0.9f},
			{1.2f, 0.4f, 0.f},
			{0.4f, 1.1f, 1.f},
			{1.2f, 0.6f,0.f},
			{2.6f, 0.2f, -0.2f} };

	// array populated randomly with 6 numbers in  order to randomly render pipes at diff scales and heights
	int randomOrder[24];
	// initial Y coordinate for the bird
	float init_birdY = 2.25f;
	// current Y coordinate for the bird
	float birdY;
	
	// initial X coordinate for pipes
	float init_pipesX;
	// current X coordinates for pipes
	float pipesX_iter1, pipesX_iter2;
	
	// rotation angle
	float angle;
	// acceleration and velocity for creating gravity 
	float acceleration = 9.8f;
	float velocity;

	// bool variables representing game states
	bool started = false;
	bool gameOver = false;
	bool paused = false;
	bool running = true;
	
	// variables for logicSpace -> viewSpace transformation
	ViewportSpace viewSpace;
	LogicSpace logicSpace;
	glm::mat3 visMatrix;

	// variables for describing coordinates for collsions
	// top pipe and bottom pipe
	BoxColl upPip, botPip;
	// bird
	CircleColl birp;
	// checks if collision happened
	bool coll;

	int score, highscore;
	// variable for printing the score after the ends
	bool printedScore = false;

	// variable for determining when a point is added to the score
	float wiggleRoom;
	// variable for controlling the pipe speed, increases at certain scores
	float speedPipe;
	
	// variable used to make sure a point is not added twice due to  the wiggleRoom
	int i_pre;

	// scales factors for the block boundaries for when the game window is resized
	float scaleFactorX;
	float scaleFactorY;

};
