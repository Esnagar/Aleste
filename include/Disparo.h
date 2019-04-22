#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "TextureManager.h"
#include "Window.h"

class Disparo {
    private:
        int tipo;
        sf::Sprite disparo;
        float tiempo;

    protected:


    public:
        Disparo(int tipoDisparo, sf::IntRect areaRecorte, float escala, float x, float y);
        ~Disparo();

        void cambiarSprite(std::string estado);

        void update(sf::Vector2f posicionJugador);
        bool dentroPantalla();
        void render();

        int getRight();
        int getLeft();
        int getTop();
        int getBottom();
        sf::FloatRect getGBounds();
};

#endif // DISPARO_H

