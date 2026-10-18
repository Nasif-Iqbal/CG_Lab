#include <GL/glut.h>
#include <cmath>

float x = -0.8;
float speed = 0.01;

void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);

    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.14159 / 180.0;

        glVertex2f(cx + r * cos(angle),
                   cy + r * sin(angle));
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw ground
    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINES);
        glVertex2f(-1.0, -0.5);
        glVertex2f(1.0, -0.5);
    glEnd();

    // Draw moving ball
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(x, 0.0, 0.1);

    glFlush();
}

void update(int value)
{
    x += speed;

    // Reverse direction at boundaries
    if (x > 0.9 || x < -0.9)
        speed = -speed;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
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

    glutCreateWindow("Drawing Objects and Animation");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}
