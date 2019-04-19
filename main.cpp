#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Juego.h"
#include "TextureManager.h"

int main() {

    std::string url ("resources/spritesheet.png");
    TextureManager::getInstancia()->loadTexture("Spritesheet", url);

    Juego juego;

    Window::getInstancia()->first.x=juego.getPosicionJugador().x;
    Window::getInstancia()->first.y=juego.getPosicionJugador().y;

    while(!Window::getInstancia()->haTerminado()) {
        juego.update();
        juego.render();
    }

    return 0;
}
