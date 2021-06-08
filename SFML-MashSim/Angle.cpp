#include "Angle.h"

//Public
	//Construct
Angle::Angle() :_Value(1)
{
}

Angle::Angle(char type, float cant)
{
	if (type == 'd' || type == 'D')
	{
		_Value = degToRad(cant);
		rectifyValue();
	}
	else if (type == 'r' || type == 'R')
	{
		_Value = cant;
		rectifyValue();
	}
	else
	{
		throw std::invalid_argument("Tipo de angulo Incorrecto");
	}

}

//metods
float Angle::asRad()
{
	return _Value;
}

float Angle::asDeg()
{
	return RadToDeg(_Value);
}

void Angle::setDeg(float deg)
{
	_Value = degToRad(deg);
	rectifyValue();
}

void Angle::setRad(float rad)
{
	_Value = rad;
	rectifyValue();
}

//Operators
void Angle::operator=(Angle* Betha)
{
	memcpy(this, Betha, sizeof *this);
}

Angle Angle::operator+(Angle Betha)
{
	return Angle('r', _Value + Betha.asRad());
}

Angle Angle::operator-(Angle Betha)
{
	return Angle('r', _Value - Betha.asRad());
}

void Angle::operator+=(Angle Betha)
{
	_Value += Betha.asRad();
	rectifyValue();
}

void Angle::operator-=(Angle Betha)
{
	_Value -= Betha.asRad();
	rectifyValue();
}

Angle Angle::operator*(float num)
{
	return Angle('r', _Value * num);
}

Angle Angle::operator/(float num)
{
	return Angle('r', _Value / num);
}

void Angle::operator*=(float num)
{
	_Value *= num;
	rectifyValue();
}

void Angle::operator/=(float num)
{
	_Value /= num;
	rectifyValue();
}

//Private
#define PI 3.1415f

void Angle::rectifyValue()
{
	if (_Value >  2*PI)
	{
		_Value -= 2* PI;
		rectifyValue();
	}
	if (_Value < 0)
	{
		_Value += 2*PI;
		rectifyValue();
	}
	return;
}

float Angle::degToRad(float deg)
{
	return deg * PI / 180.0f;
}

float Angle::RadToDeg(float rad)
{
	return rad * 180.0f / PI;
}