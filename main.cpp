#include "Orion.h"


int main(int argc, char **argv){

	bool hasController;

	int frameDrops = 0;
	double timeFactor = 0.0166;


	SDL_Joystick* gGameController = NULL;


	Mix_Music * music = NULL;


	//Options//
	int FPS = 30;
	bool fullScreen = NULL;

	int screenWidth = 1024;
	int screenHeight = 576;

	if (checkOptions(&FPS, &fullScreen)){

		if (fullScreen){

			//Windows//
			//GetDesktopResolution(screenWidth, screenHeight);


		}
		else{



		}

	}
	else{


		FPS = 60;


	}
	FPS = 60;
	//this is used when regulating upper bound for frame rate. don't worry about this//
	int TICKS_PER_FRAME = 1000 / 60;

	//frameTimeInfo timeInfo;

	//The frame rate regulator
	Timer fps;

	timeFactor = 1/(double)FPS;


	//Initialize main window and renderer

	SDL_Renderer * renderer = NULL;
	SDL_Window * window = NULL;


	//vector of pointers all game objects loaded//
	vector<gameObject *> objects;

	//vector of pointers to all active and rendered game objects//

	vector<gameObject *> activeRenderedObjects;

	//vector of pointers to all inactive game objects//

	vector<gameObject *> inactiveObjects;

	//vector of pointers to all active but obscured game objects//

	vector<gameObject *> activeObscuredObjects;

	vector<hitbox *> hitboxes;

	uGrid uniformGrid(screenWidth + 200, screenHeight + 200);


	//Initialize SDL systems//
	if (init(screenWidth, screenHeight, &window, &renderer, fullScreen, gGameController, &hasController) == false)
	{
		return 1;
	}

	//
	background b(100, 100, 1024, 576, "background_01", "images/background_test.png", "background", renderer, &uniformGrid);
	wall leftWall(100, 100, 233, 576, "wall_01", "images/wall.png", "wall", renderer, &uniformGrid);
	wall rightWall(891, 100, 233, 576, "wall_02", "images/wall.png", "wall", renderer, &uniformGrid);
	ship player(450, 500, 60, 56, "ship_01", "images/ship1.png", "ship", renderer, &uniformGrid, timeFactor);
	block firstLeft(334, 163, 150, 150, "blockOneLeft", "images/blockRedSS.png", "blockLeft", renderer, &uniformGrid, timeFactor);
	block secondLeft(334, 313, 150, 150, "blockTwoLeft", "images/blockBlueSS.png", "blockLeft", renderer, &uniformGrid, timeFactor);
	block thirdLeft(334, 463, 150, 150, "blockThreeLeft", "images/blockGreenSS.png", "blockLeft", renderer, &uniformGrid, timeFactor);
	block firstRight(741, 163, 150, 150, "blockOneRight", "images/blockRedSS.png", "blockRight", renderer, &uniformGrid, timeFactor);
	block secondRight(741, 313, 150, 150, "blockTwoRight", "images/blockBlueSS.png", "blockRight", renderer, &uniformGrid, timeFactor);
	block thirdRight(741, 463, 150, 150, "blockThreeRight", "images/blockGreenSS.png", "blockRight", renderer, &uniformGrid, timeFactor);

	Camera camera(0, 0, 1024, 768);

	objects.push_back(&b);
	objects.push_back(&leftWall);
	objects.push_back(&rightWall);
	objects.push_back(&player);
	objects.push_back(&firstLeft);
	objects.push_back(&secondLeft);
	objects.push_back(&thirdLeft);
	objects.push_back(&firstRight);
	objects.push_back(&secondRight);
	objects.push_back(&thirdRight);


	crusherCaptain cCap(objects);
	//shipCaptain sCap(objects);
	if(loadAllFiles(objects, renderer)){

		//no problems in loading files//


	}
	else{

		//there was a problem in loading files//
		return 1;


	}

	//pause flag//
	bool paused = false;

	//Quit flag//
	bool quit = false;


	while (quit == false){


		fps.start();

		cCap.update();
		//sCap.update();

		handleEvents(&quit, &paused, objects);

		if (!paused){

			handleAllStateChanges(objects, &uniformGrid);

			enactAllStateChanges(objects, renderer, &uniformGrid);

			cleanLoop(objects);

			if (Mix_PlayingMusic() == 0)
			{
				//Play the music
				Mix_PlayMusic(music, -1);
			}

			renderAll(objects, renderer);

			//If frame finished early
			int frameTicks = fps.get_ticks();
			if (frameTicks < TICKS_PER_FRAME)
			{
				//Wait remaining time
				SDL_Delay(TICKS_PER_FRAME - frameTicks);
			}
			if(frameTicks > TICKS_PER_FRAME){
				frameDrops++;
				SDL_Delay(frameTicks - TICKS_PER_FRAME);

			}


		}

	}
	//uniformGrid.printGridInfo();
	cout << "Frame Drops: " << frameDrops << endl;
	uniformGrid.destruct();
	close(objects, renderer, window);

	return 0;
}
