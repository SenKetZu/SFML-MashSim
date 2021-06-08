#include <SFML/Graphics.hpp>
#include"SoftBody.h"
#include <iostream>
#include "DrawAgent.h"
int main()
{
	//main loop
	sf::CircleShape center;
	center.setRadius(2);
	center.setOrigin({ 2 ,2 });
	center.setFillColor(sf::Color::Green);
	center.setPosition(400, 300);
	SoftBody obj(5, { 400 ,300 }, 200.0f);
	obj.init();


	while (DrawAgent::getInstance().isOpen())
	{

		DrawAgent::getInstance().handleEvents();


		obj.update();

		DrawAgent::getInstance().Clear();
		DrawAgent::getInstance().Draw(obj);
		DrawAgent::getInstance().Draw(center);

		DrawAgent::getInstance().Display();



	}





	return 0;
}