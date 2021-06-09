#include "MathVector.h"

//constructors
MathVector::MathVector() :_Magnitud(1), _Angle('r', 0) {}
MathVector::MathVector(sf::Vector2f a)
{
	_Magnitud = sqrt(pow(a.x, 2) + pow(a.y, 2));
	_Angle.setRad(asin(a.y / _Magnitud));
}
#define PI 3.1415f
MathVector::MathVector(sf::Vector2f F, sf::Vector2f I)
{
	sf::Vector2f aux = F - I;
	_Magnitud = sqrt(pow(aux.x, 2) + pow(aux.y, 2));
	_Angle.setRad(atan2(aux.y , aux.x)+PI);
}
MathVector::MathVector(float mod, Angle ang) :_Magnitud(mod), _Angle(ang) {}


//metods
float			MathVector::getMagnitude()
{
	return _Magnitud;
}

void			MathVector::setMagnitude(float mag)
{
	_Magnitud = mag;
}

Angle			MathVector::getAngle()
{
	return _Angle;
}

void			MathVector::setAngle(Angle alpha)
{
	_Angle = alpha;
}

sf::Vector2f	MathVector::getComponents()
{
	return sf::Vector2f( cos(_Angle.asRad()) * _Magnitud, sin(_Angle.asRad()) * _Magnitud);
}

void			MathVector::normalize()
{
	_Magnitud = 1.0f;
}

MathVector		MathVector::perpendicular()
{
	Angle cuart('d', 90.0f);
	return MathVector(1, (_Angle + cuart));
}

MathVector		MathVector::oposite()
{
	return this->perpendicular().perpendicular();
}

//operators
void			MathVector::operator= (MathVector* fors)
{
	memcpy(this, fors, sizeof *this);
}

MathVector		MathVector::operator+ (MathVector fors)
{
	sf::Vector2f sum = this->getComponents() + fors.getComponents();
	MathVector aux(sqrt((pow(sum.x, 2) + pow(sum.y, 2))), Angle('r', asin(sum.y / _Magnitud)));
	return aux;
}

MathVector		MathVector::operator- (MathVector fors)
{
	sf::Vector2f res = this->getComponents() - fors.getComponents();
	MathVector aux(sqrt((pow(res.x, 2) + pow(res.y, 2))), Angle('r', asin(res.y / _Magnitud)));
	return aux;
}

void			MathVector::operator+=(MathVector fors)
{
	sf::Vector2f sum = this->getComponents() + fors.getComponents();
	_Magnitud = sqrt((pow(sum.x, 2) + pow(sum.y, 2)));
	_Angle.setRad(asin(sum.y / _Magnitud));
}

void			MathVector::operator-=(MathVector fors)
{
	sf::Vector2f res = this->getComponents() - fors.getComponents();
	_Magnitud = sqrt((pow(res.x, 2) + pow(res.y, 2)));
	_Angle.setRad(asin(res.y / _Magnitud));
}

MathVector		MathVector::operator* (float num)
{
	return MathVector(_Magnitud * num, _Angle);
}

MathVector		MathVector::operator/ (float num)
{
	return MathVector(_Magnitud / num, _Angle);
}

void			MathVector::operator*=(float num)
{
	_Magnitud *= num;
}

void			MathVector::operator/=(float num)
{
	_Magnitud /= num;
}
