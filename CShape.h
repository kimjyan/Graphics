#pragma once
#include <gl/glut.h>

#pragma comment( lib, "glut32.lib"  )

class CShape
{
public:
	CShape() {};
	~CShape() {};
public:
	virtual void Draw() = 0;
	virtual void mouse(int button, int state, int x, int y) = 0;
	virtual void motion(int x, int y) = 0;
};
