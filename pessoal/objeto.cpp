#include "objeto.h"

Objeto::Objeto()
{

}

void Objeto::desenha()
{
    // T.Rz.Ry.Rs.S
    glTranslatef(t.x,t.y,t.z); // transformaçao (matriz) mais a esquerda (mais global)
    glRotatef(a.z,0,0,1);
    glRotatef(a.y,0,1,0);
    glRotatef(a.x,1,0,0);
    glScalef(s.x,s.y,s.z); // transformaçao (matriz) mais a direita (mais local)
}
