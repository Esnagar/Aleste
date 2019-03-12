#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "Disparo.h"


class Enemigo
{
    private:
        sf::Texture texEnemigo;
        sf::Sprite enemigo;

    protected:


    public:

        Enemigo(std::string ruta);
        ~Enemigo();

        void mover(float x, float y);
        void checkColision(Disparo disparo);
        void draw(sf::RenderWindow &window);

        float getPosX();
        float getPosY();
};


#endif // ENEMIGO_H_INCLUDED
