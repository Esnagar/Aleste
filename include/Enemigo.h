#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "Juego.h"


class Enemigo
{
    private:
        sf::Texture texEnemigo;
        sf::Sprite enemigo;
        bool aLaDerecha;

    protected:


    public:

        Enemigo(std::string ruta);
        ~Enemigo();

        void mover(int velocidad);
        //void checkColision(Disparo disparo);
        void draw(sf::RenderWindow &window);

        float getPosX();
        float getPosY();
};


#endif // ENEMIGO_H_INCLUDED
