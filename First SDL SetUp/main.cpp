#include <SDL.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <TileAnimation.h>
#include <TextureLoader.h>
#include <CollisionCheck.h>
#include <mutex>
#include <thread>
#include <InputManager.h>
#include <map>
#undef main

int points = 0;


void improveRenderer(SDL_Window* mainWindow, SDL_Renderer* mainRenderer) {

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);

	auto desktopWidth = DM.w;
	auto desktopHeight = DM.h;


	if (SDL_SetWindowFullscreen(mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP) < 0)
	{
		std::cout << "sdl renderer improved failed" << SDL_GetError();

	}

	SDL_RenderSetLogicalSize(mainRenderer, 1920, 1080);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");





}

int main(int argc, char* argv[])
{

	TileAnimation tileAnim;
	TileAnimation tileAnim2;
	InputManager inputManager;




	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* mainWindow = SDL_CreateWindow("Caption", 0, 0, 1920, 1080, 0);

	SDL_Renderer* mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);

	//improved rendered
	
	improveRenderer(mainWindow, mainRenderer);

	std::map <std::string, int> mouseButtons;
	std::map <std::string, SDL_Scancode> keyboardButtons;

	inputManager.mapControlsMouse("left", "left");
	inputManager.mapControlsKeyBoard("a", "left");

	mouseButtons = inputManager.actionMapMouse;
	keyboardButtons = inputManager.actionMapKeyboard;
	


	TextureLoader textLoader;
	SDL_Texture* skeleton_idle = textLoader.CreateTexture("skeleton_idle.bmp", mainRenderer);
	SDL_Surface* surface = SDL_LoadBMP("hammer.bmp");
	SDL_Cursor* cursor = SDL_CreateColorCursor(surface, 0, 0);
	SDL_SetCursor(cursor);
	SDL_Texture* NeuromancerBackground = textLoader.CreateTexture("Neuromancer.bmp", mainRenderer);
	SDL_Texture* Gugug = textLoader.CreateTexture("gufguy.bmp", mainRenderer);


	//make a 3d rect vs 2019 make viking anim
	int frame = 0;

	
	int currentX = 5;
	int currentY = 5;
	int animStateY = 0;
	


	

	
	CollisionCheck colcheck;
	SDL_Rect cursorDstRect{ 0, 0, 0, 0 };
	int xMouse = 0;
	int yMouse = 0;
	bool isRunning = true;
	
	while (isRunning)
	{
		SDL_Event Event;
		

		
		cursorDstRect.x = xMouse;
		cursorDstRect.y = yMouse;
		


		while (SDL_PollEvent(&Event)) {
			switch (Event.type) 
			{
				case SDL_QUIT:
					isRunning = false;
					break;

				case SDL_KEYDOWN:
					if(inputManager.keyboardButtonPressed(Event, keyboardButtons["left"])){

						SDL_Quit();
					
					
					
					
					}
					break;

				case SDL_MOUSEBUTTONDOWN:
					if (inputManager.mouseButtonPressed(Event.button, mouseButtons["left"])) {
						SDL_Quit();
					}
					break;

				case SDL_MOUSEMOTION:
					SDL_GetGlobalMouseState(&xMouse, &yMouse);
					break;


				default:
					break;
			}
			
			
			
			
			// Add more event handling as needed
		}

















			SDL_RenderCopy(mainRenderer, NeuromancerBackground, NULL, NULL);
			SDL_RenderCopy(mainRenderer, Gugug, NULL, NULL);

			
			SDL_RenderPresent(mainRenderer);
			






			SDL_RenderClear(mainRenderer);
			SDL_Delay(70);


		
	}


	return 0;
}

