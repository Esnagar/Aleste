#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "TextureManager.h"


class Enemigo
{
    private:
        sf::Texture* texEnemigo;
        sf::Sprite enemigo;
        bool aLaDerecha;

    protected:


    public:

        Enemigo(int tipo);
        ~Enemigo();

        void mover(int velocidad);
        void update();
        void render();
        //void checkColision(Disparo disparo);

        float getPosX();
        float getPosY();
};


#endif // ENEMIGO_H_INCLUDED
