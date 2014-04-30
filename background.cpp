// Authors: Edwin Onattu, Adrian A. Gerbaud H. , Alejandra Aranguren
//This is the implementation file for the Background class


#include "SDL/SDL.h"
#include "background.h"
#include <iostream>
using namespace std;


void Background::show(SDL_Surface* screen)
{
  SDL_BlitSurface(picture,NULL,screen,NULL);
  
}
Background::Background(const char *image, SDL_Surface *screen){
  
  picture = SDL_LoadBMP(image); //load in the picture to be used as background
  
  if(picture==NULL){ //if image doesn't load
    cout << "Error opening image" << endl;
  }
  
}

