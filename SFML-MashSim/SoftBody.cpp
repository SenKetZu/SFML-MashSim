#include "SoftBody.h"

SoftBody::SoftBody(size_t definition, sf::Vector2f center, float lenght):
	_Centro(center),
	_Definition(definition),
	_Length(lenght),
	_Body(sf::LinesStrip,definition+1)
{
	/*
	_Body.setFillColor(sf::Color::Red);
	_Body.setOutlineColor(sf::Color::White);
	_Body.setOutlineThickness(3);
	_Body.setPosition(center);
	*/
}

void SoftBody::init()
{
	_BDcolor = sf::Color::Red;
	_Bordes.clear();
	_Springs.clear();
	//_Body.setPointCount(_Definition);
	float alpha, betha;

	alpha = 0.0f;
	betha = 360.0f / float(_Definition);

	for (size_t i = 0; i < _Definition; i++)
	{

		MathVector dir(_Length, Angle('d', alpha));
		MassPoint point(dir.getComponents()+_Centro.getLocation());
		_Bordes.push_back(point);

		alpha += betha;
	}
	for (MassPoint& e:_Bordes)
	{
		_Springs.push_back(Spring(_Centro, e));
	}
	build();
}

void SoftBody::build()
{
	/*
	_Body[0].position = _Centro.getLocation();
	_Body[0].color = sf::Color::Green;
	*/
	for (size_t i = 0; i < _Definition; i++)
	{
		
		_Body[i].position=_Bordes[i].getLocation();
		_Body[i].color = _BDcolor;

	}
	_Body[_Definition].position = _Bordes[0].getLocation();
	_Body[_Definition].color = _BDcolor;
}

void SoftBody::update()
{
	//init();
	for (size_t i = 0; i < _Springs.size(); i++)
	{
		_Springs[i].Update();
	}

	build();
}

void SoftBody::moveTo(sf::Vector2f pos)
{
	_Centro.setLocation(pos);
}

sf::VertexArray SoftBody::draw()
{
	return _Body;
}
