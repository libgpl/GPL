#include "../include/Input.h"

Input::Input(void)
{
	for(int i = 0; i < KEY::KeyCount; i++){
		onPressed[i] = false;
		onDownPressed[i] = false;
		timer[i] = 0;
	}
	for(int i = 0; i < MOUSE::ButtonCount; i++){
		onPressedMouse[i] = false;
		onDownPressedMouse[i] = false;
		mouseTimer[i] = 0;
	}
}


Input::~Input(void)
{
}

//
//	bool Input::anyKeyPressed(){
//
//	for(int i = 0; i < KEY::KeyCount; i++){
//		if(isKeyHeld(KEY(i))){			
//			return true;			
//		}	
//	}	
//	return false;
//}
//bool Input::anyButtonPressed(){
//	
//	for(int i = 0; i < MOUSE::ButtonCount; i++){
//		if(isMouseButtonHeld(MOUSE(i))){				
//			return false;
//		}
//	}
//	return false;
//	
//}

bool Input::isKeyHeld(KEY key)
{
	if(sf::Keyboard::isKeyPressed(key))
	{
		return true;
	}
	return false;
}

bool Input::isMouseButtonHeld(MOUSE mouse)
{
	if (sf::Mouse::isButtonPressed(mouse))
	{
		return true;
	}	
	return false;
}

bool Input::isKeyDownReleased(KEY _key){	

	if(isKeyHeld(_key)){			
		onDownPressed[_key] = true;			
		return false;
	}	
	if(onDownPressed[_key] && !isKeyHeld(_key)){			
		onDownPressed[_key] = false;	
		return true;		
	}	
	return false;
}

bool Input::isKeyUp(KEY _key)
{	
	if(isKeyHeld(_key)){			
		onPressed[_key] = true;			
		return false;
	}	
	if(onPressed[_key] && !isKeyHeld(_key)){			
		onPressed[_key] = false;	
		return true;		
	}	
	return false;
}


bool Input::isKeyDown(KEY _key)
{

	if(isKeyHeld(_key)){
		timer[_key]++;
		if(timer[_key] == 1){
			return true;
		}	
	}
	if(isKeyDownReleased(_key)){
		timer[_key] = 0;
	}
	return false;
}

bool Input::isMouseButtonUp(MOUSE _mouse){

	if(isMouseButtonHeld(_mouse)){			
		onPressedMouse[_mouse] = true;		
		return false;
	}	
	if(onPressedMouse[_mouse] && !isMouseButtonHeld(_mouse)){		
		onPressedMouse[_mouse] = false;	
		return true;		
	}
	return false;
}

bool Input::isMouseButtonDown(MOUSE _mouse){

	if(isMouseButtonHeld(_mouse)){
		mouseTimer[_mouse]++;
		if(mouseTimer[_mouse] == 1){
			return true;
		}	
	}
	if(isMouseButtonHeld(_mouse)){
		mouseTimer[_mouse] = 0;
	}
	return false;
}



bool Input::isButtonDownReleased(MOUSE _mouse){	

	if(isMouseButtonHeld(_mouse)){			
		onDownPressedMouse[_mouse] = true;		
		return false;
	}	
	if(onDownPressedMouse[_mouse] && !isMouseButtonHeld(_mouse)){		
		onDownPressedMouse[_mouse] = false;	
		return true;		
	}
	return false;
}

// ---------- JOYSTICK ---------- 
bool Input::isJoystickButtonHeld(MOUSE _mouse)
{
	return false;
}

bool Input::isJoystickButtonUp(MOUSE _mouse)
{
	return false;
}

bool Input::isJoystickButtonDown(MOUSE _mouse)
{
	return false;
}