#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Window.h"
#include "TextureManager.h"
#include "Disparo.h"
#include "FactoryDisparo.h"
#include "Window.h"
#include "Interpolacion.h"

class Jugador
{
    private:
        sf::Sprite jugador;
        sf::CircleShape circuloColision;

        FactoryDisparo factoriaDisp;
        std::vector <Disparo*> vectorDisparos;

        sf::Clock relojInmortal;
        sf::Vector2f posicionFinal;

        float kVELOCIDADx = 0.5f;
        float kVELOCIDADy = 0.5f;

        int arma;
        bool escudoActivado = false;
        bool inmortal = false;

        void updateDisparos(float tiempoPasado);
        void cambiarSprite();

        Interpolacion antes;
        Interpolacion despues;

    protected:

    public:
        Jugador();
        ~Jugador();

        void mover(float x, float y);
        void crearDisparo();
        void cambiarSprite(std::string estado);
        void update(float tiempoPasado);
        void render(float percentTick);

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
