#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(void);
void display(void);

void quadrado(int x1, int y1, int x2, int y2){
    glBegin(GL_POLYGON);
        glVertex2i(x1, y1);
        glVertex2i(x2, y1);
        glVertex2i(x2, y2);
        glVertex2i(x1, y2);
    glEnd();
}

void tabuleiro(int n){
    int i,j;

    if(n < 0){
        return;
    }

    n = n*10;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2i(20, 20);
        glVertex2i(n+20, 20);
        glVertex2i(n+20, n+20);
        glVertex2i(20, n+20);
    glEnd();

    for (i = 20; i < n+20;i+=1){
        for (j = 20; j < n+20; j+=1){
                glColor3f(rand()%70/100.0, rand()%70/100.0, rand()%70/100.0);
            if((i == j && i % 10 == 0) || (((i - j) % 20 == 0) && (j % 10 == 0)) || (((j - i) % 20 == 0) && (j % 10 == 0))){
                quadrado(i, j, i+10, j+10);
                }
            }
        }

}


int main( int argc, char** argv ){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500 ,500);
    glutInitWindowPosition(500,100);
    glutCreateWindow("Desenhando um tabuleiro");
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
    srand(time(NULL));

    glClear(GL_COLOR_BUFFER_BIT);

    tabuleiro(10);

    glFlush();
}

