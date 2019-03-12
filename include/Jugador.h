#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "Enemigo.h"

class Jugador
{
    private:
        sf::Texture texJugador;
        sf::Sprite jugador;

    protected:

    public:

        Jugador(std::string ruta);
        ~Jugador();

        void mover(float x, float y);
        void checkColision(Enemigo enemigo);
        void draw(sf::RenderWindow &window);

        float getPosX();
        float getPosY();
};

#endif // JUGADOR_H_INCLUDED
