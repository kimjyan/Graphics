#include <list>
#include <iostream>
#include "CShape.h"
#include "CLine.h"
#include "CQuad.h"
#include <gl/glut.h>

#pragma comment( lib, "glut32.lib"  )

using namespace std;

void initialize();
void finalize();

// glut callback functions
void reshape(int w, int h);
void display();
void idle();
void finalize();
void timer(int timer_id);

void keyboard(unsigned char key, int x, int y);
void special(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);

//
unsigned int win_width = 800;
unsigned int win_height = 600;
float win_aspect_ratio = ((float)win_width / (float)win_height);
unsigned int time_interval = 1;

bool ismouse_down = false;
bool triger = false;
std::list<CShape*> shape_list;
std::list<CShape*>::iterator itor;

int type = 1;

//
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(win_width, win_height);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("GLUT Template");

	// call-back initialization
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutTimerFunc(time_interval, timer, 1);

	initialize();
	glutMainLoop();
}

void initialize()
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void finalize()
{
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// WRITE YOUR DRAWING CODE FROM HERE ...

	glBegin(GL_TRIANGLES);
		glColor3d(1.0, 0.0, 0.0);
		glVertex2d(100, 100);
		glVertex2d(200, 100);
		glVertex2d(100, 200);
	glEnd();
	for (itor = shape_list.begin(); itor != shape_list.end(); itor++)
	{
		CShape* shape = (CLine*)*itor;
		shape->Draw();
	}
	// ... TO HERE

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	win_width = w;
	win_height = h;
	win_aspect_ratio = (float)h / (float)w;

	//
	glViewport(0, 0, win_width, win_height);

	glMatrixMode(GL_PROJECTION);      // Projection transformation
	glLoadIdentity();
	glOrtho(0, win_width, win_height, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void timer(int timer_id)
{
	glutTimerFunc(time_interval, timer, timer_id);
	glutPostRedisplay();
}

void idle()
{
	
}

void keyboard(unsigned char key, int x, int y)
{

}

void special(int key, int x, int y)
{

}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{ 
		triger = true;
		if (state == GLUT_DOWN)
		{
			CShape* shape;
			if (type == 0)
				shape = new CLine();
			else shape = new CQuad();
			shape->mouse(button, state, x, y);
			shape_list.push_back(shape);
			ismouse_down = true;
		}
		else
		{
			ismouse_down = false;
		}
	}
}

void motion(int x, int y)
{
	if (ismouse_down = true)
	{
		CShape* shape = (CLine*)shape_list.back();;
		shape->motion(x, y);
	}
}
