#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265

void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * PI / 180.0;
        glVertex2f(cx + r * cos(angle),
                   cy + r * sin(angle));
    }
    glEnd();
}

void drawTriangle()
{
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.7, -0.1);
        glVertex2f(-0.3, -0.1);
        glVertex2f(-0.5, 0.3);
    glEnd();
}

void drawRectangle()
{
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.1, -0.2);
        glVertex2f(0.5, -0.2);
        glVertex2f(0.5, 0.2);
        glVertex2f(0.1, 0.2);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Original shapes in blue
    glColor3f(0.0, 0.0, 1.0);

    drawCircle(0.0, 0.6, 0.15);
    drawTriangle();
    drawRectangle();

    // Magnify about fixed point (0, 0)
    glPushMatrix();

    // Translate to origin, scale, then translate back
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(1.5, 1.5, 1.0);

    glColor3f(1.0, 0.0, 0.0);

    drawCircle(0.0, 0.6, 0.15);
    drawTriangle();
    drawRectangle();

    glPopMatrix();

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Magnification of Circle, Triangle and Rectangle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
