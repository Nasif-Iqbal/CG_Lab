#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(3.0);

    glBegin(GL_POINTS);

    for (float x = -200; x <= 200; x += 1)
    {
        float y = 0.01 * x * x;
        glVertex2f(x, y);
    }

    glEnd();
    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-250, 250, -50, 450);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polynomial Line Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
