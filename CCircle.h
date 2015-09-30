#pragma once

#include "CShape.h"

class CCircle : public CShape
{
public:
	CCircle();
	~CCircle();

private:
	bool ismouse_down;

	float radius;
	float start_x;
	float start_y;
	float end_x;
	float end_y;
public:
	void Draw();
	void mouse(int button, int state, int x, int y);
	void motion(int x, int y);
};

CCircle::CCircle()
{
}

CCircle::~CCircle()
{
}

void CCircle::Draw()
{
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(start_x, start_y);
		for (int i = 0; i < 12; i++)
		{
			glVertex2f(start_x, start_y);
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
	}
}