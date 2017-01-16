#include "Orion.h"

crusherCaptain::crusherCaptain(vector<gameObject *> gameObjects){

  frames = 0;

  int size = gameObjects.size();
  string name;
  gameObject ** p = gameObjects.data();

  for(int i = 0; i < size; i++){

    name = (*p)->getName();

    if(!(name.compare("blockOneLeft"))){

      blockOneLeft = *p;


    }
    else if(!(name.compare("blockOneRight"))){


      blockOneRight = *p;


    }
    else if(!(name.compare("blockTwoLeft"))){


      blockTwoLeft = *p;


    }
    else if(!(name.compare("blockTwoRight"))){


      blockTwoRight = *p;


    }
    else if(!(name.compare("blockThreeLeft"))){


      blockThreeLeft = *p;


    }
    else if(!(name.compare("blockThreeRight"))){


      blockThreeRight = *p;


    }
    else{



    }

    p++;


  }

}

void crusherCaptain::update(){

  if((frames % 550) == 0){

    if(crushFeintRed){

      blockOneLeft->addInput("CRUSH_ONE_LEFT");
      blockOneRight->addInput("CRUSH_ONE_RIGHT");
      crushFeintRed = false;
    }
    else{

      blockOneLeft->addInput("FEINT_ONE_LEFT");
      blockOneRight->addInput("FEINT_ONE_RIGHT");
      crushFeintRed = true;


    }


  }

  frames++;



}
