#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>

#define kVELOCIDAD 300


class Jugador
{
    private:
        sf::Texture texJugador;
        sf::Sprite jugador;
        sf::CircleShape circuloColision;

    protected:

    public:
        Jugador();
        Jugador(std::string ruta);
        ~Jugador();

        void update(float segundosUpdate);
        void render();

        float getPosX();
        float getPosY();
        float getRadioColision();
        sf::FloatRect getGBounds();

        void mover(float x, float y);

};

#endif // JUGADOR_H_INCLUDED
