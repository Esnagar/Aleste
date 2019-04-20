#include "FactoryDisparo.h"

FactoryDisparo::FactoryDisparo() {}

FactoryDisparo::~FactoryDisparo() {}

Disparo* FactoryDisparo::crearDisparo(int p_tipo, sf::Vector2f posicionJugador) {

    switch(p_tipo) {

        case 1:
            tipo = p_tipo;
            posRX = 234;
            posRY = 213;
            ancho = 24;
            alto = 71;
            escala = 0.7;
        break;

        case 2:
            tipo = p_tipo;
            posRX = 0;
            posRY = 208;
            ancho = 78;
            alto = 71;
            escala = 0.7;
        break;


        case 3:
            tipo = p_tipo;
            posRX = 312;
            posRY = 72;
            ancho = 47;
            alto = 141;
            escala = 0.7;
        break;
    }

    return new Disparo(tipo, sf::IntRect(posRX, posRY, ancho, alto), escala, posicionJugador.x, posicionJugador.y - 50);


}
