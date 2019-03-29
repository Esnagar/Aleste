#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "Window.h"
#include "TextureManager.h"
#include "Jugador.h"
#include <cmath>

class Enemigo
{
    private:
        sf::Texture* texEnemigo;
        sf::Sprite enemigo;
        sf::CircleShape circuloColision;
        int tipo;

        bool aLaDerecha;

    protected:


    public:

        Enemigo(int tipo);
        ~Enemigo();

        void mover(int velocidad);
        void update();
        void render();
        bool checkColisionJugador(Jugador jugador);

        float getPosX();
        float getPosY();

        int getTipo();
        sf::FloatRect getCirculoColision();
};


#endif // ENEMIGO_H_INCLUDED
