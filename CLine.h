#pragma once
#include "CShape.h"

class CLine : public CShape
{
public:
	CLine();
	~CLine();
private:
	bool ismouse_down;

public:
	void Draw();
	void mouse(int button, int state, int x, int y);
	void motion(int x, int y);
};

CLine::CLine()
{
	start_x = 0;
	start_y = 0;

	end_x = 0;
	end_y = 0;

	ismouse_down = false;
}

CLine::~CLine()
{
}

void CLine::Draw()
{
	glColor3d(RGB[0], RGB[1], RGB[2]);
		glBegin(GL_LINES);
		glVertex2d(start_x, start_y);
		glVertex2d(end_x, end_y);
	glEnd();
}

void CLine::mouse(int button, int state, int x, int y)
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

void CLine::motion(int x, int y)
{
	if (ismouse_down)
	{
		end_x = x;
		end_y = y;
	}
}