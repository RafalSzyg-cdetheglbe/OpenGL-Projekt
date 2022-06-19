#include <iostream>
#include<GL/glut.h>
#include <GLFW/glfw3.h>


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int x, y;
int MouseX, MouseY;
int color = 255;
int l = 0;
int IloscPunktow = 0;

void rysujKwadrat(int x1, int y1, int sidelength);
void ZamalujKwadrat(int x1, int y1, int sidelength);
void RysujLinie();

class Linia {
public:
	void rysuj() {
		glBegin(GL_LINES);
		glVertex2f(0, 500);
		glVertex2f(1000, 500);
		glEnd();
}
};

class Pamiec 
{
private:
	int x=0;
	int y=0;
	int length=100;
	bool czyCzerwony = false;

public:
	Pamiec(int x, int y, int length, bool czyCzerwony) {
		this->x = x;
		this->y = y;
		this->length = length;
		this->czyCzerwony = czyCzerwony;


}

	void rysuj() 
	{
		if (this->czyCzerwony == true)color = 0;
		else color = 255;
		rysujKwadrat(this->x, this->y, this->length);
}

	void zamaluj() {
		ZamalujKwadrat(this->g_x(), this->g_y(), 100);
	}


void s_x(int x)
{
	this->x = x;
}
int g_x()
{
	return this->x;
}
void s_y(int y)
{
	this->y = y;
}
int g_y()
{
	return this->y;
}

};

void GLinit();
void myDisplayFunc();

Pamiec p1{ rand() % 1000,rand() % 399,100,false };
Pamiec p2{ rand() % 1000,rand() % 399,100,true };
Pamiec p3{ rand() % 1000,rand() % 399,100,false };
Pamiec p4{ rand() % 1000,rand() % 399,100,false };
Linia l1;

int main()
{
	srand(time(0));
	glutInit(&__argc, __argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Grafika Komputerowa");

	GLinit();
	
	 glutDisplayFunc(myDisplayFunc);

	 p1.rysuj();

	 p2.rysuj();
	 
	 p3.rysuj();

	 p4.rysuj();

	 l1.rysuj();

	glutMainLoop();
}

void GLinit()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1000, 0, 1000);
}

void myDisplayFunc() {

	l1.rysuj();
	l++;
	POINT p;
	if (GetCursorPos(&p)) {
		MouseX = p.x;
		MouseY = p.y;
	}



	
	if (MouseX > p1.g_x() - 100 && MouseX <p1.g_x() + 100 && MouseY > p1.g_y() - 100 && MouseY < p1.g_y() + 100) {
		p1.zamaluj(); p1.s_x(rand() % 1000); p1.s_y(rand() % 399); p1.rysuj(); IloscPunktow++;
	}

	else if (MouseX > p2.g_x() - 100 && MouseX < p2.g_x() + 100 && MouseY > p2.g_y() - 100 && MouseY < p2.g_y() + 100) {
		p2.zamaluj(); p2.s_x(rand() % 1000); p2.s_y(rand() % 399); p2.rysuj(); std::cout << "Ilosc zdobytych punktow:" << IloscPunktow << std::endl; exit(1);
	}

	else if (MouseX > p3.g_x() - 100 && MouseX < p3.g_x() + 100 && MouseY > p3.g_y() - 100 && MouseY < p3.g_y() + 100) {
		p3.zamaluj(); p3.s_x(rand() % 1000); p3.s_y(rand() % 399); p3.rysuj(); IloscPunktow++;
	}

	else if (MouseX > p4.g_x() - 100 && MouseX < p4.g_x() + 100 && MouseY > p4.g_y() - 100 && MouseY < p4.g_y() + 100) {
		p4.zamaluj(); p4.s_x(rand() % 1000); p4.s_y(rand() % 399); p4.rysuj(); IloscPunktow++;
	}
	
	glFlush();
}

void rysujKwadrat(int x1, int y1, int sidelength) {
	double halfside = sidelength / 2;

	glColor3d(255, 0, color);
	glBegin(GL_POLYGON);

	glVertex2d(x1 + halfside, y1 + halfside);
	glVertex2d(x1 + halfside, y1 - halfside);
	glVertex2d(x1 - halfside, y1 - halfside);
	glVertex2d(x1 - halfside, y1 + halfside);

	glEnd();
}

void ZamalujKwadrat(int x1, int y1, int sidelength) {
	double halfside = sidelength / 2;

	glColor3d(0,0, 0);
	glBegin(GL_POLYGON);

	glVertex2d(x1 + halfside, y1 + halfside);
	glVertex2d(x1 + halfside, y1 - halfside);
	glVertex2d(x1 - halfside, y1 - halfside);
	glVertex2d(x1 - halfside, y1 + halfside);

	glEnd();
}




void gra() {

}

