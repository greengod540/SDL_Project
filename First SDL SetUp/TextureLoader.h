#pragma once
#include <SDL.h>
#include <iostream>
#include <filesystem>

class TextureLoader {
public:
    SDL_Texture* CreateTexture(std::string imagePathBMP, SDL_Renderer* renderer) {
        std::string tmpImg = "img\\" + imagePathBMP;
        imagePathBMP = "img\\" + imagePathBMP;
        SDL_Surface* surface = SDL_LoadBMP(imagePathBMP.c_str()); 

        SDL_Texture* Texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (Texture == nullptr) {
            imagePathBMP = "img\\Null.bmp";
            SDL_Surface* surface1 = SDL_LoadBMP(imagePathBMP.c_str());

            SDL_Texture* Texture = SDL_CreateTextureFromSurface(renderer, surface1);
            
            SDL_FreeSurface(surface);
            return Texture;
            
            
        }
        SDL_FreeSurface(surface);
        return Texture;
    }
};
