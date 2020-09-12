#include "obj3.h"

//modelagen de uma casa quadrado e piramide

obj3::obj3()
{
    nome = "obj3";
}

void obj3::desenha()
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
            glVertex3f(0.3,0,1);
            glVertex3f(0.7,0,1);
            glVertex3f(0.7,2,1);
            glVertex3f(0.3,2,1);
        glEnd();
        //frente esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,1);
            glVertex3f(0,0,0.7);
            glVertex3f(0.3,0,1);
            glVertex3f(0.3,2,1);
            glVertex3f(0,2,0.7);
        glEnd();
        //tras
        glBegin(GL_QUADS);
            glNormal3f(0,0,-1);
            glVertex3f(0.3,0,0);
            glVertex3f(0.3,2,0);
            glVertex3f(0.7,2,0);
            glVertex3f(0.7,0,0);
        glEnd();
        //tras direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,-1);
            glVertex3f(0.7,0,0);
            glVertex3f(0.7,2,0);
            glVertex3f(1,2,0.3);
            glVertex3f(1,0,0.3);
        glEnd();
        //tras esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,-1);
            glVertex3f(0,0,0.3);
            glVertex3f(0,2,0.3);
            glVertex3f(0.3,2,0);
            glVertex3f(0.3,0,0);
        glEnd();
        //face direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,0);
            glVertex3f(1,0,0.3);
            glVertex3f(1,2,0.3);
            glVertex3f(1,2,0.7);
            glVertex3f(1,0,0.7);
        glEnd();
        //face frente direita
        glBegin(GL_QUADS);
            glNormal3f(1,0,1);
            glVertex3f(0.7,0,1);
            glVertex3f(1,0,0.7);
            glVertex3f(1,2,0.7);
            glVertex3f(0.7,2,1);
        glEnd();
        //face esquerda
        glBegin(GL_QUADS);
            glNormal3f(-1,0,0);
            glVertex3f(0,0,0.3);
            glVertex3f(0,0,0.7);
            glVertex3f(0,2,0.7);
            glVertex3f(0,2,0.3);
        glEnd();
        //cima
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0.7,2,1);
            glVertex3f(1,2,0.7);
            glVertex3f(1,2,0.3);
            glVertex3f(0.7,2,0);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0.7,2,1);
            glVertex3f(0.7,2,0);
            glVertex3f(0.3,2,0);
            glVertex3f(0.3,2,1);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(0,1,0);
            glVertex3f(0.3,2,0);
            glVertex3f(0,2,0.3);
            glVertex3f(0,2,0.7);
            glVertex3f(0.3,2,1);
        glEnd();

        //baixo
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0.7,0,1);
            glVertex3f(0.7,0,0);
            glVertex3f(1,0,0.3);
            glVertex3f(1,0,0.7);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0.7,0,1);
            glVertex3f(0.3,0,1);
            glVertex3f(0.3,0,0);
            glVertex3f(0.7,0,0);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(0,-1,0);
            glVertex3f(0.3,0,0);
            glVertex3f(0.3,0,1);
            glVertex3f(0,0,0.7);
            glVertex3f(0,0,0.3);
        glEnd();

        //telhado frente
        glBegin(GL_POLYGON);
            glNormal3f(0,0,1);
            glVertex3f(0.3,2,1);
            glVertex3f(0.7,2,1);
            glVertex3f(0.5,3,0.5);
        glEnd();
        //telhado frente esquerda
        glBegin(GL_POLYGON);
            glNormal3f(-1,0,1);
            glVertex3f(0.3,2,1);
            glVertex3f(0.5,3,0.5);
            glVertex3f(0,2,0.7);
        glEnd();
        //telhado tras
        glBegin(GL_POLYGON);
            glNormal3f(0,0,-1);
            glVertex3f(0.3,2,0);
            glVertex3f(0.5,3,0.5);
            glVertex3f(0.7,2,0);
        glEnd();
        //telhado tras direita
        glBegin(GL_POLYGON);
            glNormal3f(1,0,-1);
            glVertex3f(0.7,2,0);
            glVertex3f(0.5,3,0.5);
            glVertex3f(1,2,0.3);
        glEnd();
        //telhado tras esquerda
        glBegin(GL_POLYGON);
            glNormal3f(-1,0,-1);
            glVertex3f(0,2,0.3);
            glVertex3f(0.5,3,0.5);
            glVertex3f(0.3,2,0);
        glEnd();
        //telhado direita
        glBegin(GL_POLYGON);
            glNormal3f(1,0,0);
            glVertex3f(1,2,0.3);
            glVertex3f(0.5,3,0.5);
            glVertex3f(1,2,0.7);
        glEnd();
        //telhado frente direita
        glBegin(GL_POLYGON);
            glNormal3f(1,0,1);
            glVertex3f(1,2,0.7);
            glVertex3f(0.5,3,0.5);
            glVertex3f(0.7,2,1);
        glEnd();
        //telhado esquerda
        glBegin(GL_POLYGON);
            glNormal3f(-1,0,0);
            glVertex3f(0,2,0.7);
            glVertex3f(0.5,3,0.5);
            glVertex3f(0,2,0.3);
        glEnd();

    glPopMatrix();
}
