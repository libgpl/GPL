#include "../include/Input.hpp"

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

	for(int i = 0; i < sf::Joystick::ButtonCount; i++){
		onPressedJoystick[PLAYER_1][i] = false;
		onDownPressedJoystick[PLAYER_1][i] = false;
		joystickTimer[PLAYER_1][i] = 0;

		onPressedJoystick[PLAYER_2][i] = false;
		onDownPressedJoystick[PLAYER_2][i] = false;
		joystickTimer[PLAYER_2][i] = 0;
	}
}

Input::~Input(void)
{
	if(instance)
	{
		delete instance;
	}
}

Input* Input::getInstance()
{
	if(!instance)
	{
		instance = new Input();
	}
	return instance;
}

//
//	bool Input::anyKeyPressed(){
//
//	for(int i = 0; i < KEY::KeyCount; i++){
//		if(isPressed(KEY(i))){			
//			return true;			
//		}	
//	}	
//	return false;
//}
//bool Input::anyButtonPressed(){
//	
//	for(int i = 0; i < MOUSE::ButtonCount; i++){
//		if(isPressed(MOUSE(i))){				
//			return false;
//		}
//	}
//	return false;
//	
//}

bool Input::isPressed(KEY key)
{
	if(sf::Keyboard::isKeyPressed(key))
	{
		return true;
	}
	return false;
}

bool Input::isPressed(MOUSE mouse)
{
	if (sf::Mouse::isButtonPressed(mouse))
	{
		return true;
	}	
	return false;
}

bool Input::isKeyDownReleased(KEY _key){	

	if(isPressed(_key)){			
		onDownPressed[_key] = true;			
		return false;
	}	
	if(onDownPressed[_key] && !isPressed(_key)){			
		onDownPressed[_key] = false;	
		return true;		
	}	
	return false;
}

bool Input::isUp(KEY _key)
{	
	if(isPressed(_key)){			
		onPressed[_key] = true;			
		return false;
	}	
	if(onPressed[_key] && !isPressed(_key)){			
		onPressed[_key] = false;	
		return true;		
	}	
	return false;
}


bool Input::isDown(KEY _key)
{
	if(isPressed(_key)){
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

bool Input::isUp(MOUSE _mouse)
{
	if(isPressed(_mouse)){			
		onPressedMouse[_mouse] = true;		
		return false;
	}	
	if(onPressedMouse[_mouse] && !isPressed(_mouse)){		
		onPressedMouse[_mouse] = false;	
		return true;		
	}
	return false;
}

bool Input::isDown(MOUSE _mouse){

	if(isPressed(_mouse)){
		mouseTimer[_mouse]++;
		if(mouseTimer[_mouse] == 1){
			return true;
		}	
	}
	if(isPressed(_mouse)){
		mouseTimer[_mouse] = 0;
	}
	return false;
}


bool Input::isButtonDownReleased(MOUSE _mouse){	

	if(isPressed(_mouse)){			
		onDownPressedMouse[_mouse] = true;		
		return false;
	}	
	if(onDownPressedMouse[_mouse] && !isPressed(_mouse)){		
		onDownPressedMouse[_mouse] = false;	
		return true;		
	}
	return false;
}

// ---------- JOYSTICK ---------- 
bool Input::isPressed(JOYSTICK _joystick, PLAYER _player)
{
	if(sf::Joystick::isButtonPressed(_player, _joystick))
	{
		return true;
	}
	return false;
}

bool Input::isUp(JOYSTICK _joystick, PLAYER _player)
{
	if(isPressed(_joystick,_player)){			
		onPressedJoystick[_player][_joystick] = true;		
		return false;
	}	
	if(onPressedJoystick[_player][_joystick] && !isPressed(_joystick,_player)){		
		onPressedJoystick[_player][_joystick] = false;	
		return true;		
	}
	return false;
}

bool Input::isDown(JOYSTICK _joystick, PLAYER _player)
{
	if(isPressed(_joystick, _player)){
		joystickTimer[_player][_joystick]++;
		if(joystickTimer[_player][_joystick] == 1){
			return true;
		}	
	}
	if(isButtonDownReleasedJoysTick(_joystick,_player)){
		joystickTimer[_player][_joystick] = 0;
	}
	return false;
}

bool Input::isButtonDownReleasedJoysTick(JOYSTICK _joystick, PLAYER _player)
{
	if(isPressed(_joystick,_player)){			
		onDownPressedJoystick[_player][_joystick] = true;		
		return false;
	}	
	if(onDownPressedJoystick[_player][_joystick] && !isPressed(_joystick,_player)){		
		onDownPressedJoystick[_player][_joystick] = false;	
		return true;		
	}
	return false;
}

Input* Input::instance = NULL;