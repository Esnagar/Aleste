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

        void mover(float x, float y);
        void draw(Window &window);
        bool dentroPantalla(Window &window);
        void cambiarSprite(string estado);

        void update();

        int getRight();
        int getLeft();
        int getTop();
        int getBottom();
        sf::FloatRect getGlobalBounds(){ return disparo.getGlobalBounds(); }
};

#endif // DISPARO_H

