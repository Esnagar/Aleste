#ifndef JUEGO_H
#define JUEGO_H
#include "Window.h"
#include "HUD.h"
#include "Jugador.h"
#include "Disparo.h"
#include "Enemigo.h"
#include "FactoryEnemigo.h"
#include "Arma.h"

#define kVELOCIDAD 15

class Juego
{
    private:
        HUD hud;

        Jugador jugador;

        FactoryEnemigo factoriaEnem;
        std::vector <Enemigo*> vectorEnemigos; //deberia ser un puntero?
        std::vector <Arma*> vectorArmas;

        sf::Clock relojEnemigos1;
        sf::Clock relojEnemigos2;
        sf::Clock relojEnemigos3;

        int enemigosTipo1 = -1;
        int posEnemigo1;

        bool checkColisionED(Enemigo enemigo, Disparo disparo);
        bool checkColisionEJ(Enemigo enemigo);
        bool checkColisionJA(Arma arma);
        bool checkColisionDA(Arma arma, Disparo disparo);

    protected:


    public:
        Juego();
        ~Juego();

        int haEntrado = 1;

        void update();
        void render();

        sf::Vector2f getPosicionJugador();

};

#endif // JUEGO_H
