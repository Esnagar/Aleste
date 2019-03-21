#include "Juego.h"
#include "Jugador.h"
#include "Window.h"
#include "Disparo.h"

Juego::Juego(): jugador("resources/nave2.png") {}

Juego::~Juego() {}


void Juego::update() {

    Window::getInstancia()->procesarInput();

    //UPDATEAR JUGADOR
    jugador.update();


    //CREAR DISPAROS SI EL JUGADOR HA PULSADO SPACE
    if (Window::getInstancia()->inputs[4]) {
        Disparo disparo("resources/disparos.png", jugador.getPosX(), jugador.getPosY() - 70);
        vectorDisparos.push_back(disparo);
    }


    //UPDATEAR DISPAROS
    for(int i = 0; i < vectorDisparos.size(); i++) {
        vectorDisparos[i].update();

        //ELIMINAR LOS QUE SALGAN FUERA DE LA PANTALLA
        if(!vectorDisparos[i].dentroPantalla())
            vectorDisparos.erase(vectorDisparos.begin() + i);
    }
}



void Juego::render() {

    Window::getInstancia()->beginDraw();


    //RENDER FONDO
    Window::getInstancia()->renderWindow.draw( Window::getInstancia()->fondo);

    //RENDER JUGADOR
    jugador.render();

    //RENDER DISPAROS
    for(int i = 0; i < vectorDisparos.size(); i++) {
        vectorDisparos[i].render();
    }

    //RENDER ENEMIGOS

    //for (int i = 0; i < vectorDisparos.size(); i++) {
    //    vectorDisparos[i].draw(Window::getInstancia());
    //}

    //RENDER HUD
    hud.render();

    Window::getInstancia()->endDraw();

}
