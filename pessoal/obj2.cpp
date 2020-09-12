#include "obj2.h"

//modelagen de uma casa quadrado e piramide

obj2::obj2()
{
    nome = "obj2";
}

void obj2::desenha()
{
    glPushMatrix();
        Objeto::desenha();

        if (selecionado) {
            GUI::setColor(0,0,1);
        } else {
            GUI::setColor(1,1,0);
        }

        if(desenhar_sist_coord){
            GUI::drawOrigin(1.5);
        }

        //frente
        glBegin(GL_QUADS);
            glNormal3f(0,0,1);
            glVertex3f(0,0,1);
            glVertex3f(1,0,1);
            glVertex3f(1,1,1);
            glVertex3f(0,1,1);
        glEnd();
        //tras
        glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            glVertex3f(0,0,0);
            glVertex3f(0,1,0);
            glVertex3f(1,1,0);
            glVertex3f(1,0,0);
        glEnd();
        //face direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(1,0,0);
            glVertex3f(1,1,0);
            glVertex3f(1,1,1);
        glEnd();
        //face esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            glVertex3f(0,0,1);
            glVertex3f(0,1,1);
            glVertex3f(0,1,0);
            glVertex3f(0,0,0);
        glEnd();
        //face superior
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(-0.2,1,-0.2);
            glVertex3f(1.2,1,-0.2);
            glVertex3f(1.2,1,1.2);
            glVertex3f(-0.2,1,1.2);
        glEnd();
        //face inferior
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0,0,0);
            glVertex3f(1,0,0);
            glVertex3f(1,0,1);
            glVertex3f(0,0,1);
        glEnd();
        //telhado
        //esquerda
        glBegin(GL_POLYGON);
            glNormal3f(-1,0,0);
            glVertex3f(-0.2,1,-0.2);
            glVertex3f(-0.2,1,1.2);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //frente
        glBegin(GL_POLYGON);
            glNormal3f(0,0,1);
            glVertex3f(-0.2,1,1.2);
            glVertex3f(1.2,1,1.2);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //direita
        glBegin(GL_POLYGON);
            glNormal3f(0,0,1);
            glVertex3f(1.2,1,1.2);
            glVertex3f(1.2,1,-0.2);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
        //tras
        glBegin(GL_POLYGON);
            glNormal3f(0,0,1);
            glVertex3f(1.2,1,-0.2);
            glVertex3f(-0.2,1,-0.2);
            glVertex3f(0.5,1.5,0.5);
        glEnd();
    glPopMatrix();
}
