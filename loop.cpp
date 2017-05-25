#include "Orion.h"

int loop(int FPS, int screenWidth, int screenHeight, bool fullScreen){

  bool hasController = false;

	int frameDrops = 0;
	double timeFactor = 0;

	SDL_Joystick* gGameController = NULL;

	Mix_Music * music = NULL;

	ofstream logInputs;
	remove("Inputs.txt");
  logInputs.open("Inputs.txt", std::ofstream::app);
  logInputs.put('\n');


	//this is used when regulating upper bound for frame rate.
	int TICKS_PER_FRAME = 1000 / FPS;


	//The frame rate regulator
	Timer fps;

	timeFactor = 1/(double)FPS;


	//Initialize main window and renderer
	SDL_Renderer * renderer = NULL;
	SDL_Window * window = NULL;


	//vector of pointers all game objects loaded//
	vector<gameObject *> objects;


	uGrid uniformGrid(screenWidth + 200, screenHeight + 200);


	//Initialize SDL systems//
	if (init(screenWidth, screenHeight, &window, &renderer, fullScreen, gGameController, &hasController) == false)
	{
		return 1;
	}

	////
	background b(100, 100, 1024, 576, "background_01", "images/background_test.png", "background", renderer, &uniformGrid);
	//wall leftWall(100, 100, 233, 576, "wall_01", "images/wall.png", "wall", renderer, &uniformGrid);
	//wall rightWall(891, 100, 233, 576, "wall_02", "images/wall.png", "wall", renderer, &uniformGrid);
	ship player(450, 500, 60, 56, "ship_01", "images/ship1.png", "ship", renderer, &uniformGrid, timeFactor);


	//Camera camera(0, 0, 1024, 768);

	objects.push_back(&b);

	objects.push_back(&player);

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

		handleEvents(&quit, &paused, objects);



		if (!paused){
      cout << "Test1" << endl;
			handleAllStateChanges(objects, &uniformGrid);
      cout << "Test2" << endl;

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
