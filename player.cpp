//Authors: Alejandra Aranguren, Adrian Gerbaud, Edwin Onattu
// This is the implementation of the player class. 

#include "sprite.h"
#include "player.h"
#include "SDL/SDL.h"
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include<iostream>

player::player(std::string filename, int r, int g, int b, int x, int y):Sprite(8), SPRITE_DOWN(0), SPRITE_UP(1), SPRITE_RIGHT(2), SPRITE_LEFT(3), TDown(4), TUp(5), TRight(6), TLeft(7) //constructor
{
    //Initialize sprite dimensions
    height = 120;
    width = 100;

    //Initialize movement variables
    offSetY = y;
    offSetX = x;
    velocityX = 0;
    velocityY = 0;
	
    isStarting = true;

    //Initialize animation variables
    frame = 0;
    status = SPRITE_LEFT;

    //Sprite pointer
    sprite = load_image(filename,r,g,b);

    //Initialize States
    set_clips();
    
    isVisible = true;

}

void player::set_clips()
{ //sets sprite sheet clip positions
  
  //Clip the sprites
  
  //down
  states[0][0].x = 0; 
  states[0][0].y = 0;
  states[0][0].w = width;
  states[0][0].h = height;
  
  states[0][1].x = 120;
  states[0][1].y = 0;
  states[0][1].w = width;
  states[0][1].h = height;
  
  states[0][2].x = 240; 
  states[0][2].y = 0;
  states[0][2].w = width;
  states[0][2].h = height;
  
  states[0][3].x = 360;
  states[0][3].y = 0;
  states[0][3].w = width;
  states[0][3].h = height;
  
  states[0][4].x = 480; 
  states[0][4].y = 0;
  states[0][4].w = width;
  states[0][4].h = height;
  
  states[0][5].x = 600; 
  states[0][5].y = 0;
  states[0][5].w = width;
  states[0][5].h = height;
    
    
    // up
    
    states[1][0].x = 0; 
    states[1][0].y = 120;
    states[1][0].w = width;
    states[1][0].h = height;

    states[1][1].x = 120;
    states[1][1].y = 120;
    states[1][1].w = width;
    states[1][1].h = height;

    states[1][2].x = 240; 
    states[1][2].y = 120;
    states[1][2].w = width;
    states[1][2].h = height;

    states[1][3].x = 360;
    states[1][3].y = 120;
    states[1][3].w = width;
    states[1][3].h = height;

    states[1][4].x = 480; 
    states[1][4].y = 120;
    states[1][4].w = width;
    states[1][4].h = height;

    states[1][5].x = 600; 
    states[1][5].y = 120;
    states[1][5].w = width;
    states[1][5].h = height;
    
    // right

    states[2][0].x = 0; 
    states[2][0].y = 240;
    states[2][0].w = width;
    states[2][0].h = height;

    states[2][1].x = 120;
    states[2][1].y = 240;
    states[2][1].w = width;
    states[2][1].h = height;

    states[2][2].x = 240; 
    states[2][2].y = 240;
    states[2][2].w = width;
    states[2][2].h = height;

    states[2][3].x = 360;
    states[2][3].y = 240;
    states[2][3].w = width;
    states[2][3].h = height;

    states[2][4].x = 480; 
    states[2][4].y = 240;
    states[2][4].w = width;
    states[2][4].h = height;

    states[2][5].x = 600; 
    states[2][5].y = 240;
    states[2][5].w = width;
    states[2][5].h = height;

    //left

    states[3][0].x = 0; 
    states[3][0].y = 360;
    states[3][0].w = width;
    states[3][0].h = height;

    states[3][1].x = 120;
    states[3][1].y = 360;
    states[3][1].w = width;
    states[3][1].h = height;

    states[3][2].x = 240; 
    states[3][2].y = 360;
    states[3][2].w = width;
    states[3][2].h = height;

    states[3][3].x = 360;
    states[3][3].y = 360;
    states[3][3].w = width+10;
    states[3][3].h = height;

    states[3][4].x = 480; 
    states[3][4].y = 360;
    states[3][4].w = width;
    states[3][4].h = height;

    states[3][5].x = 600; 
    states[3][5].y = 360;
    states[3][5].w = width;
    states[3][5].h = height;

    //Tackle Right
    
    states[6][0].x = 0; 
    states[6][0].y = 480;
    states[6][0].w = 66;
    states[6][0].h = height;

    states[6][1].x = 247;
    states[6][1].y = 480;
    states[6][1].w = 93;
    states[6][1].h = height;

    states[6][2].x = 493; 
    states[6][2].y = 480;
    states[6][2].w = 122;
    states[6][2].h = height;
    
    states[6][3].x = 35; 
    states[6][3].y = 600;
    states[6][3].w = 149;
    states[6][3].h = height;

    states[6][4].x = 300;
    states[6][4].y = 600;
    states[6][4].w = 160;
    states[6][4].h = height;

    states[6][5].x = 575; 
    states[6][5].y = 600;
    states[6][5].w = 145;
    states[6][5].h = height;

    // Tackle Left

    states[7][0].x = 172; 
    states[7][0].y = 720;
    states[7][0].w = 69;
    states[7][0].h = height;

    states[7][1].x = 381;
    states[7][1].y = 475;
    states[7][1].w = 93;
    states[7][1].h = height;

    states[7][2].x = 586; 
    states[7][2].y = 720;
    states[7][2].w = 122;
    states[7][2].h = height;
    
    
    states[7][3].x = 56; 
    states[7][3].y = 840;
    states[7][3].w = 149;
    states[7][3].h = height;

    states[7][4].x = 259;
    states[7][4].y = 840;
    states[7][4].w = 162;
    states[7][4].h = height;

    states[7][5].x = 476; 
    states[7][5].y = 840;
    states[7][5].w = 148;
    states[7][5].h = height;

    
    // Tackle Up

    states[5][0].x = 0; 
    states[5][0].y = 960;
    states[5][0].w = width;
    states[5][0].h = 2*height;

    states[5][1].x = 120;
    states[5][1].y = 960;
    states[5][1].w = width;
    states[5][1].h = 2*height;

    states[5][2].x = 240; 
    states[5][2].y = 960;
    states[5][2].w = width;
    states[5][2].h = 2*height;

    states[5][3].x = 360;
    states[5][3].y = 960;
    states[5][3].w = width;
    states[5][3].h = 2*height;

    states[5][4].x = 480; 
    states[5][4].y = 960;
    states[5][4].w = width;
    states[5][4].h = 2*height;

    states[5][5].x = 600; 
    states[5][5].y = 960;
    states[5][5].w = width;
    states[5][5].h = 2*height;

    // Tackle Down

    states[4][0].x = 0; 
    states[4][0].y = 1200;
    states[4][0].w = width;
    states[4][0].h = 2*height;

    states[4][1].x = 120;
    states[4][1].y = 1200;
    states[4][1].w = width;
    states[4][1].h = 2*height;

    states[4][2].x = 240; 
    states[4][2].y = 1200;
    states[4][2].w = width;
    states[4][2].h = 2*height;

    states[4][3].x = 360;
    states[4][3].y = 1200;
    states[4][3].w = width;
    states[4][3].h = 2*height;

    states[4][4].x = 480; 
    states[4][4].y = 1200;
    states[4][4].w = width;
    states[4][4].h = 2*height;

    states[4][5].x = 600; 
    states[4][5].y = 1200;
    states[4][5].w = width;
    states[4][5].h = 2*height;
  
}


