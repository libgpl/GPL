#pragma once

const double PI = 3.141592654;
const double g = 9.8;				// aceleracao da gravidade 

class Rigidbody
{
	//int ground;		// posição do chão
	double h;		// intervalo de tempo 
	double s;		// escala (pixel / unid. compr.) 
	//double x;		// posição inicial de x
	//double y;		// posição inicial de y	  
	//double t;		// instante
	double ax;		// variável da aceleração x
	double ay;		// variável da aceleração y
	double	vx;		// velocidade de x
	double	vy;		// velocidade de y

public:
	double m;		// massa 
	double b;		// coeficiente de atrito 

	double v;		// velocidade
	bool is_grounded;
	Rigidbody();
	~Rigidbody(void);
	void shoot(float speed = 10, float angle = 90);
	void update(float &x, float &y);
};

