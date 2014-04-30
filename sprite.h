// Alejandra Aranguren, Edwin Onattu, Adrian A. Gerbaud H.
// This is the header file for the Sprite class which is the abstract base class upon which most other classes are inherited

#include "SDL/SDL.h"
#include <vector>
#include <string>

#ifndef SPRITE_H
#define SPRITE_H
using namespace std;

class Sprite
{
 public:
  Sprite(int); //constructor

  virtual void move()=0; // handles the movement of the sprite
  virtual void show(SDL_Surface *, bool, bool)=0; // updates the frames of the sprite sheet shown
  virtual void set_clips()=0; //clips sprite sheet
  virtual int collision()=0; //handles collision with another object
  virtual int getOffSetX()=0; //returns x pos
  virtual int getOffSetY()=0; //returns y pos
  virtual int collisioncheck(int,int,int)=0; // returns 1 if what is specified gets too close
  
  void apply_surface(SDL_Surface *,SDL_Surface *,SDL_Rect *); //applies new surface
  SDL_Surface * load_image(std::string,int,int,int); //takes in image of sprite
  bool getHasCollided(); //returns whether object has collided with another
  SDL_Surface * sprite; //sprite surface
  
 protected:
  int frame;
  int offSetX; // x pos
  int offSetY; // y pos
  int velocityX; // horizontal speed
  int velocityY; //vertical speed
  int status; // determines the status of movement
  int height; //height of image
  int width; //width of image
  bool hasCollided; //whether object has collided with another
  vector< vector<SDL_Rect> > states; //contains states for sprite sheet clips
  
  //Screen Dimensions
  const int SCREEN_WIDTH; 
  const int SCREEN_HEIGHT; 
  const int SCREEN_BPP; 
  
  //FPS
  const int FRAMES_PER_SECOND;
  
  //Statuses
  const int SPRITE_DOWN;
  const int SPRITE_UP;
  const int SPRITE_LEFT;
  const int SPRITE_RIGHT;
  
  const int TDown;
  const int TUp;
  const int TLeft;
  const int TRight;
  
};

#endif
