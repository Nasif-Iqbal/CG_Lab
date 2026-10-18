#include <GL/glut.h>
#include <iostream>
using namespace std;

const float xmin = -0.5, ymin = -0.5;
const float xmax =  0.5, ymax =  0.5;

int code(float x, float y)
{
    int c = 0;

    if (x < xmin) c |= 1;
    if (x > xmax) c |= 2;
    if (y < ymin) c |= 4;
    if (y > ymax) c |= 8;

    return c;
}

void clipLine(float x1, float y1, float x2, float y2)
{
    int c1 = code(x1, y1);
    int c2 = code(x2, y2);

    while (true)
    {
        if (!(c1 | c2))
        {
            glColor3f(0, 1, 0);
            glBegin(GL_LINES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glEnd();
            break;
        }
        else if (c1 & c2)
        {
            break;
        }
        else
        {
            float x, y;
            int c = c1 ? c1 : c2;

            if (c & 8)
            {
                x = x1 + (x2 - x1) *
                    (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (c & 4)
            {
                x = x1 + (x2 - x1) *
                    (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (c & 2)
            {
                y = y1 + (y2 - y1) *
                    (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2 - y1) *
                    (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (c == c1)
            {
                x1 = x;
                y1 = y;
                c1 = code(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                c2 = code(x2, y2);
            }
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Clipping window
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    // Original line in red
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-0.8, -0.7);
    glVertex2f(0.8, 0.7);
    glEnd();

    // Clipped line in green
    clipLine(-0.8, -0.7, 0.8, 0.7);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Cohen Sutherland Line Clipping");

    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-1, 1, -1, 1);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
