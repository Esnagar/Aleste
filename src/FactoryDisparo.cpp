#include "FactoryDisparo.h"

FactoryDisparo::FactoryDisparo() {}

FactoryDisparo::~FactoryDisparo() {}

Disparo* FactoryDisparo::crearDisparo(int p_tipo, sf::Vector2f posicionJugador, sf::Vector2f posicionBoss) {

    float modulo;

    switch(p_tipo) {

        case 1:
            tipo = p_tipo;
            posRX = 234;
            posRY = 213;
            ancho = 24;
            alto = 71;
            escala = 0.7;
            posX = posicionJugador.x;
            posY = posicionJugador.y - 50;
        break;

        case 2:
            tipo = p_tipo;
            posRX = 0;
            posRY = 208;
            ancho = 78;
            alto = 71;
            escala = 0.7;
            posX = posicionJugador.x;
            posY = posicionJugador.y - 50;
        break;


        case 3:
            tipo = p_tipo;
            posRX = 312;
            posRY = 72;
            ancho = 47;
            alto = 141;
            escala = 0.7;
            posX = posicionJugador.x;
            posY = posicionJugador.y - 50;
        break;

        //Para los bosses
        case 4:
            tipo = p_tipo;
            posRX = 252;
            posRY = 144;
            ancho = 28;
            alto = 35;
            escala = 0.7;

            modulo = sqrt(  (posicionBoss.x - posicionJugador.x) * (posicionBoss.x - posicionJugador.x)
                          + (posicionBoss.y - posicionJugador.y) * (posicionBoss.y - posicionJugador.y));

            direccionDisparo.x = (posicionJugador.x - posicionBoss.x) / modulo;
            direccionDisparo.y = (posicionJugador.y - posicionBoss.y) / modulo;

            posX = posicionBoss.x + 15;
            posY = posicionBoss.y + 15;
        break;
    }

    return new Disparo(tipo, sf::IntRect(posRX, posRY, ancho, alto), escala, posX, posY, direccionDisparo);


}
