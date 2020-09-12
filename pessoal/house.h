#ifndef HOUSE_H
#define HOUSE_H

#include <objeto.h>

class house : public Objeto
{
public:
    Model3DS* model;
public:
    house();
    void desenha();
};

#endif // HOUSE_H
