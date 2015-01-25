#pragma once

#include <string>
#include <vector>
#include "Transform.hpp"
#include "Object.hpp"
using namespace std;


class GameObject
{
private:
	vector<vector<Object*>*>* components;
	Transform transform;
	unsigned int ID;
	bool active;

public:
	GameObject(void);
	~GameObject(void);

	static GameObject* getGameObject(unsigned int ID);
	Object* addComponent(std::string className);
	Object* getComponent(std::string className);
	std::vector<Object*>* getComponents(std::string className);
	void setActive(bool status);

};


typedef GameObject GO;