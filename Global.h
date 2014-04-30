/// Author: Adrian A. Gerbaud H., Alejandra Aranguren, Edwin Onattu
// This are some functions that are used all around the program. Inluded here for ease in programming and debugging.

#ifndef GLOBAL_H
#define GLOBAL_H


#include "SDL/SDL.h"
#include <string>
#include <iostream>

//variables
const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 840;
const int SCREEN_BPP = 32;

const int FRAMES_PER_SECOND = 10;
SDL_Event event;
SDL_Surface *screen = NULL;

bool init()
{
    //Initialize all SDL subsystems
  if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
      return false;
    }
  
  //Set up the screen
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

  //If there was an error in setting up the screen
  if(screen == NULL)
    {
      return false;
    }
  
  //Set the window caption
  SDL_WM_SetCaption("Tackle Tag", NULL);
  
  //If everything initialized fine
  return true;
}

#endif
