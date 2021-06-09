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
	
	

	/*
	while (DrawAgent::getInstance().isOpen())
	{

	
		DrawAgent::getInstance().handleEvents();
	
		std::cout << "<>";
		sf::VertexArray line(sf::Lines, 2);

		MathVector force(100, Angle('d', 0));
		MassPoint _anchor({ 400,300 }), _border({ 400,200 });

		line[0].position = _anchor.getLocation();
		line[0].color = sf::Color::Blue;
		line[1].position = _border.getLocation();
		line[1].color = sf::Color::Blue;

		DrawAgent::getInstance().Draw(line);
		DrawAgent::getInstance().Display();
		sf::sleep(sf::seconds(5));

		_border.push(force);

		line[0].position = _anchor.getLocation();
		line[1].position = _border.getLocation();

		DrawAgent::getInstance().Draw(line);
		DrawAgent::getInstance().Display();
		sf::sleep(sf::seconds(5));
	}
	*/
	return 0;
}