int player::getOffSetX()
{
  return offSetX;
}

int player::getOffSetY()
{
  return offSetY;
}

void player::setOffSetY(int num)
{
  offSetY = num;
}

void player::setOffSetX(int num)
{
  offSetX=num;
}

void player::setStarting(bool val)
{
  isStarting = val;
}

int player::collision(){return 0;} //Not used. Implemented b/c it is a pure virtual function 

void player::setIsVisible(bool vis)
{
  isVisible = vis;
} 


int player::collisioncheck(int computerX, int computerY, int sensitivity)
{ // returns 1 if something gets close enough to the player
  double xdiff = (double)computerX - ((double)offSetX);
  double ydiff =  (double)computerY - ((double)offSetY);
  double distance = sqrt(pow(xdiff,2) + pow(ydiff,2));
  
  if (distance <= sensitivity) return 1;
    else return 0;

}

void player::handle_AI(int userx, int usery)
{ // controls the automatic movement of the USC Player
double xdiff = (double)offSetX - (double)userx;
double ydiff = (double)offSetY - (double)usery;

double distance = sqrt(pow(xdiff,2) + pow(ydiff,2));
double velocity = counter;
if (velocity>20)
{
velocity=19+(.01*(double)counter);
}
double distright = sqrt(pow((xdiff+velocity),2) + pow(ydiff,2));
double distleft = sqrt(pow((xdiff-velocity),2) + pow(ydiff,2));
double distdown = sqrt(pow(xdiff,2)+pow((ydiff+velocity),2));
double distup = sqrt(pow(xdiff,2)+pow((ydiff-velocity),2));

double dist2oclock = sqrt(pow((xdiff+velocity),2)+pow((ydiff-velocity),2));
double dist5oclock = sqrt(pow((xdiff+velocity),2)+pow((ydiff+velocity),2));
double dist8oclock =sqrt(pow((xdiff-velocity),2)+pow((ydiff+velocity),2));
double dist11oclock = sqrt(pow((xdiff-velocity),2)+pow((ydiff-velocity),2));

int direction = 4;

 if ((counter % 20) ==1) 
   {	
     direction = (rand() % 8 +1); // does random move sometimes, instead of picking the move that will move it closest
   }
 else
   {
     if ((distright <=distance) && (distright<=distleft) && (distright <=distdown) && (distright <=distup) && (distright <=dist2oclock) && (distright <=dist5oclock) && (distright <=dist8oclock) && (distright <=dist11oclock))
       {
	 direction = 4;
       }
     else if ((distleft <=distance) && (distleft<=distright) && (distleft <=distdown) && (distleft <=distup)&& (distleft <=dist2oclock) && (distleft <=dist5oclock) && (distleft <=dist8oclock) && (distleft <=dist11oclock))
       {
	 direction = 3;
       }
     else if((distdown <=distance) && (distdown<=distleft) && (distdown <=distright) && (distdown <=distup)&& (distdown <=dist2oclock) && (distdown <=dist5oclock) && (distdown <=dist8oclock) && (distdown <=dist11oclock))
       {
	 direction = 2;
       }
     else if ((distup <=distance) && (distup<=distleft) && (distup <=distdown) && (distup <=distright)&& (distup <=dist2oclock) && (distup <=dist5oclock) && (distup <=dist8oclock) && (distup <=dist11oclock))
       {
	 direction = 1;
       }
     else if ((dist2oclock <=distance) && (dist2oclock<=distleft) && (dist2oclock <=distdown) && (dist2oclock <=distright)&& (dist2oclock <=distup) && (dist2oclock <=dist5oclock) && (dist2oclock <=dist8oclock) && (dist2oclock <=dist11oclock))
       {
	 direction = 5;
       }
     else if ((dist5oclock <=distance) && (dist5oclock<=distleft) && (dist5oclock <=distdown) && (dist5oclock <=distright)&& (dist5oclock <=dist2oclock) && (dist5oclock <=distup) && (dist5oclock <=dist8oclock) && (dist5oclock <=dist11oclock))
       {
	 direction = 6;
       }
     else if ((dist8oclock <=distance) && (dist8oclock<=distleft) && (dist8oclock <=distdown) && (dist8oclock <=distright)&& (dist8oclock <=dist2oclock) && (dist8oclock <=dist5oclock) && (dist8oclock <=distup) && (dist8oclock <=dist11oclock))
       {
	 direction = 7;
       }
     else if ((dist11oclock <=distance) && (dist11oclock<=distleft) && (dist11oclock <=distdown) && (dist11oclock <=distright)&& (dist11oclock <=dist2oclock) && (dist11oclock <=dist5oclock) && (dist11oclock <=dist8oclock) && (dist11oclock <=distup))
       {
	 direction = 8;
       }
     
   }
 
 switch(direction)
   {
   case 1: velocityY -= velocity; break; // up
   case 2: velocityY  += velocity; break; // down
   case 3: velocityX -= velocity; break; // left
   case 4: velocityX  += velocity; break; // right
   case 5: 
     {
       velocityY -= velocity; 
       velocityX += velocity; 
       break;// 2 o' clock
     }
   case 6:
     {
       velocityY += velocity; 
       velocityX += velocity; 
       break;// 5 o' clock
     }
   case 7: 
     {
       velocityY += velocity; 
       velocityX -= velocity; 
       break;// 8 o'clock
     }
   case 8: 
     {
       velocityY -= velocity;
       velocityX -= velocity; 
       break;// 11 o'clock
     }
   }
 
}

