//Author: Adrian A. Gerbaud H., Alejandra Aranguren, Edwin Onattu
//This is the implemenation file for the Sprite class which is the abstract base class upon which most other classes are inherited

#include "sprite.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

Sprite::Sprite(int count):states(count,vector<SDL_Rect>(15)), SCREEN_WIDTH(1100),SCREEN_HEIGHT(840), SCREEN_BPP(32), FRAMES_PER_SECOND(10), SPRITE_DOWN(0), SPRITE_UP(1), SPRITE_RIGHT(2), SPRITE_LEFT(3), TDown(4), TUp(5), TRight(6), TLeft(7){} //constructor

bool Sprite::getHasCollided()
{ // returns variable that indicates if object has collided with another
  return hasCollided;
}

void Sprite::apply_surface(SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip){ //applies new surface
  //Holds offsets
  SDL_Rect shift;
  
  //Get offsets
  shift.x = offSetX;
  shift.y = offSetY;
  
  //Blit
  SDL_BlitSurface(source, clip, destination, &shift);
  
}

SDL_Surface * Sprite::load_image(std::string filename, int r, int g, int b)
{
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;
  
  //Load
  loadedImage = SDL_LoadBMP( filename.c_str() );
  
  if( loadedImage != NULL )
    {
      //Optimize for better performance
      optimizedImage = SDL_DisplayFormat( loadedImage );
      
      SDL_FreeSurface( loadedImage ); //free old one
      
      if( optimizedImage != NULL )
	{
	  SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, r, g, b ) );
	}
      
      
    }
  return optimizedImage;
 
}

 
