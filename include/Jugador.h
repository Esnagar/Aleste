#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Window.h"
#include "TextureManager.h"
#include "Disparo.h"

#define kVELOCIDAD 300


class Jugador
{
    private:
        sf::Sprite jugador;
        sf::CircleShape circuloColision;
        std::vector <Disparo*> vectorDisparos;
        int arma;

        void updateDisparos();


    protected:

    public:
        Jugador();
        ~Jugador();

        void mover(float x, float y);
        void crearDisparo();
        void update(float segundosUpdate);
        void render();

        void setArma(int tipo);

        std::vector <Disparo*> getDisparos();
        void borrarDisparo(int posicion);

        float getPosX();
        float getPosY();
        sf::FloatRect getCirculoColision();
        sf::FloatRect getGBounds();

        int getArma();
};

#endif // JUGADOR_H_INCLUDED
