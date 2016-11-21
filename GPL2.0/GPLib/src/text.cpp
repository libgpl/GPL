/*
========================================================
GPL - Game Programming Library
by Luan Carlos Nesi (2014-2016)
https://github.com/libgpl
========================================================

The MIT License (MIT)

Copyright (c) 2014-2016 Luan Nesi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "../include/Text.hpp"
#include "../include/Window.hpp"
#include "../include/Base.hpp"

Text::Text(void) :x(0), y(0), size(1), R(255), G(255), B(255), bold(false), italic(false), underline(false)
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

	if (!font->loadFromFile(File))
	{
		panel->debug("ERROR", "Arquivo de fonte '" + Filename + "' não encontrado");
	}

	this->text.setFont(*font);
}

void Text::draw(std::string text, int x, int y, unsigned int size, unsigned int R, unsigned int G, unsigned int B, unsigned int A, bool bold, bool italic, bool underline)
{
	if (this->_text != text)
	{
		this->_text = text;
		this->text.setString(text);
	}

	if (this->x != x || this->y != y)
	{
		this->x = x;
		this->y = y;
		this->text.setPosition(sf::Vector2f((float)x, (float)y));
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
		this->text.setPosition(sf::Vector2f((float)x, (float)y));
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