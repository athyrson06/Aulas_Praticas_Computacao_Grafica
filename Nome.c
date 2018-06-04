#include <GL/gl.h>
#include <GL/glut.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int main( int argc, char** argv )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640 ,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Desenhando meu nome");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 1;
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.1);
    glOrtho(0, 256, 0, 256, -1,1);
}

void display(void){
    int p;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2, 1.0, 0.0);
    glLineWidth(2.0);

    p = 1;

    //A
    glBegin(GL_LINES);
        glVertex2f(20.0, 100.0);
        glVertex2f(20.0, 150.0);


        glVertex2f(20.0, 150.0);
        glVertex2f(40.0, 150.0);


        glVertex2f(40.0, 150.0);
        glVertex2f(40.0, 100.0);


        glVertex2f(20.0, 125.0);
        glVertex2f(40.0, 125.0);
    glEnd();

    //T
    glBegin(GL_LINES);
        glVertex2f(55.0, 100.0);
        glVertex2f(55.0, 150.0);


        glVertex2f(45.0, 150.0);
        glVertex2f(65.0, 150.0);
    glEnd();

    //H
    glBegin(GL_LINES);
        glVertex2f(70.0, 100.0);
        glVertex2f(70.0, 150.0);


        glVertex2f(90.0, 100.0);
        glVertex2f(90.0, 150.0);


        glVertex2f(70.0, 125.0);
        glVertex2f(90.0, 125.0);
    glEnd();

    //Y
    glBegin(GL_LINES);
        glVertex2f(95.0, 100.0);
        glVertex2f(115.0, 150.0);


        glVertex2f(95.0, 150.0);
        glVertex2f(105.0, 125.0);
    glEnd();

    //R
    glBegin(GL_LINES);
        glVertex2f(120.0, 100.0);
        glVertex2f(120.0, 150.0);

        glVertex2f(120.0, 150.0);
        glVertex2f(140.0, 150.0);


        glVertex2f(140.0, 150.0);
        glVertex2f(140.0, 125.0);


        glVertex2f(140.0, 125.0);
        glVertex2f(120.0, 125.0);


        glVertex2f(130.0, 125.0);
        glVertex2f(140.0, 100.0);
    glEnd();

    //S
    glBegin(GL_LINES);
        glVertex2f(145.0, 100.0);
        glVertex2f(165.0, 100.0);


        glVertex2f(165.0, 100.0);
        glVertex2f(165.0, 125.0);


        glVertex2f(165.0, 125.0);
        glVertex2f(145.0, 125.0);


        glVertex2f(145.0, 125.0);
        glVertex2f(145.0, 150.0);


        glVertex2f(145.0, 150.0);
        glVertex2f(165.0, 150.0);
    glEnd();

    //O
    glBegin(GL_LINES);
        glVertex2f(170.0, 100.0);
        glVertex2f(170.0, 150.0);


        glVertex2f(170.0, 150.0);
        glVertex2f(190.0, 150.0);


        glVertex2f(190.0, 150.0);
        glVertex2f(190.0, 100.0);


        glVertex2f(190.0, 100.0);
        glVertex2f(170.0, 100.0);
    glEnd();

    //N
    glBegin(GL_LINES);
        glVertex2f(195.0, 100.0);
        glVertex2f(195.0, 150.0);


        glVertex2f(195.0, 150.0);
        glVertex2f(215.0, 100.0);


        glVertex2f(215.0, 100.0);
        glVertex2f(215.0, 150.0);

    glEnd();

    glFlush();
}



void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 27:
            exit(0);
            break;
    }
}
