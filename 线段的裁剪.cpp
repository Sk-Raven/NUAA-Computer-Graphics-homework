// ConsoleApplication9.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include<GL/glut.h>  
#include<stdio.h>  
#include<stdlib.h>  



float Rx0 = 0, Ry0 =0, Rx1 = 300, Ry1 = 300;
float x0 = 0, y0 = 0, x1 = 400, y1 = 400;
void LineGL(int x0, int y0, int x1, int y1) //画线函数
{
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);   
	glVertex2f(x0, y0);
	glColor3f(0.0f, 1.0f, 0.0f);  
	glVertex2f(x1, y1);      
	glEnd();                                                
}                                                           





int LBLineClipTest(float p, float q, float &umax, float &umin) {
	float r = 0.0;
	if (p < 0.0) {
		r = q / p;
		if (r > umin)
			return 0;
		else if (r < umax)
			umax = r;

	}
	else if (p > 0.0) {
		r = q / p;
		if (r < umax)
			return 0;
		else if (r < umin)
			umin = r;

	}
	else if (q < 0.0)
		return 0;
	return 1;


}
void LBLineClip(float xwl, float xwr, float ywb, float ywt, float &x1, float &y1, float &x2, float &y2)
{
	float umax, umin, deltax, deltay;
	deltax = x2 - x1; deltay = y2 - y1; umax = 0.0; umin = 1.0;
	if (LBLineClipTest(-deltax, x1 - xwl, umax, umin))
	{
		if (LBLineClipTest(deltax, xwr - x1, umax, umin))
		{
			if (LBLineClipTest(-deltay, y1 - ywb, umax, umin))
			{
				if (LBLineClipTest(deltay, ywt - y1, umax, umin))
				{
					x1 = int(x1 + umax*deltax + 0.5);
					y1 = int(y1 + umax*deltay + 0.5);
					x2 = int(x1 + umin*deltax + 0.5);
					y2 = int(y1 + umin*deltay + 0.5);
				}


			}


		}
	}

}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(Rx0, Ry0, Rx1, Ry1);
	LineGL((int)x0, (int)y0, (int)x1, (int)y1);
	glFlush();
}



void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);

}




int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("线段的裁剪");
	//LBLineClip(Rx0, Rx1, Ry0, Ry1, x0, y0, x1, y1);     //Liang-Barsky算法
	glutDisplayFunc(myDisplay);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	
	glutReshapeFunc(Reshape);
	
	glutMainLoop();
	return 0;
}

