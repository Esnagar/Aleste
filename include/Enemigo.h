#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "Window.h"
#include "TextureManager.h"
#include "Jugador.h"
#include <cmath>
#include <SFML/Graphics.hpp>

class Enemigo
{
    private:
        int tipo;
        sf::Sprite enemigo;
        sf::CircleShape circuloColision;

        bool aLaDerecha = true;
        sf::Vector2f direccionEnemigo;
        float gravedad = -0.15f;
        float velX = 3.f;
        float velY = 10.f;

    protected:


    public:

        Enemigo(int tipoEnemigo, sf::IntRect areaRecorte, float escala, sf::Vector2f posicion, sf::Vector2f direccion);
        ~Enemigo();

        void mover(int velocidad);
        void update();
        void render();
        bool dentroPantalla();
        bool checkColisionJugador(Jugador jugador);

        float getPosX();
        float getPosY();

        int getRight();
        int getLeft();
        int getTop();
        int getBottom();

        int getTipo();
        sf::FloatRect getCirculoColision();
};


#endif // ENEMIGO_H_INCLUDED
