#include <iostream>
#include<GL/glut.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int x, y;
int Mousex, Mousey;
int color = 255;
int l = 0;
void rysujKwadrat(int x1, int y1, int sidelength);
void ZamalujKwadrat(int x1, int y1, int sidelength);

void mous(int button, int state, int mousex, int mousey)
{
	if (button == GLUT_LEFT_BUTTON && stat == GLUT_DOWN)
	{
		Mousex = mousex;
		Mousey = 480 - mousey;
	}
}
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

Pamiec p1{ rand() % 1000,rand() % 1000,100,false };
Pamiec p2{ rand() % 1000,rand() % 1000,100,true };
Pamiec p3{ rand() % 1000,rand() % 1000,100,false };
Pamiec p4{ rand() % 1000,rand() % 1000,100,false };

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
	l++;

	std::cout << Mousex << " : " << Mousey << " " << std::endl;

	if (l % 5 == 0) //ZAMIAST TEGO MA BYC SPRAWDZENIE CZY BYLO KLIKNIETE W KWADRAT TJ. X I Y  MYSZKI MIESZCZCZA SIE W PRZEDIALE KWADRATU
	{
		p1.zamaluj(); p1.s_x(rand() % 1000); p1.s_y(rand() % 1000); p1.rysuj();
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

