#ifndef DISPARO_H
#define DISPARO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <TextureManager.h>
#include "Window.h"

class Disparo {
    private:
        sf::Texture texDisparo;
        sf::Sprite disparo;
        float posX, posY;

    protected:


    public:
        Disparo(std::string ruta, float x, float y);
        ~Disparo();

        void cambiarSprite(string estado);

        void update();
        bool dentroPantalla();
        void render();

        int getRight();
        int getLeft();
        int getTop();
        int getBottom();
};

#endif // DISPARO_H

