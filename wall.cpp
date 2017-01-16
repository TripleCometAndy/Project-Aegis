#include "Orion.h"

wall::wall(int xCoor, int yCoor, int gWidth, int gHeight, string n, string file, string t, SDL_Renderer * renderer, uGrid * uniformGrid){



	x = xCoor;
	y = yCoor;
	width = gWidth;
	height = gHeight;



	image = NULL;

	currentClip = 0;

	name = n;
	fileName = file;
	type = t;


	hitboxes.push_back(hitbox());
	hitboxes[0].left = x;
	hitboxes[0].right = x + width;
	hitboxes[0].top = y;
	hitboxes[0].bottom = y + height;
	hitboxes[0].name = "wall";
	hitboxes[0].parentName = name;
	hitboxes[0].parentType = type;



	frames[0].x = 0;
	frames[0].y = 0;
	frames[0].w = width;
	frames[0].h = height;

	clip = &frames[currentClip];



	//uniformGrid->addReferenceNoIgnore(hitboxes[0]);
	uniformGrid->update(hitboxes);
}

void wall::handleInput(SDL_Event& e){





}

void wall::handleStateChanges(vector<gameObject *> * objects, uGrid * uniformGrid){




}

void wall::enactStateChanges(vector<gameObject *> * objects, SDL_Renderer * renderer, uGrid * uniformGrid){

	//uniformGrid->update(hitboxes);

}
