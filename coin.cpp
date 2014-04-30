//Authors: Adrian Gerbaud, Jandra Aranguren, Edwin Onattu
//This is the implementation of the coin class.

#include<cmath>
#include "sprite.h"
#include "coin.h"
#include "SDL/SDL.h"
#include <vector>
#include <string>
#include <iostream>

Coin::Coin(std::string filename, int r, int g, int b,int randX,int randY):Sprite(2), SPIN(0), SCORE(1)
{
  hasCollided = false;
  
  //Initialize movement variables
  offSetY = randY;
  offSetX = randX;
  velocityX = 0;
  velocityY = 0;
  
  //Initialize variables
  frame = 0;
  status = SPIN;
  
  //Sprite pointer
  sprite = load_image(filename,r,g,b);
  
  //Initialize States
  set_clips();
}

int Coin::getOffSetX()
{ //returns x pos
  return offSetX;
}

int Coin::getOffSetY()
{ //returns y pos
  return offSetY;
}

void Coin::set_clips(){ //sets clip location for sprite sheets
    //Clip the sprites
    states[0][0].x = 6; //spin0
    states[0][0].y = 3;
    states[0][0].w = 14;
    states[0][0].h = 16;

    states[0][1].x = 23; //spin1
    states[0][1].y = 3;
    states[0][1].w = 12;
    states[0][1].h = 16;

    states[0][2].x = 38; //spin2
    states[0][2].y = 3;
    states[0][2].w = 11;
    states[0][2].h = 16;

    states[0][3].x = 52; //spin3
    states[0][3].y = 3;
    states[0][3].w = 9;
    states[0][3].h = 16;
	
    states[0][4].x = 65; //spin4
    states[0][4].y = 3;
    states[0][4].w = 4;
    states[0][4].h = 16;

    states[0][5].x = 73; //spin5
    states[0][5].y = 3;
    states[0][5].w = 9;
    states[0][5].h = 16;

    states[0][6].x = 85; //spin6
    states[0][6].y = 3;
    states[0][6].w = 11;
    states[0][6].h = 16;

    states[0][7].x = 99; //spin7
    states[0][7].y = 3;
    states[0][7].w = 12;
    states[0][7].h = 16;

    states[0][8].x = 114; //spin8
    states[0][8].y = 3;
    states[0][8].w = 14;
    states[0][8].h = 16;
	
    states[0][9].x = 130; //spin9
    states[0][9].y = 3;
    states[0][9].w = 16;
    states[0][9].h = 16;

    states[1][0].x = 153; //points0
    states[1][0].y = 7;
    states[1][0].w = 14;
    states[1][0].h = 8;
 
}

int Coin::collision()
{ 
  // set variables accordingly if a collision occurs

  status = SCORE; //switch to show score sprites instead of coin
  hasCollided = true; //set collided to true
  return 2; //collision was with a coin
}


void Coin::move(){} // Not used. Must be included as it is a pure virtual function


void Coin::show(SDL_Surface *screen,bool,bool)
{ //rotates between sprite images to show animation
	if (status == SCORE)
	  {
	    frame=0;
	    apply_surface(sprite, screen, &states[1][frame]); //display score sprite
	  }
	
	if (status == SPIN){ //if still in coin
	  if (frame < 9)
	    {
	      frame++; //swap between sprites	
	    }
	  
	  else
	    {
	      frame = 0; //return to first sprite when reach last
	    }
	  
	  apply_surface(sprite, screen, &states[0][frame]); //display sprite
	}
}

int Coin::collisioncheck(int computerX, int computerY, int sensitivity,int,int)
{
    double xdiff = (double)computerX - (double)offSetX;
    double ydiff =  (double)computerY - (double)offSetY;
    double distance = sqrt(pow(xdiff,2) + pow(ydiff,2));

    if (distance <= sensitivity) return 1;
    else return 0;

}
