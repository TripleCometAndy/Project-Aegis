#include "Orion.h"

block::block(int xCoor, int yCoor, int gWidth, int gHeight, string n, string file, string t, SDL_Renderer * renderer, uGrid * uniformGrid, double TIME){

  x = xCoor;
	y = yCoor;
	width = gWidth;
	height = gHeight;

  futureX = x;
  futureY = y;

  image = NULL;

	currentClip = 0;

	name = n;
	fileName = file;
	type = t;



  if(t.compare("blockLeft") == 0){

    hitboxes.push_back(hitbox());
  	hitboxes[0].left = x;
  	hitboxes[0].right = x + width;
  	hitboxes[0].top = y;
  	hitboxes[0].bottom = y + 15;
  	hitboxes[0].name = "blockLeftTop";
  	hitboxes[0].parentName = name;
  	hitboxes[0].parentType = type;

    hitboxes.push_back(hitbox());
  	hitboxes[1].left = x;
  	hitboxes[1].right = x + width;
  	hitboxes[1].top = y + 135;
  	hitboxes[1].bottom = y + 150;
  	hitboxes[1].name = "blockLeftBottom";
  	hitboxes[1].parentName = name;
  	hitboxes[1].parentType = type;

    hitboxes.push_back(hitbox());
  	hitboxes[2].left = x;
  	hitboxes[2].right = x + width - 15;
  	hitboxes[2].top = y + 15;
  	hitboxes[2].bottom = y + 135;
  	hitboxes[2].name = "blockMiddleLeft";
  	hitboxes[2].parentName = name;
  	hitboxes[2].parentType = type;

    hitboxes.push_back(hitbox());
  	hitboxes[3].left = x + width - 15;
  	hitboxes[3].right = x + width;
  	hitboxes[3].top = y + 15;
  	hitboxes[3].bottom = y + 135;
  	hitboxes[3].name = "crushZoneLeft";
  	hitboxes[3].parentName = name;
  	hitboxes[3].parentType = type;


  }
  else if(t.compare("blockRight") == 0){

    hitboxes.push_back(hitbox());
  	hitboxes[0].left = x;
  	hitboxes[0].right = x + width;
  	hitboxes[0].top = y;
  	hitboxes[0].bottom = y + 15;
  	hitboxes[0].name = "blockRightTop";
  	hitboxes[0].parentName = name;
  	hitboxes[0].parentType = type;

    hitboxes.push_back(hitbox());
  	hitboxes[1].left = x;
  	hitboxes[1].right = x + width;
  	hitboxes[1].top = y + 135;
  	hitboxes[1].bottom = y + 150;
  	hitboxes[1].name = "blockRightBottom";
  	hitboxes[1].parentName = name;
  	hitboxes[1].parentType = type;

    hitboxes.push_back(hitbox());
  	hitboxes[2].left = x + 15;
  	hitboxes[2].right = x + width;
  	hitboxes[2].top = y + 15;
  	hitboxes[2].bottom = y + 135;
  	hitboxes[2].name = "blockMiddleRight";
  	hitboxes[2].parentName = name;
  	hitboxes[2].parentType = type;

    hitboxes.push_back(hitbox());
  	hitboxes[3].left = x;
  	hitboxes[3].right = x + 15;
  	hitboxes[3].top = y + 15;
  	hitboxes[3].bottom = y + 135;
  	hitboxes[3].name = "crushZoneRight";
  	hitboxes[3].parentName = name;
  	hitboxes[3].parentType = type;


  }
  else{

    //error//

  }





  frames[0].x = 5;
	frames[0].y = 5;
	frames[0].w = width;
	frames[0].h = height;

  frames[1].x = 5;
	frames[1].y = 165;
	frames[1].w = width;
	frames[1].h = height;

  frames[2].x = 165;
	frames[2].y = 165;
	frames[2].w = width;
	frames[2].h = height;

  frames[3].x = 165;
	frames[3].y = 5;
	frames[3].w = width;
	frames[3].h = height;

	clip = &frames[currentClip];


  hitbox c = hitboxes[0];
	uniformGrid->addReferenceNoIgnore(c);
  c = hitboxes[1];
  uniformGrid->addReferenceNoIgnore(c);
  c = hitboxes[2];
  uniformGrid->addReferenceNoIgnore(c);
  c = hitboxes[3];
  uniformGrid->addReferenceNoIgnore(c);



}

