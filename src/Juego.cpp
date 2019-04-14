#include "Juego.h"

Juego::Juego(): jugador("resources/nave2.png") {}

Juego::~Juego() {}


void Juego::update() {

    float segundosUpdate = Window::getInstancia()->relojUpdate.restart().asSeconds();

    //Guardamos la última posición
    Window::getInstancia()->last = Window::getInstancia()->first;

    //Procesamos las teclas pulsadas
    Window::getInstancia()->procesarInput();


    //Updatear jugador
    Window::getInstancia()->percent = std::min(1.0, (double)Window::getInstancia()->relojInterp.getElapsedTime().asMilliseconds() / UPDATE_TICK_TIME);
    jugador.update(segundosUpdate);


    //Update del fondo
    Window::getInstancia()->updateFondo();


    //Crear disparos si se ha pulsado la tecla
    if (Window::getInstancia()->inputs[4]) {
        vectorDisparos.push_back(new Disparo("resources/disparos.png", jugador.getPosX(), jugador.getPosY() - 70));
    }


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
    if (haEntrado <= 2) {
        if(haEntrado == 1)
            vectorEnemigos.push_back(new Enemigo(1, sf::Vector2f(jugador.getPosX(), jugador.getPosY())));
        else
            vectorEnemigos.push_back(new Enemigo(2, sf::Vector2f(jugador.getPosX(), jugador.getPosY())));

        haEntrado++;
    }


    //Updatear enemigos
    for(int i = 0; i < vectorEnemigos.size(); i++) {
        vectorEnemigos[i]->update();

        //Eliminar los que salgan fuera de la pantalla
        if(!vectorEnemigos[i]->dentroPantalla()) {
            delete vectorEnemigos[i];
            vectorEnemigos[i] = nullptr;
            vectorEnemigos.erase(vectorEnemigos.begin() + i);
        }
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

sf::Vector2f Juego::getPosicionJugador() {
    return sf::Vector2f(jugador.getPosX(), jugador.getPosY());
}
