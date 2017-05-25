#include "Orion.h"


int main(int argc, char **argv){

	//Options//
	int FPS = 60;
	bool fullScreen = false;
	bool debugMode = false;
	bool keylogger = false;

	int screenWidth = 1024;
	int screenHeight = 576;

	
	if (checkOptions(&FPS, &fullScreen, &debugMode, &keylogger)){

		if (fullScreen){

			//Windows//

			Display* disp = XOpenDisplay(NULL);
			Screen*  scrn = DefaultScreenOfDisplay(disp);
			screenHeight = scrn->height;
			screenWidth  = scrn->width;


		}
		else{



		}

	}
	else{

		FPS = 60;

	}

	if(debugMode == false && keylogger == false){

		loop(FPS, screenWidth, screenHeight, fullScreen);

	}
	else if(debugMode == false && keylogger == true){

		//loopWrite(FPS, screenWidth, screenHeight, fullScreen);

	}


	return 0;
}
