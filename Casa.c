#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(void);
void display(void);

void casa(void){


    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);//Parede 1
        glVertex2f(100.0,20.0);
        glVertex2f(130.0,20.0);
        glVertex2f(130.0,45.0);
        glVertex2f(115.0,60.0);
        glVertex2f(100.0,45.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);//parede 2
        glVertex2f(130.0,20.0);
        glVertex2f(180.0,20.0);
        glVertex2f(180.0,45.0);
        glVertex2f(130.0,45.0);
    glEnd();

    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_POLYGON);//telhado
        glVertex2f(130.0,45.0);
        glVertex2f(180.0,45.0);
        glVertex2f(165.0,60.0);
        glVertex2f(115.0,60.0);
    glEnd();

    glColor3f(1.0, 0.2, 0.0);
    glBegin(GL_POLYGON);//porta
        glVertex2f(110.0,20.0);
        glVertex2f(120.0,20.0);
        glVertex2f(120.0,35.0);
        glVertex2f(110.0,35.0);
    glEnd();

    glColor3f(0.7, 0.0, 0.0);
    glBegin(GL_POLYGON);//maçaneta
        glVertex2f(117.0,25.0);
        glVertex2f(119.0,25.0);
        glVertex2f(119.0,28.0);
        glVertex2f(117.0,28.0);
    glEnd();

    glColor3f(1.0, 0.2, 0.0);
    glBegin(GL_POLYGON);//janela 1
        glVertex2f(140.0,25.0);
        glVertex2f(150.0,25.0);
        glVertex2f(150.0,35.0);
        glVertex2f(140.0,35.0);
    glEnd();

    glColor3f(1.0, 0.2, 0.0);
    glBegin(GL_POLYGON);//janela 2
        glVertex2f(160.0,25.0);
        glVertex2f(170.0,25.0);
        glVertex2f(170.0,35.0);
        glVertex2f(160.0,35.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);//solo
        glVertex2f(50.0,0.0);
        glVertex2f(230.0,0.0);
        glVertex2f(230.0,20.0);
        glVertex2f(50.0,20.0);
    glEnd();

    glColor3f(0.7, 0.3, 0.0);
    glBegin(GL_POLYGON);//tronco
        glVertex2f(205.0,20.0);
        glVertex2f(210.0,20.0);
        glVertex2f(210.0,30.0);
        glVertex2f(205.0,30.0);
    glEnd();


    glColor3f(0.0, 0.4, 0.0);
    glBegin(GL_POLYGON);//arvore
        glVertex2f(190.0,30.0);
        glVertex2f(225.0,30.0);
        glVertex2f(207.5,70.0);
    glEnd();

    int i;
    for(i = 1;i<10;i++){
    glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glRotatef(10*i,0,0,1);
        glTranslatef(30*i,-50*i,0);
        glBegin(GL_POLYGON);//sol
            glVertex2f(180.0,130.0);
            glVertex2f(200.0,130.0);
            glVertex2f(200.0,150.0);
            glVertex2f(180.0,150.0);
        glEnd();
    glPopMatrix();
    }
}


int main( int argc, char** argv ){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500 ,500);
    glutInitWindowPosition(500,100);
    glutCreateWindow("Desenhando uma casa");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 1;
}

void init(void){
    glClearColor(0.0, 0.9, 0.7, 0.1);
    glOrtho(0, 256, 0, 256, -1,1);
}

void display(void){
    srand(time(NULL));

    glClear(GL_COLOR_BUFFER_BIT);

//    glTranslatef(-5,0,0);
    casa();

    glFlush();
}

