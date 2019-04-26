#ifndef FACTORYDISPARO_H
#define FACTORYDISPARO_H
#include "Disparo.h"

class FactoryDisparo
{
    public:
        FactoryDisparo();
        virtual ~FactoryDisparo();
        Disparo* crearDisparo(int p_tipo, sf::Vector2f posicionJugador, sf::Vector2f posicionBoss);

    protected:

    private:
        int tipo;

        int posRX;
        int posRY;
        int ancho;
        int alto;
        int posX;
        int posY;
        float escala;

        sf::Vector2f direccionDisparo;
};

#endif // FACTORYDISPARO_H
