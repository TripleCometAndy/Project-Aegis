#include "Orion.h"


background::background(int xCoor, int yCoor, int gWidth, int gHeight, string n, string file, string t, SDL_Renderer * renderer, uGrid * uniformGrid){



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
	hitboxes[0].top = y - 5;
	hitboxes[0].bottom = y;
	hitboxes[0].name = "background_topWall";
	hitboxes[0].parentName = name;
	hitboxes[0].parentType = type;

	hitboxes.push_back(hitbox());
	hitboxes[1].left = x;
	hitboxes[1].right = x + 5;
	hitboxes[1].top = y;
	hitboxes[1].bottom = y + height;
	hitboxes[1].name = "background_leftWall";
	hitboxes[1].parentName = name;
	hitboxes[1].parentType = type;

	hitboxes.push_back(hitbox());
	hitboxes[2].left = x + width - 5;
	hitboxes[2].right = x + width;
	hitboxes[2].top = y;
	hitboxes[2].bottom = y + height;
	hitboxes[2].name = "background_rightWall";
	hitboxes[2].parentName = name;
	hitboxes[2].parentType = type;


	hitboxes.push_back(hitbox());
	hitboxes[3].left = x;
	hitboxes[3].right = x + width;
	hitboxes[3].top = y + height;
	hitboxes[3].bottom = y + height + 5;
	hitboxes[3].name = "background_bottomWall";
	hitboxes[3].parentName = name;
	hitboxes[3].parentType = type;

	hitboxes.push_back(hitbox());
	hitboxes[4].left = x;
	hitboxes[4].right = x + width;
	hitboxes[4].top = y;
	hitboxes[4].bottom = y + height;
	hitboxes[4].name = "background_full";
	hitboxes[4].parentName = name;
	hitboxes[4].parentType = type;


	frames[0].x = 0;
	frames[0].y = 0;
	frames[0].w = width;
	frames[0].h = height;

	clip = &frames[currentClip];

	cout << "Cat" << endl;
	hitbox c = hitboxes[0];
	uniformGrid->addReferenceNoIgnore(c);
	c = hitboxes[1];
	uniformGrid->addReferenceNoIgnore(c);
	c = hitboxes[2];
	uniformGrid->addReferenceNoIgnore(c);
	c = hitboxes[3];
	uniformGrid->addReferenceNoIgnore(c);
	c = hitboxes[4];
	uniformGrid->addReferenceNoIgnore(c);
//uniformGrid->update(hitboxes);



}

void background::handleInput(SDL_Event& e){





}

void background::handleStateChanges(vector<gameObject *> * objects, uGrid * uniformGrid){




}

void background::enactStateChanges(vector<gameObject *> * objects, SDL_Renderer * renderer, uGrid * uniformGrid){

	//uniformGrid->update(hitboxes);

}
