#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include<SDL2/SDL.h>
#include<cmath>
#include"Constants.h"
#include"Geometry.h"
#include"MyMath.h"

class MovingObject
{
    public:
        MovingObject(int x, int y, SDL_Renderer* renderer, vec2di &c, bool hW);
        virtual void update();
        virtual void render();
        virtual bool isDead();
        virtual void update_interp(int interpolation);

    protected:
        SDL_Renderer *gameRenderer;
        vec2di &camera;
        vec2df vel;
        vec2di pos;
        /* velocity & position information */
        vec2di interppos;
        vec2df remainder;
        vec2df interpremainder;
        //determines wether the object is influenced by gravity
        bool hasWeight;
        int interpXcnt;

    private:
};

#endif

