#pragma once
#include <string>
#include <iostream>



class Scene
{
public:
	Scene(std::string SceneName = "");
	~Scene(void);
private:
	std::string folderName;
};

