#include "Tema1.h"

#include <vector>
#include <iostream>
#include <algorithm>

#include <Core/Engine.h>
#include "Transform2D.h"



using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init()
{ 
	// setting up camera
	auto camera = GetSceneCamera();
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	logicSpace.x = 0;		// logic x
	logicSpace.y = 0;		// logic y
	logicSpace.width = 4;	// logic width
	logicSpace.height = 4;	// logic height
	
	// init game states
	gameOver = false;
	paused = false;
	running = true;
	started = false;
	i_pre = -1;
	coll = false;

	// init velocity and rotation agle
	velocity = 0;
	angle = 0;

	

	// init positions
	init_pipesX = 4.f;
	pipesX_iter1 = init_pipesX;
	pipesX_iter2 = init_pipesX + 8.f;
	birdY = init_birdY;

	// init pipe speed and wiggleRoom
	speedPipe = 1.5f;
	wiggleRoom = 0.03f;
	
	// populating randomly the randomOrder array
	for (int i = 0; i < 24; i++) {
		int r = rand() % 7;
		randomOrder[i] = r;

	}

	// creating bird meshes
	Mesh *body = birds->CreateBody();
	Mesh *eye = birds->CreateEye();
	Mesh *wings = birds->CreateWings();
	// adding the meshes to the game's storing container for meshes
	meshes.insert(birds->meshes_birds.begin(), birds->meshes_birds.end());

	// creating pipe meshes
	Mesh *top = pipes->CreateTopPipes("top");
	Mesh *bottom = pipes->CreateBottomPipes("bottom");
	// adding the meshes to the game's storing container for meshes
	meshes.insert(pipes->meshes_pipes.begin(), pipes->meshes_pipes.end());

	// creating message meshes
	Mesh *letters = letNdig->CreateLetters("GAMEOVER");	
	// adding the mesh to the game's storing container for meshes
	meshes.insert(letNdig->meshes_ld.begin(), letNdig->meshes_ld.end());

	// creating background meshes: ground, sky and block boundaries
	Mesh *ground = backgr->CreateGround("ground");
	Mesh *sky = backgr->CreateSky("sky");
	Mesh *block = backgr->CreateBlocks("block");
	// adding the meshes to the game's storing container for meshes
	meshes.insert(backgr->meshes_bg.begin(), backgr->meshes_bg.end());
}

// restart function
void Tema1::Restart()
{
	// reinit games states 
	gameOver = false;
	paused = false;
	running = true;
	started = false;
	i_pre = -1;
	coll = false;

	// reinit velocity and rotation agle
	velocity = 0;
	angle = 0;

	// reinit positions
	pipesX_iter1 = init_pipesX;
	pipesX_iter2 = init_pipesX + 8.f;
	birdY = init_birdY;

	// reinit pipe speed and wiggleRoom
	speedPipe = 1.5f;
	wiggleRoom = 0.03f;
	
	// populating randomly the randomOrder array
	for (int i = 0; i < 24; i++) {
		int r = rand() % 7;
		randomOrder[i] = r;

	}
	
	// resetting score
	score = 0;
	// the score was printed to console, resetting var in order to be printed again when game ends
	printedScore = false;

	Tema1::Run();

}

// uniform 2D visualization matrix (same scale factor on x and y axes somewhat)
glm::mat3 Tema1::VisualizationTransf2DUnif(const LogicSpace & logicSpace, const ViewportSpace & viewSpace)
{
	float sx, sy, tx, ty, smin;
	sx = viewSpace.width / logicSpace.width;
	sy = viewSpace.height / logicSpace.height;
	if (sx < sy) {
		scaleFactorX = viewSpace.width / logicSpace.width;
		scaleFactorY = (viewSpace.height * logicSpace.width / logicSpace.height);
		smin = sx;
	}
	else {
		scaleFactorX = (viewSpace.width * logicSpace.height / logicSpace.height);
		scaleFactorY = logicSpace.height;
		smin = sy;
	}
	
	tx = viewSpace.x - smin * logicSpace.x + (viewSpace.width - smin * logicSpace.width) / 2;
	//ty = viewSpace.y - smin * logicSpace.y + (viewSpace.height - smin * logicSpace.height) / 2;
	ty = viewSpace.y - sy * logicSpace.y;

	return glm::transpose(glm::mat3(
		smin, 0.0f, tx,
		0.0f, smin, ty,
		0.0f, 0.0f, 1.0f));
}

