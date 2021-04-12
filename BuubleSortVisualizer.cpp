#include<GL/glut.h>
#include<iostream>
using namespace std;

//All the variables
const int HEIGHT = 200;
const int WIDTH = 200;
float* values;
int i = 0, j = 0;

//Code
float RandomFloatGenerator(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

void swap(int a, int b) {
	float temp = values[a];
	values[a] = values[b];
	values[b] = temp;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0.0, 1.0);
	glBegin(GL_LINES);
	if (values[j] > values[j + 1]) {
		swap(j, j + 1);
	}
	if (i < WIDTH) {
		j++;
		if (j >= WIDTH - i - 1) {
			j = 0;
			i++;
		}
	}
	for (int k = 0; k < WIDTH; k++) {
		glVertex2f((float)k, (float)HEIGHT);
		glVertex2f((float)k, (float)HEIGHT - values[k]);
	}	
	glEnd();
	glutSwapBuffers();
}

void myinit() {
	glClearColor(0, 0, 0, 0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000/100, timer, 0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	values = new float[WIDTH];
	for (int i = 0; i < WIDTH; i++) {
		values[i] = RandomFloatGenerator(0.0, (float)HEIGHT);
	}
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Buuble Sort");
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	myinit();
	glutMainLoop();
}
