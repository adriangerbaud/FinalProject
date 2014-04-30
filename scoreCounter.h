//Adrian Gerbaud, Jandra Aranguren, Edwin Onattu
//This is the header file for the scoreCounter class. 

#include "SDL/SDL.h"
#include "sprite.h"
#include <vector>
#include <string>

#ifndef SCORE_H
#define SCORE_H

class scoreCounter : public Sprite{
 public:
  scoreCounter(std::string,int,int,int);
  void apply_surface(int,int,SDL_Surface *,SDL_Surface *,SDL_Rect *); //Puts the numbers onto the screen
  virtual void move(); //Not used. Only included because of inheritance
  virtual void show(SDL_Surface *,bool,bool); //Display the numbers
  virtual void set_clips(); //Gets number from sprite sheet
  virtual int getOffSetX(); //Returns x position
  virtual int getOffSetY(); //Returns y position
  virtual int collision(); //Not used. Only included because of inheritance
  virtual int collisioncheck(int,int,int); //Not used. Only included because of inheritance

  void setScore(int); //Update score value
  void setTitle(bool);
  bool getTitle();

private:
  const int COUNT;
  int score;
  bool title;
  bool isStarted; 
};

#endif
