#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Window.h"
#include "TextureManager.h"
#include "Disparo.h"
#include "FactoryDisparo.h"
#include "Window.h"

#define kVELOCIDAD 300


class Jugador
{
    private:
        sf::Sprite jugador;
        sf::CircleShape circuloColision;

        FactoryDisparo factoriaDisp;

        std::vector <Disparo*> vectorDisparos;
        int arma;
        int numSprite = 0;
        sf::Clock relojInmortal;
        bool inmortal = false;

        void updateDisparos();
        void cambiarSprite();


    protected:

    public:
        Jugador();
        ~Jugador();

        void mover(float x, float y);
        void crearDisparo();
        void cambiarSprite(std::string estado);
        void update(float segundosUpdate);
        void render();

        void setArma(int tipo);
        void setInmortal();
        bool getInmortal();

        std::vector <Disparo*> getDisparos();
        void borrarDisparo(int posicion);

        float getPosX();
        float getPosY();
        sf::FloatRect getCirculoColision();
        sf::FloatRect getGBounds();

        int getArma();
};

#endif // JUGADOR_H_INCLUDED
