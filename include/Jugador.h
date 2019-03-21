#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>

#define kVELOCIDAD 6


class Jugador
{
    private:
        sf::Texture texJugador;
        sf::Sprite jugador;

    protected:

    public:
        Jugador();
        Jugador(std::string ruta);
        ~Jugador();

        //void checkColision(Enemigo enemigo);
        void update();
        void render();

        float getPosX();
        float getPosY();
};

#endif // JUGADOR_H_INCLUDED
