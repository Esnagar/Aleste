#ifndef DISPARO_H
#define DISPARO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Window.h"
#include "Enemigo.h"

class Disparo {
    private:
        sf::Sprite disparo;
        float posX, posY;

    protected:


    public:
        Disparo(std::string ruta, float x, float y);
        ~Disparo();

        void cambiarSprite(std::string estado);

        void update();
        bool dentroPantalla();
        void render();
        bool checkColisionDisparo(Enemigo enemigo);

        int getRight();
        int getLeft();
        int getTop();
        int getBottom();
        sf::FloatRect getGBounds() { return disparo.getGlobalBounds();}
};

#endif // DISPARO_H

