#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Window.h>
#include <TextureManager.h>
#define kVELOCIDAD 300


class Jugador
{
    private:
        sf::Sprite jugador;
        sf::CircleShape circuloColision;

    protected:

    public:
        Jugador();
        ~Jugador();

        void mover(float x, float y);
        void update(float segundosUpdate);
        void render();

        float getPosX();
        float getPosY();
        float getRadioColision();
        sf::FloatRect getGBounds();
};

#endif // JUGADOR_H_INCLUDED
