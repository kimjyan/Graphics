#pragma once

#include "CShape.h"

#define PI 3.141592

class CCircle : public CShape
{
public:
	CCircle();
	~CCircle();

private:
	bool ismouse_down;

	float radius;


public:
	void Draw();
	void mouse(int button, int state, int x, int y);
	void motion(int x, int y);
};

CCircle::CCircle()
{
	radius = 0;
}

CCircle::~CCircle()
{
}

void CCircle::Draw()
{
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glColor3d(RGB[0], RGB[1], RGB[2]);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(start_x, start_y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				start_x + (radius * cos(i *  twicePi / triangleAmount)),
				start_y + (radius * sin(i * twicePi / triangleAmount))
				);
		}
	glEnd();
}

void CCircle::mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			start_x = x;
			start_y = y;
			end_x = x;
			end_y = y;

			ismouse_down = true;
		}
		else
		{
			ismouse_down = false;
		}
	}
}

void CCircle::motion(int x, int y)
{
	if (ismouse_down)
	{
		end_x = x;
		end_y = y;

		float disX = start_x - end_x;
		float disY = start_y - end_y;

		radius = sqrtf(abs(disX * disX) + abs(disY * disY));
	}
}