void Tema1::SetViewportArea(const ViewportSpace & viewSpace, glm::vec3 colorColor, bool clear)
{
	glViewport(viewSpace.x, viewSpace.y, viewSpace.width, viewSpace.height);

	glEnable(GL_SCISSOR_TEST);
	glScissor(viewSpace.x, viewSpace.y, viewSpace.width, viewSpace.height);

	// Clears the color buffer (using the previously set color) and depth buffer
	glClearColor(colorColor.r, colorColor.g, colorColor.b, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_SCISSOR_TEST);

	GetSceneCamera()->SetOrthographic((float)viewSpace.x, (float)(viewSpace.x + viewSpace.width), (float)viewSpace.y, (float)(viewSpace.y + viewSpace.height), 0.1f, 400);
	GetSceneCamera()->Update();
}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0.f, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Tema1::Update(float deltaTimeSeconds)
{
	glm::ivec2 resolution = window->GetResolution();

	// Sets the screen area where to draw 
	viewSpace = ViewportSpace(0, 0, resolution.x, resolution.y);
	SetViewportArea(viewSpace, glm::vec3(0.70196f, 0.850980f, 0.90588f), true);

	// Compute the 2D visualization matrix
	visMatrix = glm::mat3(1);
	visMatrix *= VisualizationTransf2DUnif(logicSpace, viewSpace);
	DrawScene(visMatrix, deltaTimeSeconds);

}

void Tema1::FrameEnd()
{

}

bool Tema1::Collision(CircleColl cColl, BoxColl bColl)
{
	float x = max(bColl.minX, min(cColl.x, bColl.maxX));
	float y = max(bColl.minY, min(cColl.y, bColl.maxY));
	float distance = (x - cColl.x)*(x - cColl.x) + (y - cColl.y) * (y - cColl.y);

	return distance < 0.077f * 0.37f * 0.1f * 0.37f;
}

