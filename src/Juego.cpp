#include "Juego.h"

Juego::Juego(): jugador("resources/nave2.png") {}

Juego::~Juego() {}


void Juego::update() {

    Window::getInstancia()->procesarInput();

    //Updatear jugador
    jugador.update();


    //Crear disparos si se ha pulsado la tecla
    if (Window::getInstancia()->inputs[4]) {
        vectorDisparos.push_back(new Disparo("resources/disparos.png", jugador.getPosX(), jugador.getPosY() - 70));
    }


    std::cout << vectorDisparos.size() << std::endl;

    //Updatear disparos
    for(int i=0; i<vectorDisparos.size(); i++) {
        vectorDisparos[i]->update();

        //Eliminar los que salgan fuera de la pantalla
        if(!vectorDisparos[i]->dentroPantalla()) {
            delete vectorDisparos[i];
            vectorDisparos[i] = nullptr;

            vectorDisparos.erase(vectorDisparos.begin() + i);
        }
    }


    //Crear enemigos
    if (!haEntrado) {
        vectorEnemigos.push_back(new Enemigo(1));
        haEntrado = true;
    }

    //Updatear enemigos
    for(int i = 0; i < vectorEnemigos.size(); i++) {
        vectorEnemigos[i]->update();
    }


    //Comprobar la colisión enemigo-disparo
    for(int i = 0; i < vectorDisparos.size(); i++)
        for(int j = 0; j < vectorEnemigos.size(); j++)
            if(vectorDisparos[i]->checkColisionDisparo(*vectorEnemigos[j])) { //si estan colisionando

                hud.updatePuntuacion(vectorEnemigos[j]->getTipo());

                delete vectorEnemigos[j];
                vectorEnemigos[j] = nullptr;
                vectorEnemigos.erase(vectorEnemigos.begin() + j);

                delete vectorDisparos[i];
                vectorDisparos[i] = nullptr;
                vectorDisparos.erase(vectorDisparos.begin() + i);
            }



    //Comprobar la colisión enemigo-jugador
    for(int i = 0; i < vectorEnemigos.size(); i++)
        if(vectorEnemigos[i]->checkColisionJugador(jugador)) {
            hud.updateVidas(-1);
            jugador.mover(Window::getInstancia()->getTamanyo().x/2, Window::getInstancia()->getTamanyo().y/2);
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
        vectorDisparos[i]->render();
    }

    //Render enemigos
    for(int i = 0; i < vectorEnemigos.size(); i++) {
        vectorEnemigos[i]->render();
    }

    //Render HUD
    hud.render();

    Window::getInstancia()->endDraw();

}