void block::shakeLeft(){

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 1;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 2;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 1;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 2;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 2;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 1;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 1;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 0;




}

void block::shakeRight(){


  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 1;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 2;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 1;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 2;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 2;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 1;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = true;
  timeline.back().frame = 1;

  timeline.push_back(blockState());
  timeline.back().shakeRight = true;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;



}

void block::feint(){

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 3;

  timeline.push_back(blockState());
  timeline.back().shakeRight = false;
  timeline.back().shakeLeft = false;
  timeline.back().frame = 0;


}

void block::moveLeft(){

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 5;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 10;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 15;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 20;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 25;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 30;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 35;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 40;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 45;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveLeft = true;
  timeline.back().mpf = 54;
  timeline.back().frame = 0;


}

void block::moveRight(){

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 5;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 10;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 15;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 20;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 25;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 30;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 35;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 40;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 45;
  timeline.back().frame = 0;

  timeline.push_back(blockState());
  timeline.back().moveRight = true;
  timeline.back().mpf = 54;
  timeline.back().frame = 0;


}

void block::handleInput(SDL_Event& e){





}

void block::handleStateChanges(vector<gameObject *> * objects, uGrid * uniformGrid){

  string * p = inputs.data();
	int numInputs = inputs.size();


	for (int i = 0 ; i < numInputs; i++){


		if ((*p).compare("CRUSH_ONE_LEFT") == 0){

      shakeLeft();
      shakeLeft();
      moveRight();
      moveLeft();

		}
    else if((*p).compare("CRUSH_ONE_RIGHT") == 0){

      shakeRight();
      shakeRight();
      moveLeft();
      moveRight();

    }
    else if((*p).compare("CRUSH_TWO_LEFT") == 0){

      shakeLeft();
      shakeLeft();

    }
    else if((*p).compare("CRUSH_TWO_RIGHT") == 0){

      shakeRight();
      shakeRight();

    }
    else if((*p).compare("CRUSH_THREE_LEFT") == 0){

      shakeLeft();
      shakeLeft();

    }
    else if((*p).compare("CRUSH_THREE_RIGHT") == 0){

      shakeRight();
      shakeRight();

    }
    else if((*p).compare("FEINT_ONE_LEFT") == 0){

      shakeLeft();
      feint();

    }
    else if((*p).compare("FEINT_TWO_LEFT") == 0){

      shakeLeft();
      feint();

    }
    else if((*p).compare("FEINT_THREE_LEFT") == 0){

      shakeLeft();
      feint();

    }
    else if((*p).compare("FEINT_ONE_RIGHT") == 0){

      shakeRight();
      feint();

    }
    else if((*p).compare("FEINT_TWO_RIGHT") == 0){

      shakeRight();
      feint();

    }
    else if((*p).compare("FEINT_THREE_RIGHT") == 0){

      shakeRight();
      feint();

    }

		p++;

	}

  if(timeline.size() > 0){

    if(timeline.front().shakeRight){

      futureX = x + 50;

    }
    else if(timeline.front().shakeLeft){

      futureX = x - 50;

    }
    else if(timeline.front().moveLeft){

      futureX = x - timeline.front().mpf;


    }
    else if(timeline.front().moveRight){

      futureX = x + timeline.front().mpf;


    }
    else{

      futureX = x;

    }
    clip = &frames[timeline.front().frame];

    timeline.pop_front();

  }


}

void block::enactStateChanges(vector<gameObject *> * objects, SDL_Renderer * renderer, uGrid * uniformGrid){

	//uniformGrid->update(hitboxes);
  move(futureX - x, futureY - y);

	uniformGrid->update(hitboxes);

}
