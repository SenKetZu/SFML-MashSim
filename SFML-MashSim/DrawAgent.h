#pragma once
#include <SFML/Graphics.hpp>
#include "SoftBody.h"
class DrawAgent
{
public:

	static DrawAgent&	getInstance()
	{
		static DrawAgent instance;
		return instance;
	}

	void				Draw(const sf::Drawable& drawable);
	void				Draw(SoftBody body);
	void				Clear();
	void				Display();
	float				DeltaTime();
	bool				isOpen();

	void				handleEvents();
private:
	DrawAgent();
	sf::RenderWindow	_Screen;
	sf::Clock			_Clock;

};