void player::handle_events(SDL_Event &event)
{
  int velocity = 24;
  
  //If a key was pressed
  if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
      switch( event.key.keysym.sym )
        {
	case SDLK_UP: velocityY -= velocity; break;
	case SDLK_DOWN: velocityY += velocity; break;
	case SDLK_LEFT: velocityX -= velocity; break;
	case SDLK_RIGHT:velocityX  += velocity; break;
        }
    }
  
  //If a key was released
  else if( event.type == SDL_KEYUP )
    {
      //Adjust the velocity
      switch( event.key.keysym.sym )
	{
	case SDLK_UP: velocityY += velocity; break;
	case SDLK_DOWN: velocityY -= velocity; break;
	case SDLK_LEFT: velocityX += velocity; break;
	case SDLK_RIGHT: velocityX -= velocity; break;
	}
    }
  
}

void player::handle_AIadjust()
{
  // reset velocities

	velocityX=0;
	velocityY=0;
}

void player::move()
{
  offSetX += velocityX;
  
  // Check boundary conditions
  if( (offSetX < 0) || ( offSetX + width > SCREEN_WIDTH ) )
    {
      offSetX -= velocityX;
    }  
  
  offSetY += velocityY;
  
  // Check boundary conditions
  if( ( offSetY < 0 ) || ( offSetY + height > SCREEN_HEIGHT ) )
    {
      offSetY -= velocityY;
    }
 
}


