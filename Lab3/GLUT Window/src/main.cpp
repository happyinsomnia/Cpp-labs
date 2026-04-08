#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <glut.h>

void display();

void init()
{
	glClearColor(1.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("GLUT + OpenGL Test");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // красный
    glVertex2f(-0.5f, -0.5f);

    glColor3f(0.0f, 1.0f, 0.0f); // зелёный
    glVertex2f(0.5f, -0.5f);

    glColor3f(0.0f, 0.0f, 1.0f); // синий
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush();
}