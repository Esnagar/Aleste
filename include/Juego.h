#ifndef JUEGO_H
#define JUEGO_H
#include "Window.h"
#include "HUD.h"
#include "Jugador.h"
#include "Disparo.h"
#include "Enemigo.h"
#include "FactoryEnemigo.h"
#include "Arma.h"
#include "FactoryArma.h"

#define kVELOCIDAD 15

class Juego
{
    private:
        HUD hud;

        Jugador jugador;

        FactoryEnemigo factoriaEnem;
        FactoryArma factoriaArma;

        //Para el fondo
        int tamanyo = 820;
        int posX = 0;
        int posY = 3280 - tamanyo;
        sf::Sprite fondo;
        bool stopArmas = false;
        bool stopFondo = false;
        bool stopEnemigos = false;


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

        void updateFondo();

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
