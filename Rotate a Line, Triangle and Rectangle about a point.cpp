#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw original line, triangle and rectangle
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
        glVertex2f(-0.8, 0.6);
        glVertex2f(-0.3, 0.6);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7, 0.2);
        glVertex2f(-0.3, 0.2);
        glVertex2f(-0.5, 0.6);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(0.1, 0.2);
        glVertex2f(0.6, 0.2);
        glVertex2f(0.6, 0.6);
        glVertex2f(0.1, 0.6);
    glEnd();

    // Rotate all objects about the origin (0,0)
    glPushMatrix();
    glRotatef(45.0, 0.0, 0.0, 1.0);

    glColor3f(1.0, 0.0, 0.0);

    // Rotated line
    glBegin(GL_LINES);
        glVertex2f(-0.8, 0.6);
        glVertex2f(-0.3, 0.6);
    glEnd();

    // Rotated triangle
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7, 0.2);
        glVertex2f(-0.3, 0.2);
        glVertex2f(-0.5, 0.6);
    glEnd();

    // Rotated rectangle
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.1, 0.2);
        glVertex2f(0.6, 0.2);
        glVertex2f(0.6, 0.6);
        glVertex2f(0.1, 0.6);
    glEnd();

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
    glutCreateWindow("Rotation of Line, Triangle and Rectangle");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
