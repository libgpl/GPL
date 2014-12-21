//#include "../include/text.h"
//#include "../include/gpl.h"
//
//text::text(void):x(0),y(0),size(1),R(255),G(255),B(255),bold(false),italic(false),underline(false)
//{
//}
//
//text::~text(void)
//{
//}
//
//void text::load(string filename)
//{
//	font = new sf::Font();
//	
//
//	string file = "./assets/fonts/" + filename;
//	if(!font->loadFromFile(file))
//	{
//		debug("ERRO","Arquivo de fonte '"+filename+"' não encontrado");
//	}	
//
//	this->Text.setFont(*font);
//}
//
//void text::draw(string text, int x, int y, unsigned int size, unsigned int R, unsigned int G, unsigned int B, unsigned int A, bool bold, bool italic, bool underline)
//{
//	if(this->_text != text)
//	{
//		this->_text = text;
//		// set the string to distocar
//		this->Text.setString(text);
//	}
//	if(this->x != x || this->y != y)
//	{
//		this->x = x;
//		this->y = y;
//		this->Text.setPosition(sf::Vector2f((float)x,(float)y));
//	}
//
//	if(this->size != size)
//	{
//		this->size = size;
//		// set the character size
//		this->Text.setCharacterSize(size); // in pixels, not points!
//	}
//
//	if(this->R != R || this->G != G || this->B != B || this->A != A)
//	{
//		this->R = R;
//		this->G = G;
//		this->B = B;
//		this->A = A;
//		// set the color
//		this->Text.setColor(sf::Color::Color(R,G,B,A));
//	}
//
//	if(this->bold != bold || this->italic != italic || this->underline != underline)
//	{
//		this->bold = bold;
//		this->italic = italic;
//		this->underline = underline;
//
//		if(bold && italic && underline)
//		{
//			// set the text style
//			this->Text.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic);
//		}
//		else if(bold && italic)
//		{
//			// set the text style
//			this->Text.setStyle(sf::Text::Bold | sf::Text::Italic);
//		}
//		else if(bold && underline)
//		{
//			// set the text style
//			this->Text.setStyle(sf::Text::Bold | sf::Text::Underlined);
//		}
//		else if(italic && underline)
//		{
//			// set the text style
//			this->Text.setStyle(sf::Text::Underlined | sf::Text::Italic);
//		}
//		else if(bold)
//		{
//			// set the text style
//			this->Text.setStyle(sf::Text::Bold);
//		}
//		else if(italic)
//		{
//			// set the text style
//			this->Text.setStyle(sf::Text::Italic);
//		}
//		else if(underline)
//		{
//			// set the text style
//			this->Text.setStyle(sf::Text::Underlined);
//		}
//
//	}
//
//	::write(&this->Text);
//}