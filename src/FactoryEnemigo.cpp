#include "FactoryEnemigo.h"

FactoryEnemigo::FactoryEnemigo() {}

FactoryEnemigo::~FactoryEnemigo() {}

Enemigo* FactoryEnemigo::crearEnemigo(int p_tipo, sf::Vector2f posicionJugador, int posEnemigo) {

    float modulo;

    switch(p_tipo) {

        case 1:
            tipo = p_tipo;
            posRX = 234;
            posRY = 71;
            ancho = 78;
            alto = 71;
            escala = 0.8;
            posicion.x = posEnemigo;
            posicion.y = 5;
        break;

        case 2:
            tipo = p_tipo;
            posRX = 359;
            posRY = 71;
            ancho = 66;
            alto = 139;
            escala = 0.7;

            srand(time(NULL));
            posEnemigo = (rand() % (800 - 20)) + 20;

            posicion.x = posEnemigo;
            posicion.y = 5;

            //Se calcula el vector unitario entre el enemigo y el jugador. De esta forma, el enemigo se moverá a la misma velocidad siempre
            modulo = sqrt(  (posicion.x - posicionJugador.x) * (posicion.x - posicionJugador.x)
                          + (posicion.y - posicionJugador.y) * (posicion.y - posicionJugador.y));

            direccionEnemigo.x = (posicionJugador.x - posicion.x) / modulo;
            direccionEnemigo.y = (posicionJugador.y - posicion.y) / modulo;
        break;


        case 3:
            tipo = p_tipo;
            posRX = 0;
            posRY = 142;
            ancho = 78;
            alto = 71;
            escala = 0.7;

            srand(time(NULL));
            posEnemigo = (rand() % (815 - 5)) + 5;
            posicion.x = posEnemigo;
            posicion.y = 5;
        break;
    }

    return new Enemigo(tipo, sf::IntRect(posRX, posRY, ancho, alto), escala, posicion, direccionEnemigo);
}
