#include <iostream>
#include "CShape.h"
#include "CLine.h"
#include "CQuad.h"
#include "CCircle.h"
#include "CPen.h"

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

void menu_mode(int option);
void menu_color(int option);
void menu_main(int item);

//
unsigned int win_width = 800;
unsigned int win_height = 600;
float win_aspect_ratio = ((float)win_width / (float)win_height);
unsigned int time_interval = 1;

bool ismouse_down = false;
bool triger = false;

std::list<CShape*> shape_list;
std::list<CShape*>::iterator itor;

int type = 0;
double RGB[3] = { 0, };

//
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(win_width, win_height);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("GLUT Template");

	int mode_menu = glutCreateMenu(menu_mode);
	glutAddMenuEntry("Pen", 0);
	glutAddMenuEntry("Line", 1);
	glutAddMenuEntry("Rect", 2);
	glutAddMenuEntry("Circle", 3);

	int color_menu = glutCreateMenu(menu_color);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Black", 3);

	glutCreateMenu(menu_main);
	glutAddSubMenu("Mode", mode_menu);
	glutAddSubMenu("Color", color_menu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// call-back initialization
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	//glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutTimerFunc(time_interval, timer, 1);

	initialize();
	glutMainLoop();
}

void menu_main(int item)
{
	mouse(item, item, 0, 0);
}

void menu_mode(int option)
{
	switch (option)
	{
	case 0:
		type = 0;
		break;
	case 1:
		type = 1;
		break;
	case 2:
		type = 2;
		break;
	case 3:
		type = 3;
		break;
	default:
		break;
	}
}

void menu_color(int option)
{
	switch (option)
	{
	case 0:
		RGB[0] = 1;
		RGB[1] = 0;
		RGB[2] = 0;
		break;
	case 1:
		RGB[0] = 0;
		RGB[1] = 1;
		RGB[2] = 0;
		break;
	case 2:
		RGB[0] = 0;
		RGB[1] = 0;
		RGB[2] = 1;
		break;
	case 3:
		RGB[0] = 0;
		RGB[1] = 0;
		RGB[2] = 0;
		break;
	default:
		break;
	}
}

void initialize()
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}


void display()
{
	glClearColor(1, 1, 1, 1);
	glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// WRITE YOUR DRAWING CODE FROM HERE ...


	for (itor = shape_list.begin(); itor != shape_list.end(); itor++)
	{
		CShape* shape;
		
		if (type == 1)
			shape = (CLine*)*itor;
		else if (type == 2)
			shape = (CQuad*)*itor;
		else if (type == 3)
			shape = (CCircle*)*itor;
		else if (type == 0)
			shape = (CPen*)*itor;
		
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

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{ 
		triger = true;
		if (state == GLUT_DOWN)
		{
			CShape* shape;
			if (type == 1)
				shape = new CLine();
			else if (type == 2)
				shape = new CQuad();
			else if (type == 3)
				shape = new CCircle();
			else if (type == 0)
				shape = new CPen();
			
			shape->setColor(RGB[0], RGB[1], RGB[2]);
			shape->mouse(button, state, x, y);
			shape_list.push_back(shape);

			ismouse_down = true;
		}
		else
		{
			ismouse_down = false;
		}
	}
	else ismouse_down = false;
}

void motion(int x, int y)
{
	if (ismouse_down == true)
	{
		CShape* shape;
		if (type == 1)
			shape = (CLine*)shape_list.back();
		else if (type == 2)
			shape = (CQuad*)shape_list.back();
		else if (type == 3)
			shape = (CCircle*)shape_list.back();
		else if (type == 0)
			shape = (CPen*)shape_list.back();
		shape->motion(x, y);
	}
}
