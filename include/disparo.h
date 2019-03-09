#ifndef DISPARO_H
#define DISPARO_H
#include <iostream>
#include <SFML/Graphics.hpp>

class disparo
{
    public:
        disparo(float x, float y);
        virtual ~disparo();

    protected:

    private:
        sf::Sprite bala;

};

#endif // DISPARO_H
