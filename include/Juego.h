#ifndef JUEGO_H
#define JUEGO_H
#include "Window.h"
#include "Jugador.h"
#include "Disparo.h"

#define kVELOCIDAD 1

class Juego
{
    private:
        Window ventana;
        Jugador jugador;
        std::vector <Disparo> vectorDisparos;

    protected:


    public:
        Juego();
        ~Juego();

        void procesarInput();
        void update();
        void render();
        void anyadirDisparo(Disparo disparo);
        Window* getWindow();
};

#endif // JUEGO_H
