//Authors: Adrian Gerbaud, Jandra Aranguren, Edwin Onattu
// Puts it all together

#include "background.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "Global.h"
#include "Timer.h"
#include "player.h"
#include "sprite.h"
#include "scoreCounter.h"
#include "menuScreen.h"
#include "coin.h"
#include <ctime>
#include <cstdlib>
#include<iostream> //used mainly for debugging


int main(int argc, char* args[])
{  
  srand (time(NULL)); // seed random number generator // comment out for debugging
  
  //Initialize all SDL stuff. See Global.h for that function
  if(init() == false)
    {
      return 1;
    }
  /*--------------AUDIO----------------*/
  
  //Initialize SDL_mixer
  if(Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
      return 1;
    }
  
  // Initialize Music to be played
  Mix_Music *titlemusic = NULL;
  Mix_Chunk *practicesound = NULL;
  Mix_Chunk *crowd = NULL;
  Mix_Chunk *crazytrain = NULL;
  Mix_Chunk *boom = NULL;
  Mix_Chunk *hit = NULL;
  Mix_Chunk *coin = NULL;
  
  // Set Quit flags
  bool quit = false;
  bool start = false;
  
  //Loading the music
  titlemusic = Mix_LoadMUS("Title1.wav");
  practicesound = Mix_LoadWAV("practice1.wav");
  crowd = Mix_LoadWAV("crowd1.wav");
  crazytrain = Mix_LoadWAV("crazytrain1.wav");
  boom = Mix_LoadWAV("boom.wav");
  hit = Mix_LoadWAV("hit1.wav");
  coin = Mix_LoadWAV("coin.wav");
  
  //If there was a problem loading the sound effects
  if( ( practicesound == NULL ) || ( crazytrain == NULL )||( crowd == NULL ) || (boom==NULL)|| (hit==NULL)) 
    { 
      return 1; 
    } 
  
  // If there was a problem loading the music
  
  if (titlemusic == NULL)
    {
      return 1;
    }
  
  
  /* ----------Initialize Variables------------ */
  
  vector<Sprite*> obstacles; // This will hold coins. Can be easily expanidble to hold other objects (i.e cones, powerups, etc...)
  
  // Player
  player playerND("ND_Player.bmp", 255, 255, 255, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
  player playerUSC("USC_Player.bmp", 255, 255, 255,0 ,0);
  
  //Timer
  Timer fps; 
  
  //The background
  Background background("background.bmp",screen);
  background.show(screen);
  
  // Menu
  MenuScreen menu("Welcome.bmp", 255,255,0);
  
  // ScoreCounter
  scoreCounter scoreCount("ND_Player.bmp",255,255,255);
  int score = 0;
  int soundCounter = 0;
  
  playerUSC.counter = 1;
  bool tackle = false;
  bool fall = false;

  /*---------------Begin Game---------------*/  
  
  while(quit == false)
    {
      while(start == false)
	{
	  //If the user has Xed out the window
	  if(event.type == SDL_QUIT)
	    {
	      //Quit the program
	      return 1;
	    }
	  
	  //If music not playing yet
	  if (Mix_PlayingMusic() == 0 && soundCounter==0)
	    {
	      //Play music
	      if(Mix_PlayMusic(titlemusic,-1) == -1)
		{
		  return 1;
		}
	      
	    }
	  
	    soundCounter++;
	    
	    
	    Timer mps; // Caps frame rate
	    mps.start();
	    scoreCount.setTitle(false);
	    
	    while(SDL_PollEvent(&event))
	      {
		
		start=menu.handle_event(event);
		if(event.type == SDL_KEYDOWN){
		  switch(event.key.keysym.sym){
		  case SDLK_s:
		    {
		      //If the music is paused
		      if( Mix_PausedMusic() == 1 ) 
			{ 
			  //Resume the music 
			  Mix_ResumeMusic(); 
			} 
		      //If the music is playing 
		      else 
			{ 
			  //Pause the music 
			  Mix_PauseMusic(); 
			}
		    }
		    break; // break once the 's' has been pressed
		  }
		}
	   	
	      }
	    
	    menu.show(screen,false, false); //show menu
	    SDL_Flip(screen); //update screen
	    
	    // cap frame rate
	    if (mps.get_ticks() < 1000/ FRAMES_PER_SECOND)
	      {
		SDL_Delay( ( 1000/FRAMES_PER_SECOND) - mps.get_ticks() );
	      }
	    
	    if(score > 0) // if the score is > 0, set it to zero and make players visible.
	      {
		score = 0;	
		playerND.setIsVisible(true);
		playerUSC.setIsVisible(true);	
	      }
	    
	    playerND.setStarting(true);
	    playerUSC.setStarting(true);
	    
	}
      
      // BEGIN GAMEPLAY
      
      Mix_HaltMusic();
      
      scoreCount.setTitle(true);
      menu.setHasPlayed(true);
      fps.start();
      
      //If score is '10' ie. game just started 
      if( score ==0 ) 
	{ 
	  Mix_HaltChannel( 4);
	  //Play the crowd and practice sound effect 
	  if( Mix_PlayChannel( 1, practicesound, 1 ) == -1 ) 
	    { 
	      return 1; 
	    } 
	  if( Mix_PlayChannel( 2, crowd, 1 ) == -1 ) 
	    { 
	      return 1; 
	    } 
	  if( Mix_PlayChannel( 3, crazytrain, 1 ) == -1 ) 
	    { 
	      return 1; 
	    } 
	}
      
      //While there's events to handle
      while(SDL_PollEvent(&event))
	  {  
	    playerUSC.counter++;
	    playerND.handle_events(event);
	    
	    //If the user has Xed out the window
	    if(event.type == SDL_QUIT)
	      {
		//Quit the program
		quit = true;
	      }
	  }
      
      int spawnCoin = rand()%1000 + 1;
      
      if(spawnCoin < 35) // spawn coins some of the time. (35/1000 of the time)
	{
	  int randX= (rand()%900) + 100;
	  int randY= (rand()%650) + 100;
	    
	  Coin* money = new Coin("coins.bmp", 48,120,128, randX, randY); //create coin in heap
	  obstacles.push_back(money); // place it in vector
	  
	}
      
	for(int i=0; i<obstacles.size(); i++)
	  {
	    int collide = playerND.collisioncheck(obstacles.at(i)->getOffSetX(), obstacles.at(i)->getOffSetY(), 75, 15,16); 
	    // collide = 1 if obstacle is close enough
	    if(collide == 1)
	      
	    {
	      obstacles.at(i)->collision(); // change necessary values
	      score = score + 100;
	      Mix_PlayChannel(-1,coin,0);
	      collide = 0;
	      
	    }
	    
	    
	  }
	
	
	playerUSC.handle_AI(playerND.getOffSetX(),playerND.getOffSetY()); // Activate USC Player automatic movement
	
	

	tackle = playerUSC.collisioncheck(playerND.getOffSetX(),playerND.getOffSetY(), 160,120,120); // will force a tacke
	fall = playerUSC.collisioncheck(playerND.getOffSetX(), playerND.getOffSetY(),90,120,120); // will end a game
	
	playerND.move();
	playerUSC.move();
	
	score += 7; // increment score and set it
	scoreCount.setScore(score);
	
	// Call show functions
	
	background.show(screen);
	for(int i = 0; i<obstacles.size(); i++) 
	  {
	    obstacles.at(i)->show(screen, false, false);
	  }
	
	playerND.show(screen, false, fall); // nd will never tackle
	playerUSC.show(screen, tackle, false); // usc will never fall
	
	scoreCount.show(screen, false, false);
	
	playerUSC.handle_AIadjust();
      
	//Update the screen
        SDL_Flip(screen);	
	
	//Cap the frame rate
        if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
	  {
	    SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
	  }
	
	
	// free obstacles if they have been collided with
	for(int i =0; i < obstacles.size(); i++)
	  {
	    if (obstacles.at(i)->getHasCollided())
	      {
		delete obstacles.at(i);
		obstacles.erase(obstacles.begin()+i);
		i--;
	      }
	   
	  }
	

	if(fall == true)
	  {
	    // Reset values for replay
	    
	    Mix_HaltChannel( 1);
	    Mix_HaltChannel(3);
	    if( Mix_PlayChannel( 4, boom, 1 ) == -1 ) 
	      { 
		return 1; 
	      } 
	    if( Mix_PlayChannel( 5, hit, 0 ) == -1 ) 
	      { 
		return 1; 
	      } 
	    start = false;
	    score = 0;
	    tackle = false;
	    fall = false;
	    playerND.setOffSetX(SCREEN_WIDTH/2);
	    playerND.setOffSetY(SCREEN_HEIGHT/2);
	    playerUSC.counter = 1;
	    playerUSC.setOffSetX(0);
	    playerUSC.setOffSetY(0);
	    playerUSC.handle_AIadjust();
	    playerND.handle_AIadjust();

	    // clear vector
	    for(int j=0; j<obstacles.size(); j++)
	      { //deletes all obstacles
		delete obstacles.at(j);
		obstacles.erase(obstacles.begin()+j);
		j--;
		
		
	      }
	
	  }
	
	
      }
    //Clean up
    //Free the sound effects 
    Mix_FreeChunk( practicesound ); 
    Mix_FreeChunk( crowd ); 
    Mix_FreeChunk( boom ); 
    Mix_FreeChunk( crazytrain );
    Mix_FreeMusic( titlemusic );
    Mix_FreeChunk( coin );
    Mix_CloseAudio(); 
    
    SDL_Quit();
    
    return 0;
    
    
}
      
