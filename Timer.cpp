// Author: Adrian A. Gerbaud H., Alejandra Aranguren, Edwin Onattu
// This is the implementation of the Timer class file

#include"Timer.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

Timer::Timer()
{
  //Initialize the variables
  startTicks = 0;
  pausedTicks = 0;
  paused = false;
  started = false;
}

void Timer::start()
{
  //Start counting
  started = true;
  paused = false;
  
  //Get the current clock time
  startTicks = SDL_GetTicks();
}

void Timer::stop()
{
  //Stop counting
  started = false;
  paused = false;
}

void Timer::pause()
{
  if( ( started == true ) && ( paused == false ) )
    {
 
      paused = true;
      
      pausedTicks = SDL_GetTicks() - startTicks;
      // Time will be the current time minus what was previously calculated
    }
}

void Timer::unpause()
{
  if( paused == true )
    {
      paused = false; // unpause
      startTicks = SDL_GetTicks() - pausedTicks; //Reset
      pausedTicks = 0;
    }
}

int Timer::get_ticks()
{
  if( started == true )
    {
      if( paused == true )
        {
	  return pausedTicks; // Just return pausedTicks
        }
      else
        {
	  return SDL_GetTicks() - startTicks; //Get difference
        }
    }
  
  //If the timer isn't running
  return 0;
}

bool Timer::is_started()
{
  return started;
}

bool Timer::is_paused()
{
  return paused;
}
