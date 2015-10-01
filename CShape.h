#pragma once

#include <math.h>
#include <gl/glut.h>

#pragma comment( lib, "glut32.lib"  )

class CShape
{
public:
	CShape() {};
	~CShape() {};

protected:
	float start_x;
	float start_y;
	float end_x;
	float end_y;

	double RGB[3];

public:
	virtual void Draw() = 0;
	virtual void mouse(int button, int state, int x, int y) = 0;
	virtual void motion(int x, int y) = 0;

public:
	void setColor(double R, double G, double B) { RGB[0] = R;  RGB[1] = G; RGB[2] = B; };
};
