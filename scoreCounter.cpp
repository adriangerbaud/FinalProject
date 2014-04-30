//Authors: Adrian Gerbaud, Jandra Aranguren, Edwin Onattu
//Implementation of the scoreCounter class

#include "sprite.h"
#include "scoreCounter.h"
#include "SDL/SDL.h"
#include <vector>
#include <string>
#include <math.h>


scoreCounter::scoreCounter(std::string filename, int r, int g, int b):Sprite(1), COUNT(0)
{ 
  //constructor
 
  isStarted = false;
  score = 0;
  hasCollided = false;
  title = true;
  
  //Initialize animation variables
  frame = 0;
  status = COUNT;
  
  //Sprite pointer
  sprite = load_image(filename,r,g,b);
  
  set_clips();
}

void scoreCounter::set_clips()
{
  //sets sprite sheet position clips
  //Clip the sprites
  states[0][1].x = 360; //0
  states[0][1].y = 1530;
  states[0][1].w = 24;
  states[0][1].h = 30;
  
  states[0][2].x = 384; //1
  states[0][2].y = 1530;
  states[0][2].w = 20;
  states[0][2].h = 30;
  
  states[0][3].x = 408; //2
  states[0][3].y = 1530;
  states[0][3].w = 24;
  states[0][3].h = 30;
  
  states[0][4].x = 432; //3
  states[0][4].y = 1530;
  states[0][4].w = 23;
  states[0][4].h = 30;
  
  states[0][5].x = 456; //4
  states[0][5].y = 1530;
  states[0][5].w = 26;
  states[0][5].h = 30;
  
  states[0][6].x = 480; //5
  states[0][6].y = 1530;
  states[0][6].w = 25;
  states[0][6].h = 30;
  
  states[0][7].x = 504; //6
  states[0][7].y = 1530;
  states[0][7].w = 26;
  states[0][7].h = 30;
  
  states[0][8].x = 528; //7
  states[0][8].y = 1530;
  states[0][8].w = 26;
  states[0][8].h = 30;
  
  states[0][9].x = 552; //8
  states[0][9].y = 1530;
  states[0][9].w = 26;
  states[0][9].h = 30;
  
  states[0][0].x = 576; //9
  states[0][0].y = 1530;
  states[0][0].w = 26;
  states[0][0].h = 30;
}

int scoreCounter::getOffSetX()
{
  return offSetX;
}

int scoreCounter::getOffSetY()
{
  return offSetY;
}

int scoreCounter::collision(){return 0;} //Not used. Virtual function from inheritnace

void scoreCounter::apply_surface(int x, int y,SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
  //applies new surface
  //Holds offsets
  SDL_Rect shift;
  
  //Get offsets
  shift.x = x;
  shift.y = y;
  
  //Blit
  SDL_BlitSurface(source, clip, destination, &shift);
}

void scoreCounter::move(){} //Not used. Virtual function from inheritance

void scoreCounter::setScore(int num)
{
  score = num;
}

bool scoreCounter::getTitle()
{ 
  return title;
}

void scoreCounter::setTitle(bool val)
{
  title = val;
}


void scoreCounter::show(SDL_Surface *screen, bool, bool)
{ 
  //Shows the numbers on the top right corner of the screen
  int xPos = SCREEN_WIDTH - (28*6);
  isStarted = true;
  int digits=0;
  
  for(int i=6;i>0;i--)
    {
      frame = score / (pow(10,i-1)); //gets each individual digit
      frame = frame % 10;
      
      if (isStarted || frame!=0)
	{
	  if (title)
	    {
	      apply_surface(xPos,0,sprite, screen, &states[0][frame]);
	    } 
	  else
	    {
	      digits++;
	      xPos -= ((480-((digits+1)*28))/2)-10;
	      apply_surface(xPos,135,sprite, screen, &states[0][frame]); //displaying the appropriate position	
	      xPos += ((480-((digits+1)*28))/2)-10;
	  }
	  isStarted = true;
	}
      xPos += 28;
    }
}

int scoreCounter::collisioncheck(int,int,int){} //Not used. Included because of inheritance
