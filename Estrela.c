#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

void init(void);
void display(void);

void star(float p, float a, float b){
    float c,d,
          f,g;

    c = 0.5 * p;
    d = 1.54 * p;
    f = 0.8 * p;
    g = 0.59 * p;

    glLineWidth(2.0);

    glBegin(GL_LINES);
    glColor3f(0.2, 1.0, 0.0);
        glVertex2f(a, b);
        glVertex2f(a+c, b-d);

    glColor3f(0.2, 1.0, 1.0);
        glVertex2f(a+c, b-d);
        glVertex2f(a-f, b-g);

    glColor3f(0.2, 0.0, 1.0);
        glVertex2f(a-f, b-g);
        glVertex2f(a+f, b-g);

    glColor3f(1.0, 0.0, 0.0);
        glVertex2f(a+f, b-g);
        glVertex2f(a-c, b-d);

    glColor3f(1.0, 1.0, 0.0);
        glVertex2f(a-c, b-d);
        glVertex2f(a, b);
    glEnd();

}

int main( int argc, char** argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500 ,500);
    glutInitWindowPosition(500,100);
    glutCreateWindow("Desenhando uma Estrela");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 1;
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.1);
    glOrtho(0, 256, 0, 256, -1,1);
}

void display(void){
    float p,
        a,b;

    p = 100.0;
    a = 125.0;
    b = 250.0;

    glClear(GL_COLOR_BUFFER_BIT);

    star(p, a, b);

    glFlush();
}

