#pragma once
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

class InputManager
{

	

	

public:
	int xMouseCords = 0;
	int yMouseCords = 0;
	std::map < std::string, SDL_Scancode> actionMapKeyboard;
	std::map <std::string, int> actionMapMouse; //tuka...abe da ne kazvam napravo, po dobre da si mulcha
	
	
	std::map<std::string, SDL_Scancode> mapControlsKeyBoard(const char* inputKey, std::string nameOfAction) {

		
		actionMapKeyboard[nameOfAction] = SDL_GetScancodeFromName(inputKey); //get scancode from name, assign it to action
		return actionMapKeyboard; //return map

		
		




	}

	std::map<std::string, int> mapControlsMouse(std::string name, std::string button) {
	

		std::transform(button.begin(), button.end(), button.begin(), ::toupper);
		if (button == "LEFT") {
			actionMapMouse[name] = SDL_BUTTON_LEFT;
		}
		if (button == "RIGHT") {
			actionMapMouse[name] = SDL_BUTTON_RIGHT;  

		}
		if (button == "MIDDLE") {
			actionMapMouse[name] = SDL_BUTTON_MIDDLE;
		}

		return actionMapMouse;
		

	}

	bool mouseButtonPressed(SDL_MouseButtonEvent& b, int mouseButton) {
		if(b.button == mouseButton){

			return true;
		
		
		}
		else {
			return false;
		}
	}

	bool keyboardButtonPressed(SDL_Event e, SDL_Scancode scancode) {


		if(e.key.keysym.scancode == scancode){
			return true;
		
		
		}
		else {

			return false;

		}


	}
	
	
	int getXMouseCoordinates(int xMouse) {
		SDL_GetGlobalMouseState(&xMouse, NULL);
		return xMouse;
		




	}
	int getYMouseCoordinates(int yMouse) {
		SDL_GetGlobalMouseState(NULL, &yMouse);
		return yMouse;





	}

	



};

