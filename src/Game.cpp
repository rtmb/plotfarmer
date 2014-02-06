#include"Game.h"
#include"Player.h"
#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{

    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_TIMER ) !=0)
     {
         cout << "SDL Initialization error. " << SDL_GetError() << endl;
         exit(-1); 
     }

    SDL_Window* gameWindow = SDL_CreateWindow(
        "plotfarmer",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0);
    if (gameWindow==NULL)
    {
         cout << "SDL Window Initialization error. " << SDL_GetError() << endl;
         exit(-1); 
    }

    SDL_Renderer* gameRenderer = SDL_CreateRenderer(
        gameWindow,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if (gameRenderer==NULL)
    {
         cout << "SDL Renderer Initialization error. " << SDL_GetError() 
                << endl;
         exit(-1); 
    }
   
    if (IMG_INIT_PNG != IMG_Init(IMG_INIT_PNG))
    {
         cout << "SDL Renderer Initialization error. " << SDL_GetError() 
                << endl;
         exit(-1); 
    }
   
    if (IMG_Init(IMG_INIT_PNG)!=IMG_INIT_PNG)
    {
         cout << "SDL Image Initialization Error. "  << endl;
         exit(-1); 
    }

    Game* plotfarmerGame = new Game(
        gameWindow,
        gameRenderer
    );
        
    plotfarmerGame->gameMainLoop();
    
    SDL_Quit();
}


Game::Game(SDL_Window* w, SDL_Renderer* r)
{
    gameWindow  =  w;
    gameRenderer = r;     
    player = new Player(gameRenderer);
}

void Game::gameMainLoop()
{
    
    bool gameOver = false;
    SDL_Event e;
    long lastTick = SDL_GetTicks();
    long thisTick;
    while (!gameOver)
    {
        thisTick = SDL_GetTicks();
        while(SDL_PollEvent(&e)!=0)
        {
            if(e.type == SDL_QUIT)
            {
            gameOver = true;
            }
        }
        update(thisTick-lastTick);
        render();
        lastTick = thisTick;
    }
            
}

void Game::update(long dt){
    player->update(dt);
    }

void Game::render(){
    SDL_SetRenderDrawColor(gameRenderer, 0, 0, 0, 255);
    SDL_RenderClear(gameRenderer);
   
    player->render();

    SDL_RenderPresent(gameRenderer);
    }