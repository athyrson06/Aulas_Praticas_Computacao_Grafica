#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int posX,posY,xi,yi;

    posX = 0;
    posY = 0;
    xi = 100;
    yi = 100;

void init(void);
void display(void);

void rotateEixo(){
    glLoadIdentity();
    xi += 10;
    yi += 10;
    glOrtho(-xi, 256, -yi, 256, -1,1);

}

void keyPressed(unsigned char key, int x, int y){
    switch(key){
        case 'd':
            posX += 10;
            break;
        case 'a':
            posX -= 10;
            break;
        case 'w':
            posY += 10;
            break;
        case 's':
            posY -= 10;
            break;
        case 'p':
            glRotatef(90,0,0,1);//calcular quadrante
            break;
        case 'q':
            glTranslatef(0,20,0);//movimentaçao nao ocorre como esperado
            break;
        case 'o':
            rotateEixo();
            break;
    }

    glutPostRedisplay();
}

void retangulo(float x1, float y1, float x2, float y2){
    glBegin(GL_POLYGON);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void shape_L(float x1, float y1, int t){
    float x2 = x1+(10*t);
    float y2 = y1+(10*t);

    glColor3f(1.0, 0.0, 0.0);
    retangulo(x1,y1,x1+((x2-x1)*1/4),y1+((y2-y1)*3/4));//A0,A1,A2
    retangulo(x1+((x2-x1)*(1/4.0)),y1,x1+((x2-x1)*(2/4.0)),y1+((y2-y1)*(1/4.0)));//B0
}


void shape_O(float x1, float y1, int t){
    float x2 = x1+(10*t);
    float y2 = y1+(10*t);

    glColor3f(0.3, 1.0, 0.5);
    retangulo(x1,y1,x1+((x2-x1)*2/4),y1+((y2-y1)*2/4));//A0,A1,B0,B1
}

void shape_T(float x1, float y1, int t){
    float x2 = x1+(10*t);
    float y2 = y1+(10*t);

    glColor3f(0.0, 0.5, 0.0);
    retangulo(x1,(y1+((y2-y1)*1/4)),x1+((x2-x1)*3/4),y1+((y2-y1)*2/4));//A1,B1,C1
    retangulo(x1+((x2-x1)*(1/4.0)),y1,x1+((x2-x1)*(2/4.0)),y1+((y2-y1)*(1/4.0)));//B0
}

void shape_Z(float x1, float y1, int t){
    float x2 = x1+(10*t);
    float y2 = y1+(10*t);

    glColor3f(0.0, 0.5, 1.0);
    retangulo(x1,(y1+((y2-y1)*1/4)),x1+((x2-x1)*2/4),y1+((y2-y1)*2/4));//A1,B1,C1
    retangulo(x1+((x2-x1)*(1/4.0)),y1,x1+((x2-x1)*(3/4.0)),y1+((y2-y1)*(1/4.0)));//B0
}

void shape_I(float x1, float y1, int t){
    float x2 = x1+(10*t);
    float y2 = y1+(10*t);

    glColor3f(1.0, 1.0, 0.0);
    retangulo(x1,y1,x1+((x2-x1)*1/4),y1+((y2-y1)*4/4));//A0,A1,A2,A3
}

void space(int n){



//    shape_L(10.0,30.0,n);
//    shape_O(60.0,30.0,n);
//    shape_I(110.0,30.0,n);
//    shape_Z(10.0,80.0,n);

}


int main( int argc, char** argv ){



    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500 ,500);
    glutInitWindowPosition(500,100);
    glutCreateWindow("Formas Tetris");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutMainLoop();
    return 1;
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.1);
    glOrtho(0, 256, 0, 256, -1,1);
}

void display(void){

    glClear(GL_COLOR_BUFFER_BIT);

//   glPushMatrix();
     //   glTranslatef(100,100,0);
       // glRotatef(70,0,0,1);
        //shape_Z(15,15,10);
    //glPopMatrix();
glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f(-10, 0);
        glVertex2f(10, 0);

        glVertex2f(0, -10);
        glVertex2f(0, 10);
    glEnd();

    glPushMatrix();
    shape_L(posX,posY,10);
    glPopMatrix();
//    shape_Z(posX+20,posY,10);
//    shape_T(posX+20,posY+20,10);
//    shape_I(posX-20,posY-20,10);



//    glPushMatrix();
//        shape_T(15,15,10);
//    glPopMatrix();
//
//    glPushMatrix();
//        glScalef(0.5,0.5,0);
//        shape_L(15,15,10);
//    glPopMatrix();

    glFlush();
}

