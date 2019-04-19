#include "FactoryEnemigo.h"

FactoryEnemigo::FactoryEnemigo() {}

FactoryEnemigo::~FactoryEnemigo() {}

Enemigo* FactoryEnemigo::crearEnemigo(int p_tipo, sf::Vector2f posicionJugador) {

    float modulo;

    switch(p_tipo) {

        case 1:
            tipo = p_tipo;
            posRX = 234;
            posRY = 71;
            ancho = 78;
            alto = 71;
            escala = 0.8;
            posicion.x = 320;
            posicion.y = 100;
        break;

        case 2:
            tipo = p_tipo;
            posRX = 331;
            posRY = 71;
            ancho = 66;
            alto = 139;
            escala = 0.7;
            posicion.x = 500;
            posicion.y = 100;

            //Se calcula el vector unitario entre el enemigo y el jugador
            //De esta forma, el enemigo se moverá a la misma velocidad siempre
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
            posicion.x = Window::getInstancia()->getTamanyo().x/4;
            posicion.y = 20;
        break;
    }

    std::cout << direccionEnemigo.x << std::endl;
    std::cout << direccionEnemigo.y << std::endl;


    return new Enemigo(tipo, sf::IntRect(posRX, posRY, ancho, alto), escala, posicion, direccionEnemigo);
}
