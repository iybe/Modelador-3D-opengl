#include "house2.h"

house2::house2()
{
    model = new Model3DS("3ds/house2.3DS");
    nome = "house2";
}

void house2::desenha()
{
    glPushMatrix();
        Objeto::desenha();
        if(selecionado){
            glEnable(GL_CULL_FACE);
            GUI::drawBox(-1, -1, -1, 1, 1, 1, true);
        }
        if(desenhar_sist_coord){
            GUI::drawOrigin(1);
        }
        glScalef(2,2,2); //ajuste final da escala podendo ser não uniforme, independente para cada eixo
        glRotatef(-90,1,0,0); //alinhar o objeto 3ds com os eixos, deixando ele para cima de acordo com o eixo
        glTranslatef(0,0,0); //trazer objeto 3ds para origem
        glScalef(0.001,0.001,0.001); //apenas para conseguir enxergar o objeto 3ds
        model->draw();
    glPopMatrix();
}
