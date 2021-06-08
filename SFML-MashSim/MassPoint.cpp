#include "MassPoint.h"
#include <iostream>



MassPoint::MassPoint(sf::Vector2f loc) :_Location(loc) {}
MassPoint::MassPoint(float mass, sf::Vector2f loc) : _Mass(mass), _Location(loc) {}

sf::Vector2f MassPoint::getLocation()
{
	return _Location;
}

void MassPoint::setLocation(sf::Vector2f loc)
{
	_Location = loc;
}

float MassPoint::getMass()
{
	return _Mass;
}

void MassPoint::setMass(float mass)
{
}

void MassPoint::push(MathVector direction)
{
	_Location += direction.getComponents();
}

void MassPoint::operator  =	(MassPoint* mp)
{
	memcpy(this, mp, sizeof *this);
	//std::cout << sizeof *this<<"<--";
}

MathVector		MassPoint::operator <<=	(MassPoint mp)
{
	return MathVector(_Location, mp.getLocation());
}
