#ifndef JUEGO_H
#define JUEGO_H
#include "Window.h"
#include "Disparo.h"
#include "Jugador.h"
#include "HUD.h"

#define kVELOCIDAD 15

class Juego
{
    private:
        Jugador jugador;
        std::vector <Disparo> vectorDisparos;
        HUD hud;

    protected:


    public:
        Juego();
        ~Juego();

        void update();
        void render();
};

#endif // JUEGO_H
