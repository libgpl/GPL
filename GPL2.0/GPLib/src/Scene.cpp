#include "../include/Scene.hpp"

Scene::Scene(std::string sceneName)
{
	//for(int i = 0; i < scenesNames.size(); i++)
	//{
	//	bool teste = scenesNames.at(i).compare(sceneName);
	//	#if teste
	//	#error MyVAL must be defined to 2
	//	#endif
	//	(scenesNames.at(i).compare(sceneName))
	//	{
	//		ERROR(Nome de cena já usado);
	//	}
	//}
	//auto search = scenesNames.find(sceneName);
	//bool temp = true;
	//if(search != scenesNames.end())
	//{	scenesNames.insert(std::pair<std::string,Scene*>(sceneName,this));
	//	folderName = sceneName;
	//}
	//else
	//{
	//	MESSAGE(Nome de cena já usado);
	//}

	std::cout << folderName << std::endl;
}


Scene::~Scene(void)
{
}
