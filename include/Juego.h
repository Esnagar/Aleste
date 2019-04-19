#ifndef JUEGO_H
#define JUEGO_H
#include "Window.h"
#include "HUD.h"
#include "Jugador.h"
#include "Disparo.h"
#include "Enemigo.h"
#include "FactoryEnemigo.h"

#define kVELOCIDAD 15

class Juego
{
    private:
        HUD hud;

        Jugador jugador;

        FactoryEnemigo factoriaEnem;

        std::vector <Disparo*> vectorDisparos; //vectorDisparos deberia ser un puntero?
        std::vector <Enemigo*> vectorEnemigos;

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
