// Authors: Jandra Arangure, Edwin Onattu, Adrian Gerbaud
// This is the header file for our coin class. It is a derived class from Sprite
#include "SDL/SDL.h"
#include "sprite.h"
#include <vector>
#include <string>

#ifndef COIN_H
#define COIN_H

class Coin: public Sprite{
  
 public:
  Coin(std::string,int,int,int,int,int); //constructor
  virtual void move(); //Not used.Taken from inheritance
  virtual void show(SDL_Surface *,bool,bool); //displays proper sprite to screen
  virtual void set_clips(); //sets sprite sheet clip positions
  virtual int getOffSetX(); //returns x position
  virtual int getOffSetY(); //returns y position
  virtual int collision(); //player collision with coin
  virtual int collisioncheck(int,int,int); // Returns 1 if player gets close enough

private:
  //States
  const int SPIN;
  const int SCORE;
};

#endif
