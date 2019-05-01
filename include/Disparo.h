#ifndef DISPARO_H
#define DISPARO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "TextureManager.h"
#include "Window.h"
#include "Interpolacion.h"

class Disparo {
    private:
        sf::Sprite disparo;
        int tipo;
        float tiempo;
        sf::Vector2f direcDisparo;
        bool explotado = false;
        int numUpdates = 6;

        Interpolacion antes;
        Interpolacion despues;
        sf::Vector2f posicionFinal;

    protected:


    public:
        Disparo(int tipoDisparo, sf::IntRect areaRecorte, float escala, float x, float y, sf::Vector2f direccionDisparo);
        ~Disparo();

        void cambiarSprite(std::string estado);

        void update(sf::Vector2f posicionJugador, float tiempoPasado);
        bool dentroPantalla();
        void render(float percentTick);

        int getRight();
        int getLeft();
        int getTop();
        int getBottom();
        sf::FloatRect getGBounds();

        bool getExplotado();
        int setNumUpdates(int num);
        int getNumUpdates();
};

#endif // DISPARO_H

