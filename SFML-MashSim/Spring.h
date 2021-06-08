#pragma once
#include "MassPoint.h"
#include "MathVector.h"
class Spring
{
public:

	Spring(MassPoint& anchor, MassPoint& exterior);//anchor-exterior	
	
	void		Update();




private:
	MassPoint&	_Anchor, 
			 &	_Exterior;
	MathVector  _Spring;
	float		_SpringLenght,
				_K,
				_Damping,
				_TimeSP;

		//variables de transicion
	float		_SpringForce,
				_DampForce,
				_Accel,
				_Vel,
				_Force;
					
};

