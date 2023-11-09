#pragma once
#include <string>
#include <fstream>
#include <SDL.h>
#include <filesystem>
class CollisionCheck
{
	private:
		bool colliding;
		SDL_Rect dstCollisionRect;

	public:
        bool collisionCheck(SDL_Rect objectRect, SDL_Rect targetRect, int offsetx, int offsety) {
            
            if (objectRect.y + objectRect.h + offsety > targetRect.y && objectRect.y < targetRect.y + targetRect.h) {
                colliding = true;
                return colliding;
            }

           
            if (objectRect.x + objectRect.w + offsetx > targetRect.x && objectRect.x < targetRect.x + targetRect.w) {
                colliding = true;
                return colliding;
            }

            colliding = false; 
            return colliding;
        }


	


};

