#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Juego.h"


int main() {

    Juego juego;

    Window::getInstancia()->first.x=juego.getPosicionJugador().x;
    Window::getInstancia()->first.y=juego.getPosicionJugador().y;

    while(!Window::getInstancia()->haTerminado()) {
        juego.update();
        juego.render();
    }

    return 0;
}
