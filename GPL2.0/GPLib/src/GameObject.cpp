#include "../include/GameObject.hpp"

#include "../include/Gizmos.hpp"
#include "../include/Music.hpp"
#include "../include/Sound.hpp"
#include "../include/Sprite.hpp"
#include "../include/Text.hpp"

static unsigned int GID = 0;

enum COMPONENTS {GIZMOS, MUSIC, SOUND, SPRITE, TEXT};

static std::vector<GameObject*> gameObjects;

GameObject::GameObject(void):active(true)
{
	GID++;
	ID = GID;

	gameObjects.push_back(this);


	components = new vector<vector<Object*>*>;
	components->resize(5);
	components->at(GIZMOS) = new vector<Object*>;
	components->at(MUSIC) = new vector<Object*>;
	components->at(SOUND) = new vector<Object*>;
	components->at(SPRITE) = new vector<Object*>;
	components->at(TEXT) = new vector<Object*>;
}

GameObject::~GameObject(void)
{
}

Object* GameObject::getComponent(string name)
{
	

	if(name == "Gizmos")
	{
		if(components->at(GIZMOS)->size() == 1)
			return (Gizmos*)components->at(GIZMOS)->back();
	}
	else if(name == "Music")
	{
		if(components->at(MUSIC)->size() == 1) 
			return (Music*)components->at(MUSIC)->back();
	}
	else if(name == "Sound")
	{
		if(components->at(SOUND)->size() == 1) 
			return (Sound*)components->at(SOUND)->back();
	}
	else if(name == "Sprite")
	{
		if(components->at(SPRITE)->size() == 1) 
			return (Sprite*)components->at(SPRITE)->back();
	}
	else if(name == "Text")
	{
		if(components->at(TEXT)->size() == 1)
			return (Text*)components->at(TEXT)->back();
	}
	return NULL;
}



Object* GameObject::addComponent(std::string className)
{
	if(className == "Gizmos")
	{
		components->at(GIZMOS)->push_back(new Gizmos());
		return components->at(GIZMOS)->back();
	}
	else if(className == "Music")
	{
		components->at(MUSIC)->push_back(new Music());
		return components->at(MUSIC)->back();
	}
	else if(className == "Sound")
	{
		components->at(SOUND)->push_back(new Sound());
		return components->at(SOUND)->back();
	}
	else if(className == "Sprite")
	{
		components->at(SPRITE)->push_back(new Sprite());
		return components->at(SPRITE)->back();
	}
	else if(className == "Text")
	{
		components->at(TEXT)->push_back(new Sprite());
		return components->at(TEXT)->back();
	}
	return NULL;
}


GameObject* GameObject::getGameObject(unsigned int ID)
{
	for(int i = 0; i < gameObjects.size(); i++)
	{
		if(gameObjects.at(i)->ID == ID)
		{
			return gameObjects.at(i);
		}
	}
	return NULL;
}

std::vector<Object*>* GameObject::getComponents(std::string className)
{
	if(className == "Gizmos")
	{
		return components->at(GIZMOS);
	}
	else if(className == "Music")
	{
		return components->at(MUSIC);
	}
	else if(className == "Sound")
	{
		return components->at(SOUND);
	}
	else if(className == "Sprite")
	{
		return components->at(SPRITE);
	}
	else if(className == "Text")
	{
		return components->at(TEXT);
	}
	return NULL;
}

void GameObject::setActive(bool status)
{
	active = status;
}
