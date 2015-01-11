#include "../include/Window.hpp"

#include <sstream>

//Text defaultText;







//void draw(sf::Sprite* t, bool borda)
//{
//	if(borda)
//	{
//		sf::RectangleShape retangulo(sf::Vector2f((float)(*t->getTexture()).getSize().x,(float)(*t->getTexture()).getSize().y));
//		retangulo.setOutlineThickness((float)3);
//		retangulo.setFillColor(sf::Color(0,0,0,0));
//		retangulo.setOutlineColor(sf::Color(255, 0, 0));
//		retangulo.setPosition(t->getPosition().x,t->getPosition().y);
//		retangulo.setRotation(t->getRotation());
//		window->draw(retangulo);
//	}
//
//	window->draw(*t);
//}
//
//void write(sf::Text* Text)
//{
//	window->draw(*Text);
//}

//int mouse_x;
//int mouse_y;
//
//int getMouseY()
//{
//	return sf::Mouse::getPosition(*window).y;
//}
//
//int getMouseX()
//{
//	return sf::Mouse::getPosition(*window).x;
//}
//
//int getMouseScroll()
//{
//	if (event.type == sf::Event::MouseWheelMoved)
//	{
//		return event.mouseWheel.delta;
//	}
//	else return 0;
//}
//
//bool isKeyPressed(KEY key)
//{
//	if(sf::Keyboard::isKeyPressed(key))
//	{
//		return true;
//	}
//	return false;
//}
//
//bool isButtonPressed(MOUSE mouse)
//{
//	if (sf::Mouse::isButtonPressed(mouse))
//	{
//		return true;
//	}	
//	return false;
//}

// TODO: Descomentar isso, método de colisão
// Return the a float rect as an int rect.
//inline sf::IntRect FToIRect(const sf::FloatRect& f) {
//	return sf::IntRect((int) f.left, (int) f.top, (int) f.width, (int) f.height);
//}
//
//
//bool testeColide(sf::Sprite& a, sf::Sprite& b, sf::Image& imgA, sf::Image& imgB) {
//	sf::IntRect boundsA(FToIRect(a.getGlobalBounds()));
//	sf::IntRect boundsB(FToIRect(b.getGlobalBounds()));
//	sf::IntRect intersection;
//
//	if(boundsA.intersects(boundsB, intersection)) {
//		const sf::Transform& inverseA(a.getInverseTransform());
//		const sf::Transform& inverseB(b.getInverseTransform());
//
//		const sf::Vector2u& sizeA(imgA.getSize());
//		const sf::Vector2u& sizeB(imgB.getSize());
//
//		const sf::Uint8* pixA = imgA.getPixelsPtr();
//		const sf::Uint8* pixB = imgB.getPixelsPtr();
//
//		sf::Vector2f vecA, vecB;
//		int xMax = intersection.left + intersection.width;
//		int yMax = intersection.top + intersection.height;
//
//		for(int x = intersection.left; x < xMax; x++)
//			for(int y = intersection.top; y < yMax; y++) {
//				vecA = inverseA.transformPoint((float)x, (float)y);
//				vecB = inverseB.transformPoint((float)x, (float)y);
//
//				int idxA = ((int) vecA.x + ((int) vecA.y)*sizeA.x)*4 + 3;
//				int idxB = ((int) vecB.x + ((int) vecB.y)*sizeB.x)*4 + 3;
//
//				if(vecA.x > 0 && vecA.y > 0 &&
//					vecB.x > 0 && vecB.y > 0 &&
//					vecA.x < sizeA.x && vecA.y < sizeA.y &&
//					vecB.x < sizeB.x && vecB.y < sizeB.y &&
//					pixA[idxA] > 0 &&
//					pixB[idxB] > 0) {
//						return true;
//				}
//			}
//	}
//
//	return false;
//}
//
//
//
