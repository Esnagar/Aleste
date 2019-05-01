#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Juego.h"
#include "TextureManager.h"

//#define UPDATE_TICK_TIME (1000/60)

int main() {

    std::string url ("resources/spritesheet.png");
    TextureManager::getInstancia()->loadTexture("Spritesheet", url);
    std::string url2("resources/fondo.png");
    TextureManager::getInstancia()->loadTexture("fondo", url2);

    Juego juego;
    sf::Clock relojInterpolacion;

    while(!Window::getInstancia()->haTerminado()) {
        juego.input();

        if(relojInterpolacion.getElapsedTime().asMilliseconds() > Window::getInstancia()->UPDATE_TICK_TIME) {
            float tiempoPasado = relojInterpolacion.restart().asMilliseconds();
            juego.update(tiempoPasado);
        }

        float percentTick = std::min(1.0f, (float)relojInterpolacion.getElapsedTime().asMilliseconds()/Window::getInstancia()->UPDATE_TICK_TIME);

        juego.render(percentTick);
    }

    return 0;
}
