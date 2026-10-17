#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(3.0);

    int xc = 250, yc = 250;
    int r = 100;

    glBegin(GL_POINTS);

    for (int angle = 0; angle <= 180; angle++)
    {
        float rad = angle * PI / 180.0;

        int x = round(xc + r * cos(rad));
        int y = round(yc + r * sin(rad));

        glVertex2i(x, y);
    }

    glEnd();
    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Arc Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
