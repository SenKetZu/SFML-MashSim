#include "Spring.h"
#include "DrawAgent.h"
Spring::Spring(MassPoint& anchor, MassPoint& exterior):

	_Anchor(anchor),
	_Exterior(exterior),
	_Spring(exterior<<=anchor),
	_SpringLenght(100.0f),
	_K(10.0f),
	_Damping(1.0f),
	_TimeSP(.01f),

	//variables trancicion
	_SpringForce(0.0f),
	_DampForce(0.0f),
	_Accel(0.0f),
	_Vel(0.0f),
	_Force(0.0f)
{}

void Spring::Update()
{
	//get timesp
	_TimeSP = DrawAgent::getInstance().DeltaTime()*100.0f;

	//calcular spring
	_Spring = _Exterior <<= _Anchor;

	//calculo de fuerzas
	_SpringForce = _K * (_Spring.getMagnitude() - _SpringLenght);
	_DampForce = _Damping * _Vel;
	_Force = _SpringForce +1 /*massXgrav*/ - _DampForce;
	_Accel = _Force / 1 /*mass*/;
	_Vel += _Accel * _TimeSP;

	//push masspoint
	_Exterior.push(MathVector(_Vel*_TimeSP,_Spring.getAngle()));
}