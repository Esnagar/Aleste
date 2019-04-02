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
        sf::Texture* texEnemigo;
        sf::Sprite enemigo;
        sf::CircleShape circuloColision;
        int tipo;

        bool aLaDerecha;
        sf::Vector2f direccionEnemigo;

    protected:


    public:

        Enemigo(int tipo, sf::Vector2f posicionJugador);
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
