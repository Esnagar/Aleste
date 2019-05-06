#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Window.h"
#include "TextureManager.h"
#include "Interpolacion.h"

class Enemigo
{
    private:
        int tipo;
        int numVidas;

        sf::Sprite enemigo;
        sf::CircleShape circuloColision;

        bool aLaDerecha = true;
        sf::Vector2f direccionEnemigo;

        float gravedad = -0.025f;
        float velX = 1.3f;
        float velY = 1.25f;
        int dirVelX = 1;
        float posXinicial;

        Interpolacion antes;
        Interpolacion despues;
        sf::Vector2f posicionFinal;

    protected:


    public:
        Enemigo(int tipoEnemigo, sf::IntRect areaRecorte, float escala, sf::Vector2f posicion, float radio, sf::Vector2f direccion, int numeroVidas);
        ~Enemigo();

        void mover(float velocidad, float tiempoPasado);
        void update(float tiempoPasado);
        void render(float percentTick);
        bool dentroPantalla();

        float getPosX();
        float getPosY();

        int getRight();
        int getLeft();
        int getTop();
        int getBottom();

        int getTipo();
        sf::FloatRect getCirculoColision();

        int getNumVidas();
        void setNumVidas(int num);
};


#endif // ENEMIGO_H_INCLUDED
