#include "Juego.h"
#include "Jugador.h"
#include "Window.h"
#include "Disparo.h"

Juego::Juego(): jugador("resources/nave2.png") {}

Juego::~Juego() {}


void Juego::update() {

    Window::getInstancia()->procesarInput();

    //Updatear jugador
    jugador.update();


    //Crear disparos si se ha pulsado la tecla
    if (Window::getInstancia()->inputs[4]) {
        Disparo disparo("resources/disparos.png", jugador.getPosX(), jugador.getPosY() - 70);
        vectorDisparos.push_back(disparo);
    }


    //Updatear disparos
    for(int i = 0; i < vectorDisparos.size(); i++) {
        vectorDisparos[i].update();

        //Eliminar los que salgan fuera de la pantalla
        if(!vectorDisparos[i].dentroPantalla())
            vectorDisparos.erase(vectorDisparos.begin() + i);
    }


    //Crear enemigos
    if (!haEntrado) {
        Enemigo enemigo(1);
        vectorEnemigos.push_back(enemigo);
        haEntrado = true;
    }

    //Updatear enemigos
    for(int i = 0; i < vectorEnemigos.size(); i++) {
        vectorEnemigos[i].update();
    }
}



void Juego::render() {

    Window::getInstancia()->beginDraw();


    //Render fondo
    Window::getInstancia()->renderWindow.draw(Window::getInstancia()->fondo);

    //Render jugador
    jugador.render();

    //Render disparos
    for(int i = 0; i < vectorDisparos.size(); i++) {
        vectorDisparos[i].render();
    }

    //Render enemigos
    for(int i = 0; i < vectorEnemigos.size(); i++) {
        vectorEnemigos[i].render();
    }

    //Render HUD
    hud.render();

    Window::getInstancia()->endDraw();

}
