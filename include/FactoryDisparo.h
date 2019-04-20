#ifndef FACTORYDISPARO_H
#define FACTORYDISPARO_H
#include "Disparo.h"

class FactoryDisparo
{
    public:
        FactoryDisparo();
        virtual ~FactoryDisparo();
        Disparo* crearDisparo(int p_tipo, sf::Vector2f posicionJugador);

    protected:

    private:
        int tipo;

        int posRX;
        int posRY;
        int ancho;
        int alto;
        float escala;

        sf::Vector2f posicion;
};

#endif // FACTORYDISPARO_H
