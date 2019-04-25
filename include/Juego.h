#ifndef JUEGO_H
#define JUEGO_H
#include "Window.h"
#include "HUD.h"
#include "Jugador.h"
#include "Disparo.h"
#include "Enemigo.h"
#include "Arma.h"
#include "FactoryEnemigo.h"
#include "FactoryArma.h"

class Juego
{
    private:
        HUD hud;
        Jugador jugador;
        sf::Sprite fondo;

        FactoryEnemigo factoriaEnem;
        FactoryArma factoriaArma;

        std::vector <Enemigo*> vectorEnemigos; //deberia ser un puntero?
        std::vector <Arma*> vectorArmas;

        sf::Clock relojBoss1;
        sf::Clock relojBoss2;
        sf::Clock relojEnemigos1;
        sf::Clock relojEnemigos2;
        sf::Clock relojEnemigos3;

        //Para el fondo
        int tamanyo = 820;
        int posYfondo = 3280 - tamanyo;
        int posXfondo = 0;

        bool stopArmas = false;
        bool stopFondo = false;
        bool stopEnemigos = false;

        bool primerBoss = false;
        bool segundoBoss = false;
        bool irAlSegundoBoss = false;

        int enemigosTipo1 = -1;
        int posEnemigo1;

        void updateFondo();
        void generarEnemigos();
        void generarArmas();
        void comprobarColisiones();

        bool checkColisionED(Enemigo enemigo, Disparo disparo);
        bool checkColisionEJ(Enemigo enemigo);
        bool checkColisionJA(Arma arma);
        bool checkColisionDA(Arma arma, Disparo disparo);

    protected:


    public:
        Juego();
        ~Juego();

        void update();
        void render();

        sf::Vector2f getPosicionJugador();
};

#endif // JUEGO_H
