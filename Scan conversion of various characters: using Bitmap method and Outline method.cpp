#include <GL/glut.h>

void drawText(float x, float y, const char* text)
{
    glRasterPos2f(x, y);

    while (*text)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *text);
        text++;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    drawText(50, 350, "BITMAP METHOD");
    drawText(50, 300, "COMPUTER GRAPHICS");
    drawText(50, 250, "ABC 123 XYZ");

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
    glutCreateWindow("Bitmap Character Method");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
