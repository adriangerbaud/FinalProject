//Authors: Adrian A. Gerbaud H., Edwin Onattu, Alejandra Aranguren
/// This is the header file for the Background class, which handles our field background.

#include "SDL/SDL.h"
using namespace std;

class Background
{
  
 public: 
  Background(const char *, SDL_Surface *); //takes name of background image in current directory
  void show(SDL_Surface *); //Puts up for display
 private:
  
  SDL_Surface *picture; //pointer to the image
};
