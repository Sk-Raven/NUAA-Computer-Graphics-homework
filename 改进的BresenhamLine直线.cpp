// ConsoleApplication4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"



#include <GL/glut.h>  
#include <iostream>  
#include <cmath>
#include<Windows.h>
#include"stdafx.h"
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
using namespace std;



void display()
{
	int x0 = 0, y0 = 0, x1 = 150, y1 = 100;
	int x = x0, y = y0;
	int dx = x1 - x0;
	int dy = y1 - y0;
	int e = -dx;
	

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	while (x <= x1) {
		glVertex2i(x, y);
		x++;
		e = e + 2 * dy;
		if (e > 0)
		{
			y++;
			e = e - 2 * dx;
		}

		
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Bresenham Draw Line");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);;
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

