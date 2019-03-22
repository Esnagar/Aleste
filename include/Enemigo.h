#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "Window.h"
#include "TextureManager.h"
#include "Disparo.h"
#include "Jugador.h"

class Enemigo
{
    private:
        sf::Texture* texEnemigo;
        sf::Sprite enemigo;
        int tipo;

        bool aLaDerecha;

    protected:


    public:

        Enemigo(int tipo);
        ~Enemigo();

        void mover(int velocidad);
        void update();
        void render();
        bool checkColisionDisparo(Disparo disparo);
        bool checkColisionJugador(Jugador jugador);

        float getPosX();
        float getPosY();

        int getTipo();
};


#endif // ENEMIGO_H_INCLUDED
