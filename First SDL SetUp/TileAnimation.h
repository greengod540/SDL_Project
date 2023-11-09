#pragma once
#include <string>
#include <fstream>
#include <SDL.h>
#include <filesystem>
class TileAnimation
{
public:
    struct Rects {
        SDL_Rect srcRect;
        SDL_Rect dstRect;
        int xMargin;
        int yMargin;
    };

private:
    Rects rect;
    int frame = 0; 
    int row = 0;
    

public:
    Rects getFrames(int framesToPlay, std::string configFilePath, int row1) {
        std::filesystem::path path = configFilePath;

        SDL_Rect srcRect1{ 0, 0, 0, 0 };
        SDL_Rect dstRect1{ 0, 0, 0, 0 };
        SDL_Rect imageValues;

        std::string imgName, temp;
        std::fstream stream;

        stream.open(path); // open the file
        stream >> temp >> imgName; // read image name
        stream >> temp >> dstRect1.x >> dstRect1.y >> dstRect1.w >> dstRect1.h;
        stream >> temp >> srcRect1.x >> srcRect1.y >> srcRect1.w >> srcRect1.h; // read the x, y, w, h coordinates
        stream >> temp >> imageValues.x >> imageValues.y >> imageValues.w >> imageValues.h;
        stream.close();

        int xMargin = imageValues.x / imageValues.h;
        int yMargin = imageValues.y / imageValues.w;

       


        

        rect.dstRect = dstRect1;
        rect.srcRect = srcRect1;
        rect.xMargin = xMargin;
        rect.yMargin = yMargin;
        
        

        
        rect.srcRect.x = rect.xMargin * frame;
        rect.srcRect.y = rect.yMargin * row1;

        return rect;
    }

    void UpdateFrame(std::string configFilePath, int framesToPlay) {
       
        frame++;
        if (frame >= framesToPlay) {
            frame = 0;
        }
        
    }

    SDL_Rect returnSrcRect(int framesToPlay, bool repeat, std::string configFilePath, int row1) {
        rect = getFrames(framesToPlay, configFilePath, row1);

        return rect.srcRect;
    }

    Rects getCurrentFrame() {
        return rect;
    }
};


