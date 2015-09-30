#pragma once
#include "CShape.h"

class CLine : public CShape
{
public:
	CLine();
	~CLine();
private:
	bool ismouse_down;

	float mouse_x;
	float mouse_y;

	float mosueMove_x;
	float mouseMove_y;
public:
	void Draw();
	void mouse(int button, int state, int x, int y);
	void motion(int x, int y);
};

CLine::CLine()
{
	mouse_x = 0; 
	mouse_y = 0;

	mosueMove_x = 0;
	mouseMove_y = 0;

	ismouse_down = false;
}

CLine::~CLine()
{
}

void CLine::Draw()
{
	glBegin(GL_LINES);
		glVertex2d(mouse_x, mouse_y);
		glVertex2d(mosueMove_x, mouseMove_y);
	glEnd();
}

void CLine::mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			mouse_x = x;
			mouse_y = y;
			mosueMove_x = x;
			mouseMove_y = y;

			ismouse_down = true;
		}
		else
		{
			ismouse_down = false;
		}
	}
}

void CLine::motion(int x, int y)
{
	if (ismouse_down)
	{
		mosueMove_x = x;
		mouseMove_y = y;
	}
}