#pragma once
#include <math.h>
#include<SFML/Graphics/Rect.hpp>
#include "Angle.h"

class MathVector
{
public:
	//constructors
	MathVector();
	MathVector(sf::Vector2f a);
	MathVector(sf::Vector2f a, sf::Vector2f b);
	MathVector(float mod, Angle alpha);

	//metods
	float			getMagnitude();
	void			setMagnitude(float mag);
	Angle			getAngle();
	void			setAngle(Angle alpha);
	sf::Vector2f	getComponents();
	void			normalize();
	MathVector		perpendicular();
	MathVector		oposite();

	//operators
	void			operator = (MathVector* fors);
	MathVector		operator + (MathVector fors);
	MathVector		operator - (MathVector fors);
	void			operator +=(MathVector fors);
	void			operator -=(MathVector fors);
	MathVector		operator * (float num);
	MathVector		operator / (float num);
	void			operator *=(float num);
	void			operator /=(float num);

private:

	float			_Magnitud;
	Angle			_Angle;
};