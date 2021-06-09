#include "DrawAgent.h"

DrawAgent::DrawAgent():
	_Screen(sf::VideoMode({ 800,600 }), "Mesh", sf::Style::Default)
{
	
}

void DrawAgent::Draw(const sf::Drawable& drawable)
{
	_Screen.draw(drawable);
}

void DrawAgent::Draw(SoftBody body)
{
	_Screen.draw(body.draw());
}

void DrawAgent::Clear()
{
	_Screen.clear();
}

void DrawAgent::Display()
{
	_Screen.display();
	_Clock.restart();
}

float DrawAgent::DeltaTime()
{
	return _Clock.getElapsedTime().asSeconds();
}

bool DrawAgent::isOpen()
{
	return _Screen.isOpen();
	_Screen.setFramerateLimit(60);
}

void DrawAgent::handleEvents()
{
	
	sf::Event Evento;
	while (_Screen.pollEvent(Evento))
	{
		if (Evento.type == sf::Event::Closed)
		{
			_Screen.close();
		}
	}
	
}





