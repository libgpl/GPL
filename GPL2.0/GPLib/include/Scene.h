#pragma once
#include <string>
#include <iostream>
using namespace std;


class Scene
{
public:
	Scene(string SceneName = "");
	~Scene(void);
private:
	string folderName;
};

