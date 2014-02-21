#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include"Geometry.h"
#include"Spritesheet.h"
#include"Level.h"
#include"Constants.h"
#include"Player.h"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<vector>

class Tilemanager{
    
    public:
        
        Tilemanager(SDL_Renderer* r, Level* l, vec2di *c);
        ~Tilemanager();
        void render();
        
    private:
        //functions
        void getClipRectangle(int n);
        vec2di calculateNewOrigin();
        void drawNewChunk();
        void drawSky();
        //fields
        bool redraw;
        SDL_Renderer* gameRenderer;
        Spritesheet* spritesheet;
        SDL_Texture* levelTexture;
        SDL_Texture* skyTexture;
        Level *level;
        vec2di *camera;
        Player *player;
        /* for splitting the level into chunks to be drawn*/
        int chunkWidth;
        int chunkHeight;
        vec2di chunkOrigin;

    };
    
#endif
