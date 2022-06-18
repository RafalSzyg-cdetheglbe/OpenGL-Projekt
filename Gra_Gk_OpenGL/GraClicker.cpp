#include <iostream>
#include<GL/glut.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int x, y;
int color = 255;
int l = 0;
void mous(int button, int state, int mousex, int mousey)
{
	if (button == GLUT_LEFT_BUTTON && stat == GLUT_DOWN)
	{
		x = mousex;
		y = 480 - mousey;
	}
}
class Pamiec 
{
private:
	int x;
	int y;
	int length;
	bool czyCzerwony;
public:
	Pamiec(int x, int y, int length) {
		this->x = x;
		this->y = y;
		this->length = length;
}
};
void GLinit();
void myDisplayFunc();
void rysujKwadrat(int x1, int y1, int sidelength);


int main()
{
	srand(time(0));
	GLFWwindow* window;
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Grafika Komputerowa",NULL, NULL);
	glfwMakeContextCurrent(window);
	glutInit(&__argc, __argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Grafika Komputerowa");

	GLinit();
	
	
	 glutDisplayFunc(myDisplayFunc);
	
	
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
	//std::cout << l;
	std::cout << x << " : " << y<<" ";
	if (l % 5 == 0)color = 0;
	else { color = 255; }
	x = x = rand() % 1000;
	y = y = rand() % 1000;
	if(l>2)
	rysujKwadrat(x, y, 100);
	
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


void gra() {

}

