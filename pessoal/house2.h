#ifndef HOUSE2_H
#define HOUSE2_H

#include <objeto.h>

class house2 : public Objeto
{
public:
    Model3DS* model;
public:
    house2();
    void desenha();
};

#endif // HOUSE2_H
