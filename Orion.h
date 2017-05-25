#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
//#include <wtypes.h>
////////////////////////////////////
#include <cmath>
#include <ctime>
#include <X11/Xlib.h>

#ifndef _UGRID
#define _UGRID
#include "lib/ugrid/uGrid/uGrid.h"
#endif

#include "lib/sdlhandlers/sdlHandlers/sdlHandlers.h"
#include "lib/timer/timer/Timer.h"

#ifndef _INPUTHANDLER
#define _INPUTHANDLER
#include "lib/inputhandler/inputHandler/inputHandler.h"
#endif

#ifndef _GAMEOBJECT
#define _GAMEOBJECT
#include "lib/gameobject/gameObject/gameObject.h"
#endif

#include "lib/loadallfiles/loadAllFiles/loadAllFiles.h"
#include "lib/cleanloop/cleanLoop/cleanLoop.h"
#include "lib/handleallstatechanges/handleAllStateChanges/handleAllStateChanges.h"
#include "lib/handleevents/handleEvents/handleEvents.h"
#include "lib/enactallstatechanges/enactAllStateChanges/enactAllStateChanges.h"
#include "lib/renderall/renderAll/renderAll.h"

///////
#define PI 3.14159265

//////////

using namespace std;

#define PIXELS_TO_METERS 1/16
#define METERS_TO_PIXELS 16

//
class background : public gameObject{

private:

	SDL_Rect frames[1];


public:


	background(int, int, int, int, string, string, string, SDL_Renderer *, uGrid * uniformGrid);

	void handleInput(SDL_Event& e);
	void handleInputDebug(inputHandler * iH);
	void handleStateChanges(vector<gameObject *> *, uGrid *);

	void enactStateChanges(vector <gameObject *> *, SDL_Renderer * renderer, uGrid *);

};

class wall : public gameObject{

private:

	SDL_Rect frames[1];


public:


	wall(int, int, int, int, string, string, string, SDL_Renderer *, uGrid * uniformGrid);

	void handleInput(SDL_Event& e);
	void handleStateChanges(vector<gameObject *> *, uGrid *);
	void enactStateChanges(vector <gameObject *> *, SDL_Renderer * renderer, uGrid *);

};

class ship : public gameObject{

private:

	double xVel;
	double yVel;
	double velocity;


	double deltaX;
	double deltaY;

	double timeFactor;

	bool leftPress;
	bool rightPress;
	bool upPress;
	bool downPress;

	SDL_Rect frames[1];



public:


	ship(int, int, int, int, string, string, string, SDL_Renderer *, uGrid * uniformGrid, double);

	void handleInput(SDL_Event& e);
	void handleInputDebug(inputHandler * iH);
	void handleStateChanges(vector<gameObject *> *, uGrid *);
	void enactStateChanges(vector<gameObject *> *, SDL_Renderer * renderer, uGrid *);
	bool exploding(uGrid * uniformGrid);

};

////
class Camera{

private:

	int x, y;
	int width, height;
	vector<hitbox> hitboxes;
	hitbox screen;

public:

	Camera(int, int, int, int);
	hitbox getScreen();

};

class frameTimeInfo{

private:

	//used with frame independent movement//
	int currentTime;
	int pastTime;
	int deltaTime;
	int tempTime;

public:

	frameTimeInfo();
	void update(Timer * t);
	int getDeltaTime();


};

struct blockState{

	bool crush;
	bool feint;
	bool moveLeft;
	bool moveRight;
	int mpf; //meters per frame//

	bool shaking;
	bool shakeLeft;
	bool shakeRight;
	int frame;



};

class block : public gameObject{

private:

	SDL_Rect frames[4];
	list<blockState> timeline;

public:


	block(int, int, int, int, string, string, string, SDL_Renderer *, uGrid * uniformGrid, double TIME);

	void handleInput(SDL_Event& e);
	void handleStateChanges(vector<gameObject *> *, uGrid *);
	void enactStateChanges(vector <gameObject *> *, SDL_Renderer * renderer, uGrid *);
	void shakeLeft();
	void shakeRight();
	void feint();
	void moveLeft();
	void moveRight();

};

class crusherCaptain{

private:

	int frames;
	bool crushFeintRed; //true == crush. false == feint//
	bool crushFeintBlue; //true == crush. false == feint//
	bool crushFeintGreen; //true == crush. false == feint//

	gameObject * blockOneLeft;
  gameObject * blockOneRight;
  gameObject * blockTwoLeft;
  gameObject * blockTwoRight;
  gameObject * blockThreeLeft;
  gameObject * blockThreeRight;

public:

	crusherCaptain(vector<gameObject *> gameObjects);

	void update();



};
//
class shipCaptain{

private:

	int frames;

	gameObject * ship;


public:

	shipCaptain(vector<gameObject *> gameObjects);

	void update();



};

void renderAll(vector<gameObject *> gameObjects, SDL_Renderer * renderer);
int loop(int FPS, int screenWidth, int screenHeight, bool fullScreen);
int loopWrite(int FPS, int screenWidth, int screenHeight, bool fullScreen);