void Tema1::DrawScene(glm::mat3 visMatrix, float deltaTimeSeconds)
{
	
	int i = 0;
	// variables for the scale and position of pipes
	float offsetY = 0;
	float pipeScaleFactorX = 1.5 , pipeTopScaleFactorY, pipeBotScaleFactorY;
	
	// rendering ground
	groundMatrix = visMatrix;
	groundMatrix *= Transform2D::Translate(-2.f, 0.0f) *
		Transform2D::Scale(1.f, 0.4f);
	RenderMesh2D(meshes["ground"], shaders["VertexColor"], groundMatrix);

	// game is running
	if (running == true) {
		/// game started
		if (started == true) {
			// determing velocity
			velocity -= acceleration * deltaTimeSeconds;

			// bird's inclination while flying
			if (angle <= -0.14f) {
				angle = -0.14f;
			} if (angle >= 0.41f)
				angle -= .15f;
			else
				angle -= .009f;

			// bird's speed
			birdY += velocity * deltaTimeSeconds *.37f;
			// pipes'speed
			pipesX_iter1 -= deltaTimeSeconds * speedPipe;
			pipesX_iter2 -= deltaTimeSeconds * speedPipe;

			// upper boundary for the bird
			if (birdY > logicSpace.height - 0.040f)
				birdY -= 0.02f;
		}
	}
	// game over
	else if(!paused) {

		// calculating variables for game over animation
		velocity -= acceleration * deltaTimeSeconds;
		if (angle >= 4.2f)
			angle = 4.2f;
		else
			angle += .185f;

		if (birdY <= -0.f)
			birdY = -0.f;
		else
			birdY -= 0.6f * abs(velocity) *  deltaTimeSeconds;
		// calculating modelMatrices for the game over animation
		birdMatrix = visMatrix;
		birdMatrix *= Transform2D::Translate(0.078f, birdY) *
			Transform2D::Scale(0.37f, 0.37f) *
			Transform2D::Translate(0.24f, 0.06f) *
			Transform2D::Rotate(angle) *
			Transform2D::Translate(-0.24f, -0.06f);
		
		wingMatrix = visMatrix;
		wingMatrix *= Transform2D::Translate(0.078f, birdY) *
			Transform2D::Scale(0.38f, 0.38f) *
			Transform2D::Translate(0.25f, 0.08f) *
			Transform2D::Rotate(angle) *
			Transform2D::Translate(-0.25f, -0.08f);
		// printing scores
		if (printedScore == false) {

			printedScore = true;
			// determining hihscore
			if (score > highscore)
				highscore = score;

			cout << "\nHIGHSCORE: " << highscore << "\n";
			cout << "SCORE: " << score << "\n";
			cout << " /////////////// \n" << " \n";

		}
		
		// rendering "GAME OVER" message
		msgMatrix = visMatrix;
		msgMatrix *= Transform2D::Translate(0.7f, 2.f) *
			Transform2D::Scale(1.f, 1.f);

		RenderMesh2D(meshes["GAMEOVER"], shaders["VertexColor"], msgMatrix);


	}

	// rendering block boundaries 

	// upper boundary
	blockMatrix = visMatrix;
	blockMatrix *= Transform2D::Translate(-2.f, logicSpace.height) *
		Transform2D::Scale(scaleFactorX, scaleFactorY);
	RenderMesh2D(meshes["block"], blockMatrix, glm::vec3(0, 0, 0.f));

	// right boundary
	blockMatrix = visMatrix;
	blockMatrix *= Transform2D::Translate(1.5f * logicSpace.width, logicSpace.y) *
		Transform2D::Scale(scaleFactorX, scaleFactorY);
	RenderMesh2D(meshes["block"], blockMatrix, glm::vec3(0, 0, 0.f));

	// left boundary
	blockMatrix = visMatrix;
	blockMatrix *= Transform2D::Translate(logicSpace.x -2.f, logicSpace.y) *
		Transform2D::Scale(-1, 1) *
		Transform2D::Translate(logicSpace.x , logicSpace.y) *
		Transform2D::Scale(scaleFactorX, scaleFactorY);
	RenderMesh2D(meshes["block"], blockMatrix, glm::vec3(0, 0, 0.f));

	
	if (!gameOver) {

		// calculating bird's inclination while flying 
		float angleBody, angleWing;
		if (velocity < -1.59f) {
			angleBody = -velocity * angle * 0.4f;
			angleWing = -velocity * angle * 0.4f;
		}
		else {
			angleBody = angle;
			angleWing = angle;
		}
		// calculating modelMatrices for the bird flying
		birdMatrix = visMatrix;
		birdMatrix *= Transform2D::Translate(0.078f, birdY) *
			Transform2D::Scale(0.37f, 0.37f) *
			Transform2D::Translate(0.24f, 0.15f) *
			Transform2D::Rotate(angleBody) *
			Transform2D::Translate(-0.24f, -0.15f);
			
		wingMatrix = visMatrix;
		wingMatrix *= Transform2D::Translate(0.078f, birdY) *
			Transform2D::Scale(0.38f, 0.38f) *
			Transform2D::Translate(0.23f, 0.15f) *
			Transform2D::Rotate(angleWing * 2.48f) *
			Transform2D::Translate(-0.23f, -0.15f);		
	}

	// rendering the bird
	RenderMesh2D(meshes["eye"], shaders["VertexColor"], birdMatrix);
	RenderMesh2D(meshes["wings"], shaders["VertexColor"], wingMatrix);
	RenderMesh2D(meshes["body"], shaders["VertexColor"], birdMatrix);

	// calculationg collision coordinates for the bird
	birp.x = 0.108f;
	birp.y = birdY + 0.2f * 0.37f;

	float pipesX_iter = pipesX_iter1;
	// rendering a set of 4 pipes 
	for (i = 0; i < 4; i++) {
		
		topPipeMatrix = glm::mat3(1) * visMatrix;
		topPipeMatrix *= Transform2D::Translate(pipesX_iter ,  2.25f)   * Transform2D::Scale(1.5, 1);

		RenderMesh2D(meshes["top"], shaders["VertexColor"], topPipeMatrix);

		bottomPipeMatrix = glm::mat3(1) * visMatrix;
		bottomPipeMatrix *= Transform2D::Translate(pipesX_iter , logicSpace.y)  * Transform2D::Scale(1.5, 0.5f);

		RenderMesh2D(meshes["bottom"], shaders["VertexColor"], bottomPipeMatrix);

		// collision coordinates for pipes
		upPip.minX = pipesX_iter;
		upPip.maxX = pipesX_iter + pipeScaleFactorX * 0.4f;

		upPip.minY = 2.25f + offsetY;
		upPip.maxY = logicSpace.height;

		botPip.minX = pipesX_iter;
		botPip.maxX = pipesX_iter + pipeScaleFactorX * 0.4f;

		botPip.minY = 0;
		botPip.maxY = 2 * 0.5f;

		// checking collision
		if (Collision(birp, upPip) == true || Collision(birp, botPip) == true) {
			coll = true;
		}
		// adding a point 
		if (upPip.maxX >= birp.x - 0.02f && upPip.maxX <= birp.x && coll == false) {
			
			score++;
			cout << "CURRENT SCORE : " << score << "\n";
		}

		// pipes are rendered at a certain distance from one another
		pipesX_iter += 2.f;
	}
	
	// resetting position for rendering the 4 pipes
	if (pipesX_iter <= -30.1f)
		pipesX_iter1 = logicSpace.width + 2.f;

	pipesX_iter = pipesX_iter2;
	
	// rendering a set of 24 pipes that have random positions and scales
	for (i = 0; i < 24; i++) {

			int idx = randomOrder[i];
		
			tuple<float, float, float> vars = pipesVars[idx];
			pipeTopScaleFactorY = get<0>(vars);
			pipeBotScaleFactorY = get<1>(vars);
			offsetY = get<2>(vars);


			topPipeMatrix = glm::mat3(1) * visMatrix;
			topPipeMatrix *= Transform2D::Translate(pipesX_iter, 2.25f + offsetY)   * Transform2D::Scale(pipeScaleFactorX, pipeTopScaleFactorY);

			RenderMesh2D(meshes["top"], shaders["VertexColor"], topPipeMatrix);

			bottomPipeMatrix = glm::mat3(1) * visMatrix;
			bottomPipeMatrix *= Transform2D::Translate(pipesX_iter, logicSpace.y)  * Transform2D::Scale(pipeScaleFactorX, pipeBotScaleFactorY);

			RenderMesh2D(meshes["bottom"], shaders["VertexColor"], bottomPipeMatrix);

			// collision coordinates for pipes
			upPip.minX = pipesX_iter;
			upPip.maxX = pipesX_iter + pipeScaleFactorX * 0.4f;

			upPip.minY = 2.25f + offsetY;
			upPip.maxY = logicSpace.height;

			botPip.minX = pipesX_iter;
			botPip.maxX = pipesX_iter + pipeScaleFactorX * 0.4f;

			botPip.minY = 0;
			botPip.maxY = 2 * pipeBotScaleFactorY;

			// checking collision
			if (Collision(birp, upPip) == true || Collision(birp, botPip) == true) {
				coll = true;
			}
			
			// adding a point
			if (upPip.maxX >= birp.x - wiggleRoom && upPip.maxX <= birp.x && coll == false && i != i_pre) { 
				i_pre = i;
				score++;
			
				cout << "CURRENT SCORE : " << score << "\n";
			}
	
			// pipes are rendered at a certain distance from one another
			pipesX_iter += 1.5f;
		}
	
	// rendering sky elements
	skyMatrix = visMatrix;
	skyMatrix *= Transform2D::Translate(-2.f, 0.0f) *
		Transform2D::Rotate(1.f) *
		Transform2D::Scale(13.f, 0.1f);

	RenderMesh2D(meshes["sky"], shaders["VertexColor"], skyMatrix);

	skyMatrix = visMatrix;
	skyMatrix *= Transform2D::Translate(-2.f, 0.0f) *
		Transform2D::Rotate(0.4f) *
		Transform2D::Scale(26.f, 0.1f);

	RenderMesh2D(meshes["sky"], shaders["VertexColor"], skyMatrix);

	// game over if collision happened
	if (coll == true) {
		gameOver = true;
	}

	// bottom boundary for the bird, game over if it reaches this height
	if (birdY <= -0.06f) {

		birdY = -0.06f;
		gameOver = true;
	}

	// game ends
	if (gameOver == true || paused == true) {
		running = false;
	}
	// resetting position for rendering the 24 pipes
	if (pipesX_iter <= -2.1f) {
		pipesX_iter2 = logicSpace.width + 2.f;

		// repopulating randomly the randomOrder array
		for (int i = 0; i < 24; i++) {
			int r = rand() % 7;
			randomOrder[i] = r;
		}

	}

	// speed increases when certain scores are hit, wiggleRoom also changes
	if (score == 28) {
		speedPipe = 2.f;
		wiggleRoom = 0.038f;
	}
	if (score == 56) {
		speedPipe = 2.5f;
		wiggleRoom = 0.038f;
	}

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{

}

void Tema1::OnKeyPress(int key, int mods)
{
	// press space to fly and start game
	if (key == GLFW_KEY_SPACE && running == true) {
		// while the bird flies, pressing space raises the bird and tilts it upwards
		if (started == true) {
			velocity = 4.2f;
			
			angle +=  .24f;
		}
		// space starts the game
		if (started == false)
			started = true;

	} 
	// press P to pause game
	else if (key == GLFW_KEY_P && gameOver == false) {

		paused = !paused;

		if (paused == false)
			running = true;
	}
	// press Enter to restart
	else if (key == GLFW_KEY_ENTER && gameOver == true) {
	
		Restart();
	}
}

void Tema1::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

// function for recalculating visualization Matrix when the window is resized, that way the game maintains its proportions
void Tema1::OnWindowResize(int width, int height)
{
	viewSpace = ViewportSpace(0, 0, width, height);
	SetViewportArea(viewSpace, glm::vec3(0.86274f, 0.94901f, 1), true);
	visMatrix = glm::mat3(1);
	visMatrix *= VisualizationTransf2DUnif(logicSpace, viewSpace);
}
