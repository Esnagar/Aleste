#ifndef DISPARO_H
#define DISPARO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <TextureManager.h>

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
        void draw(sf::RenderWindow &window);
        bool dentroPantalla(sf::RenderWindow &window);

        int getRight();
        int getLeft();
        int getTop();
        int getBottom();
};

#endif // DISPARO_H

