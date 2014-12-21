//#pragma once
//
//#include "../include/sprite.h"
//
//
//class BitmaskManager
//{
//public:
//	~BitmaskManager() {
//		std::map<const sf::Texture*, sf::Uint8*>::const_iterator end = Bitmasks.end();
//		for (std::map<const sf::Texture*, sf::Uint8*>::const_iterator iter = Bitmasks.begin(); iter!=end; iter++)
//			delete [] iter->second;
//	}
//
//	sf::Uint8 GetPixel (const sf::Uint8* mask, const sf::Texture* tex, unsigned int x, unsigned int y) {
//		if (x>tex->getSize().x||y>tex->getSize().y)
//			return 0;
//
//		return mask[x+y*tex->getSize().x];
//	}
//
//	sf::Uint8* GetMask (const sf::Texture* tex) {
//		sf::Uint8* mask;
//		std::map<const sf::Texture*, sf::Uint8*>::iterator pair = Bitmasks.find(tex);
//		if (pair==Bitmasks.end())
//		{
//			sf::Image img = tex->copyToImage();
//			mask = CreateMask (tex, img);
//		}
//		else
//			mask = pair->second;
//
//		return mask;
//	}
//
//	sf::Uint8* CreateMask (const sf::Texture* tex, const sf::Image& img) {
//		sf::Uint8* mask = new sf::Uint8[tex->getSize().y*tex->getSize().x];
//
//		for (unsigned int y = 0; y<tex->getSize().y; y++)
//		{
//			for (unsigned int x = 0; x<tex->getSize().x; x++)
//				mask[x+y*tex->getSize().x] = img.getPixel(x,y).a;
//		}
//
//		Bitmasks.insert(std::pair<const sf::Texture*, sf::Uint8*>(tex,mask));
//
//		return mask;
//	}
//private:
//	std::map<const sf::Texture*, sf::Uint8*> Bitmasks;
//};
//
//BitmaskManager Bitmasks;
//
//// Adaptação de código
//// Author: Nick (original version), ahnonay (SFML2 compatibility)
//bool colisao_por_pixel(sf::Sprite& Object1, sf::Sprite& Object2)
//{
//	sf::Uint8 AlphaLimit = 0;
//
//	sf::FloatRect Intersection; 
//	if (Object1.getGlobalBounds().intersects(Object2.getGlobalBounds(), Intersection)) {
//		sf::IntRect O1SubRect = Object1.getTextureRect();
//		sf::IntRect O2SubRect = Object2.getTextureRect();
//
//		sf::Uint8* mask1 = Bitmasks.GetMask(Object1.getTexture());
//		sf::Uint8* mask2 = Bitmasks.GetMask(Object2.getTexture());
//
//		// Loop through our pixels
//		for (int i = (int)Intersection.left; i < Intersection.left+Intersection.width; i++) {
//			for (int j = (int)Intersection.top; j < Intersection.top+Intersection.height; j++) {
//
//				sf::Vector2f o1v = Object1.getInverseTransform().transformPoint((float)i, (float)j);
//				sf::Vector2f o2v = Object2.getInverseTransform().transformPoint((float)i, (float)j);
//
//				// Make sure pixels fall within the Object1's subrect
//				if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
//					o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
//					o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {
//
//						if (Bitmasks.GetPixel(mask1, Object1.getTexture(), (int)(o1v.x)+O1SubRect.left, (int)(o1v.y)+O1SubRect.top) > AlphaLimit &&
//							Bitmasks.GetPixel(mask2, Object2.getTexture(), (int)(o2v.x)+O2SubRect.left, (int)(o2v.y)+O2SubRect.top) > AlphaLimit)
//							return true;
//
//				}
//			}
//		}
//	}
//	return false;
//}
//
//
//// #################################################################################################
//
//
//sprite::sprite(void):x(0),y(0),currentFrame(0),animationTime(30),alpha(255),mirror(false)
//{
//}
//
//sprite::~sprite(void)
//{
//}
//
//void sprite::load(string filename)
//{
//	frames.push_back(new sf::Texture());
//
//	string file = "./assets/sprites/" + filename;
//	if(!(*frames.back()).loadFromFile(file))
//	{
//		debug("ERRO","Arquivo do sprite '"+filename+"' não encontrado");
//	}	
//	
//}
//
//void sprite::load(string filename, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
//{
//	frames.push_back(new sf::Texture());
//
//	string file = "./assets/sprites/" + filename;
//	if(!(*frames.back()).loadFromFile(file, sf::IntRect(x, y, width, height)))
//	{
//		debug("ERRO","Arquivo do sprite '"+filename+"' não encontrado");
//	}	
//}
//
//int sprite::getResX()
//{
//	return (*frames.back()).getSize().x;
//}
//
//int sprite::getResY()
//{
//	return (*frames.back()).getSize().y;
//}
//
//void sprite::setSpeed(unsigned int speed)
//{
//	animationTime = speed;
//}
//
//int sprite::getSpeed()
//{
//	return animationTime;
//}
//
//void sprite::setFrame(int frame)
//{
//	currentFrame = frame;
//}
//
//void sprite::draw(int x, int y, bool mirror, int alpha, unsigned int angle, bool edge)
//{
//	// Define a opacidade da imagem
//	if(this->alpha != alpha)
//	{
//		// Aplica os limites inferior e superior para alpha (0-255)
//		this->alpha = (this->alpha < 0) ? 0 : alpha;
//		this->alpha = (this->alpha > 255) ? 255 : alpha;
//
//		_sprite.setColor(sf::Color(255,255,255,this->alpha));
//	}
//
//	// Habilita o desenho da imagem espelhado
// 	if(this->mirror != mirror)
//	{
//		this->mirror = mirror;
//		if(this->mirror)
//		{
//			_sprite.setScale(-1,1);
//		}
//		else
//		{
//			_sprite.setScale(1,1);
//		}
//	}
//	_sprite.setTexture((*frames.at(currentFrame)));
//
//	timer = clk.getElapsedTime();
//
//	if(timer.asMilliseconds() > animationTime)
//	{
//		currentFrame++;
//		if(currentFrame == frames.size()) currentFrame = 0;
//		clk.restart();
//	}
//
//	if(this->angle != angle)
//	{
//		this->angle = angle;
//		_sprite.setRotation((float)angle); // absolute angle
//	}
//
//	if(this->x != x || this->y != y)
//	{
//		this->x = x;
//		this->y = y;
//		_sprite.setPosition(sf::Vector2f((float)x,(float)y));
//	}
//
//	::draw(&_sprite, edge);
//}
//
//
//bool sprite::collides(sprite _sprite)
//{
//	// Método de colisão adaptado da LibEGL
//	int w1 = getResX();
//	int h1 = getResY();
//	int x1 = x;
//	int y1 = y;
//
//	int w2 = _sprite.getResX();
//	int h2 = _sprite.getResY();
//	int x2 = _sprite.x;
//	int y2 = _sprite.y;
//
//	if (!( ((x1)>=(x2)+(w2)) || 
//		((x2)>=(x1)+(w1)) || 
//		((y1)>=(y2)+(h2)) || 
//		((y2)>=(y1)+(h1)) ))
//	{
//		return colisao_por_pixel(this->_sprite, _sprite._sprite);
//	}
//	else
//	{
//		return false;
//	}
//
//}
//
//int sprite::getPosX()
//{
//	return x;
//}
//
//int sprite::getPosY()
//{
//	return y;
//}