#pragma once
#include <math.h>
#include <stdexcept>

class Angle
{
public:

	Angle();
	Angle(char type, float cant);

	float	asRad();
	float	asDeg();
	void	setDeg(float deg);
	void	setRad(float rad);

	void	operator = (Angle* Betha);
	Angle	operator + (Angle Betha);
	Angle	operator - (Angle Betha);
	void	operator +=(Angle Betha);
	void	operator -=(Angle Betha);
	Angle	operator * (float num);
	Angle	operator / (float num);
	void	operator *=(float num);
	void	operator /=(float num);

private:

	void	rectifyValue();
	float	degToRad(float deg);
	float	RadToDeg(float rad);
	float	_Value;

};