void player::show(SDL_Surface *screen, bool tackle, bool fall) // if i dont  want it to be able to tackle, forced a false
{

  if(isVisible)
    {
      if(velocityY > 0)
	{
	  if (tackle) status = TDown;	  
	  else status = SPRITE_DOWN;
	  
	  frame++;
	}
      
      else if(velocityY < 0 )
	{
	  
	  if (tackle) status = TUp; 
	  else status = SPRITE_UP;
	  frame++;
	}
  
      else if(velocityX > 0)
	{
	  if (tackle) status = TRight;
	   
	  else status = SPRITE_RIGHT;
	  frame++;
	}
  
      else if(velocityX < 0)
	{
        

	  if (tackle) status = TLeft;
	  else status = SPRITE_LEFT;
	  frame++;
	}
      
      // Reset if more thn 5

      if(frame>5)
	{ 
	  frame=0;
	}



      // Apply the surface depending on state
      
      if( status == SPRITE_DOWN )
	{

	  apply_surface(sprite, screen, &states[0][frame] ); 
	}
      
      else if( status == SPRITE_UP )
	{ 
	  apply_surface(sprite, screen, &states[1][frame] ); 
	}
      
      else if( status == SPRITE_RIGHT )
	{
	  apply_surface(sprite, screen, &states[2][frame] );
	}
      
      else if( status == SPRITE_LEFT)
	{ 
	  apply_surface(sprite, screen, &states[3][frame] );
	}

      else if ( status == TDown)
	{
	  apply_surface(sprite,screen, &states[4][frame]);
	}
      else if( status == TUp)
	{ 
	  apply_surface(sprite, screen, &states[5][frame] );
	}
      
      else if( status == TRight)
	{ 
	  apply_surface(sprite, screen, &states[6][frame] );
	}

      else if( status == TLeft)
	{ 
	  apply_surface(sprite, screen, &states[7][frame] );
	}
     
      
    }
} 


int player::getStatus()
{ //returns number that represents current state
  return status;
}

void player:: setStatus(int num)
{//sets to a particular status
  status = num;
}

void player:: setFrame(int num)
{//sets frame
  frame = num;
}
