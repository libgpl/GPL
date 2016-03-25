#include "Rigidbody.hpp"
#include <cmath>


Rigidbody::Rigidbody()
: v(1.0), m(0.0), b(0), ax(0),ay(0),  is_grounded(true)
{
	//m = massa;						// massa 
	//v = velocidade;
	//b = atrito;						// coeficiente de atrito 

	h = 0.01;					// intervalo de tempo 
	s = 100;						// escala (pixel / unid. compr.) 

	shoot(-90);

}

Rigidbody::~Rigidbody(void)
{
}


void Rigidbody::shoot(float speed, float angle)
{
	v = speed;
	if(is_grounded == true)
	{
		is_grounded = false;
		vx = v * cos(angle*PI/180);		// velocidade de x
		vy = v * sin(angle*PI/180) ;	// velocidade de y
		ax = 0;
		ay = 0;
	}
}


void Rigidbody::update(float &x, float &y)
{
	if(!is_grounded)
	{
		//if(y > ground)
		//{
			// Calculo da aceleração
			ax = - b * vx / m;
			ay = - b * vy / m - g;

			x = x + (vx * h)*s;
			y = y + (vy * h)*s;
	
			vx = vx + ax * h;
			vy = vy + ay * h;

			//t = t + h;

			//if(y < ground)
			//{
			//	y = ground+1;
			//	is_grounded = true;
			//}
		//}
		//else
		//{
		//	is_grounded = true;
		//}
	}
}
