#ifndef JUEGO_H
#define JUEGO_H
#include "Window.h"
#include "HUD.h"
#include "Jugador.h"
#include "Disparo.h"
#include "Enemigo.h"

#define kVELOCIDAD 15

class Juego
{
    private:
        HUD hud;

        Jugador jugador;
        std::vector <Disparo*> vectorDisparos; //vectorDisparos deberia ser un puntero?
        std::vector <Enemigo*> vectorEnemigos;

    protected:


    public:
        Juego();
        ~Juego();

        bool haEntrado = false;

        void update();
        void render();

};

#endif // JUEGO_H
