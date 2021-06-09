#pragma once
#include <vector>
#include "Spring.h"
#include <SFML/Graphics.hpp>

class SoftBody
{
public:
	SoftBody(size_t definition, sf::Vector2f center, float lenght);

	void init();
	void build();
	void update();
	sf::VertexArray draw();


private:
	sf::Color				_BDcolor;
	sf::VertexArray			_Body;
	std::vector<Spring>		_Springs;
	std::vector<MassPoint>	_Bordes;
	MassPoint				_Centro;

	//propieties
	size_t					_Definition;
	float					_Length;
	 


};

