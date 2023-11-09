#pragma once
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

class InputManager
{
private:

	

	

public:
	std::map < std::string, SDL_Scancode> actionMapKeyboard;
	std::map <std::string, int> actionMapMouse; //tuka...abe da ne kazvam napravo, po dobre da si mulcha
	
	
	auto mapControlsKeyBoard(const char* inputKey, std::string nameOfAction) {

		
		actionMapKeyboard[nameOfAction] = SDL_GetScancodeFromName(inputKey);
		return actionMapKeyboard;

		
		




	}

	auto mapControlsMouse(std::string name, std::string button) {
	

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
	


	



};

