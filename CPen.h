#pragma once

#include "CShape.h"
#include <list>

typedef struct Point
{
	float x;
	float y;
} mousePoint;


class CPen : public CShape
{
public:
	CPen();
	~CPen();
public:
	void Draw();
	void mouse(int button, int state, int x, int y);
	void motion(int x, int y);

private:
	std::list<mousePoint> point_list;
	std::list<mousePoint>::iterator point_itor;
	mousePoint stPoint;
	bool ismouse_down;
};

CPen::CPen()
{
	stPoint.x = 0;
	stPoint.y = 0;

	ismouse_down = false;
}

CPen::~CPen()
{

}

void CPen::Draw()
{
	glColor3d(RGB[0], RGB[1], RGB[2]);

	glBegin(GL_LINE_STRIP);
		for (point_itor = point_list.begin(); point_itor != point_list.end(); point_itor++)
		{
			mousePoint p = (mousePoint)*point_itor;
			glVertex2f(p.x, p.y);
		}
	glEnd();
}

void CPen::mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			stPoint.x = x;
			stPoint.y = y;

			point_list.push_back(stPoint);

			ismouse_down = true;
		}
		else
		{
			ismouse_down = false;
		}
	}
}

void CPen::motion(int x, int y)
{
	if (ismouse_down)
	{
		stPoint.x = x;
		stPoint.y = y;

		point_list.push_back(stPoint);
	}
}
