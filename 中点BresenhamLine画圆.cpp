#include<GL/glut.h>  
#include<iostream>  
#include"stdafx.h"
#include<Windows.h>
#include<gl\glut.h>
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
using namespace std;
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0f, 0.0f);
	glBegin(GL_POINTS);
	int r = 200;
	int x = 0, y = r,d = 1 - r;
	while (x <= y)
	{
		glVertex2i(x, y);
		glVertex2i(-x, y);
		glVertex2i(x, -y);
		glVertex2i(-x, -y);
		glVertex2i(y, x);
		glVertex2i(-y, x);
		glVertex2i(y, -x);
		glVertex2i(-y, -x);
		if (d < 0)
			d += 2 * x + 3;
		else {
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;

	}

	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("MidBresenhamCircle");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0, 800.0, -500.0, 800.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}