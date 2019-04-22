#ifndef FACTORYENEMIGO_H
#define FACTORYENEMIGO_H
#include "Enemigo.h"
#include <iostream>
class FactoryEnemigo
{
    public:
        FactoryEnemigo();
        virtual ~FactoryEnemigo();
        Enemigo* crearEnemigo(int p_tipo, sf::Vector2f posicionJugador, int posEnemigo1);

    protected:

    private:
        int tipo;

        int posRX;
        int posRY;
        int ancho;
        int alto;
        float escala;

        sf::Vector2f posicion;
        sf::Vector2f direccionEnemigo;
};

#endif // FACTORYENEMIGO_H
