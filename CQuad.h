#pragma once
#include "CShape.h"

class CQuad : public CShape
{
public:
	CQuad();
	~CQuad();
private:
	bool ismouse_down;


public:
	void Draw();
	void mouse(int button, int state, int x, int y);
	void motion(int x, int y);
};

CQuad::CQuad()
{
	start_x = 0;
	start_y = 0;
	end_x = 0;
	end_y = 0;
	ismouse_down = false;
}

CQuad::~CQuad()
{

}

void CQuad::Draw()
{
	glColor3d(RGB[0], RGB[1], RGB[2]);
	glBegin(GL_QUADS);
		glVertex2f(start_x, start_y);
		glVertex2f(start_x, end_y);
		glVertex2f(end_x, end_y);
		glVertex2f(end_x, start_y);		
	glEnd(); 
}

void CQuad::mouse(int button, int state, int x, int y)
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

void CQuad::motion(int x, int y)
{
	if (ismouse_down)
	{
		end_x = x;
		end_y = y;
	}
}