#include "../include/Text.hpp"
#include "../include/Window.hpp"
#include "../include/Base.hpp"

Text::Text(void):x(0),y(0),size(1),R(255),G(255),B(255),bold(false),italic(false),underline(false)
{
	//	base = Base();
}

Text::~Text(void)
{
}

void Text::load(std::string Filename)
{
	font = new sf::Font();
	std::string File;
	File = "./assets/fonts/" + Filename;

	if(!font->loadFromFile(File))
	{
		panel->debug("ERROR","Arquivo de fonte '"+Filename+"' n�o encontrado");
	}	

	this->text.setFont(*font);
}

void Text::draw(std::string text, int x, int y, unsigned int size, unsigned int R, unsigned int G, unsigned int B, unsigned int A, bool bold, bool italic, bool underline)
{
	if(this->_text != text)
	{
		this->_text = text;
		this->text.setString(text);
	}

	if(this->x != x || this->y != y)
	{
		this->x = x;
		this->y = y;
		this->text.setPosition(sf::Vector2f((float)x,base->getWindow()->getSize().y-(float)y));
	}

	if(this->size != size)
	{
		this->size = size;
		// set the character size
		this->text.setCharacterSize(size); // in pixels, not points!
	}

	if(this->R != R || this->G != G || this->B != B || this->A != A)
	{
		this->R = R;
		this->G = G;
		this->B = B;
		this->A = A;
		// set the color
		this->text.setColor(sf::Color::Color(R,G,B,A));
	}

	if(this->bold != bold || this->italic != italic || this->underline != underline)
	{
		this->bold = bold;
		this->italic = italic;
		this->underline = underline;

		if(bold && italic && underline)
		{
			// set the text style
			this->text.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic);
		}
		else if(bold && italic)
		{
			// set the text style
			this->text.setStyle(sf::Text::Bold | sf::Text::Italic);
		}
		else if(bold && underline)
		{
			// set the text style
			this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		}
		else if(italic && underline)
		{
			// set the text style
			this->text.setStyle(sf::Text::Underlined | sf::Text::Italic);
		}
		else if(bold)
		{
			// set the text style
			this->text.setStyle(sf::Text::Bold);
		}
		else if(italic)
		{
			// set the text style
			this->text.setStyle(sf::Text::Italic);
		}
		else if(underline)
		{
			// set the text style
			this->text.setStyle(sf::Text::Underlined);
		}

	}
	base->getWindow()->draw(this->text);
}
void Text::draw(int text, int x, int y, unsigned int size, unsigned int R, unsigned int G, unsigned int B, unsigned int A, bool bold, bool italic, bool underline)
{
	if (this->_text != std::to_string(text))
	{
		this->_text = std::to_string(text);
		this->text.setString(std::to_string(text));
	}

	if (this->x != x || this->y != y)
	{
		this->x = x;
		this->y = y;
		this->text.setPosition(sf::Vector2f((float)x, base->getWindow()->getSize().y - (float)y));
	}

	if (this->size != size)
	{
		this->size = size;
		// set the character size
		this->text.setCharacterSize(size); // in pixels, not points!
	}

	if (this->R != R || this->G != G || this->B != B || this->A != A)
	{
		this->R = R;
		this->G = G;
		this->B = B;
		this->A = A;
		// set the color
		this->text.setColor(sf::Color::Color(R, G, B, A));
	}

	if (this->bold != bold || this->italic != italic || this->underline != underline)
	{
		this->bold = bold;
		this->italic = italic;
		this->underline = underline;

		if (bold && italic && underline)
		{
			// set the text style
			this->text.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic);
		}
		else if (bold && italic)
		{
			// set the text style
			this->text.setStyle(sf::Text::Bold | sf::Text::Italic);
		}
		else if (bold && underline)
		{
			// set the text style
			this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		}
		else if (italic && underline)
		{
			// set the text style
			this->text.setStyle(sf::Text::Underlined | sf::Text::Italic);
		}
		else if (bold)
		{
			// set the text style
			this->text.setStyle(sf::Text::Bold);
		}
		else if (italic)
		{
			// set the text style
			this->text.setStyle(sf::Text::Italic);
		}
		else if (underline)
		{
			// set the text style
			this->text.setStyle(sf::Text::Underlined);
		}

	}
	base->getWindow()->draw(this->text);
}