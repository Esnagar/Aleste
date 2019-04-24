#ifndef FACTORYARMA_H
#define FACTORYARMA_H
#include "Arma.h"

class FactoryArma
{
    public:
        FactoryArma();
        virtual ~FactoryArma();
        Arma* crearArma(int p_tipo, int posicion);

    protected:

    private:
        int tipo;
        float posX;
        float posY;
};

#endif // FACTORYARMA_H
