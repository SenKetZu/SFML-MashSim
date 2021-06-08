#pragma once
#include<SFML/Graphics/Rect.hpp>
#include "MathVector.h"
class MassPoint
{
public:
	MassPoint(sf::Vector2f loc);//construye con solamente la posicion, la masa es 1.
	MassPoint(float mass, sf::Vector2f loc);//constructor recomendado, masa y posicion.
	sf::Vector2f	getLocation();
	void			setLocation(sf::Vector2f loc);
	float			getMass();
	void			setMass(float mass);
	void			push(MathVector direction);

	void			operator =(MassPoint* mp);//operador de asignacion estandar.	
	MathVector		operator <<=(MassPoint mp);//esto te da el vector entre 2 MassPoints.

private:
	float			_Mass = 1.0f;
	sf::Vector2f	_Location;
	//testing
	float			_Radius = 1.0f;

};
