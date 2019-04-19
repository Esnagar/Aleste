#include "Juego.h"

Juego::Juego() {}

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
        jugador.crearDisparo();

        if(jugador.getArma() != 1) {
            hud.updateDisparosArma();

            if(hud.getDisparosArma() < 1) {
                jugador.setArma(1);
                hud.setArma(1);
            }
        }
    }

    //Crear enemigos
    if (haEntrado <= 2) {
        if(haEntrado == 1) {
            vectorEnemigos.push_back(factoriaEnem.crearEnemigo(1, sf::Vector2f(jugador.getPosX(), jugador.getPosY())));
            vectorEnemigos.push_back(factoriaEnem.crearEnemigo(2, sf::Vector2f(jugador.getPosX(), jugador.getPosY())));
            vectorArmas.push_back(new Arma(3));

        } else
            vectorEnemigos.push_back(factoriaEnem.crearEnemigo(3, sf::Vector2f(jugador.getPosX(), jugador.getPosY())));

        haEntrado++;
    }


    //Updatear armas
    for(int i = 0; i < vectorArmas.size(); i++) {
        vectorArmas[i]->update();
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
    for(int i = 0; i < jugador.getDisparos().size(); i++)
        for(int j = 0; j < vectorEnemigos.size(); j++)
            if(checkColisionED(*vectorEnemigos[j], *jugador.getDisparos()[i])) { //si estan colisionando

                hud.updatePuntuacion(vectorEnemigos[j]->getTipo());

                delete vectorEnemigos[j];
                vectorEnemigos[j] = nullptr;
                vectorEnemigos.erase(vectorEnemigos.begin() + j);

                jugador.borrarDisparo(i);
            }


    //Comprobar la colisión enemigo-jugador
    for(int i = 0; i < vectorEnemigos.size(); i++)
        if(checkColisionEJ(*vectorEnemigos[i])) {
            hud.updateVidas(-1);
            jugador.mover(Window::getInstancia()->getTamanyo().x/2, Window::getInstancia()->getTamanyo().y/2);
        }


    //Comprobar la colisión disparo-arma
    for(int i = 0; i < vectorArmas.size(); i++)
        for(int j = 0; j < jugador.getDisparos().size(); j++)
            if(checkColisionDA(*vectorArmas[i], *jugador.getDisparos()[j])) {
                vectorArmas[i]->setDisparada();
            }

    //Comprobar la colisión jugador-arma
    for(int i = 0; i < vectorArmas.size(); i++)
        if(checkColisionJA(*vectorArmas[i])) {
            jugador.setArma(vectorArmas[i]->getTipo());
            hud.setArma(vectorArmas[i]->getTipo());
            vectorArmas[i]->armaActivada();
        }
}



void Juego::render() {

    Window::getInstancia()->beginDraw();

    //Render fondo
    Window::getInstancia()->renderWindow.draw(Window::getInstancia()->fondo);

    //Render enemigos
    for(int i = 0; i < vectorEnemigos.size(); i++)
        vectorEnemigos[i]->render();

    //Render armas
    for(int i = 0; i < vectorArmas.size(); i++)
        vectorArmas[i]->render();

    //Render jugador
    jugador.render();

    //Render HUD
    hud.render();

    Window::getInstancia()->endDraw();

}

sf::Vector2f Juego::getPosicionJugador() {
    return sf::Vector2f(jugador.getPosX(), jugador.getPosY());
}


bool Juego::checkColisionED(Enemigo enemigo, Disparo disparo) {
    bool colision = false;
    if (disparo.getGBounds().intersects(enemigo.getCirculoColision()))
        colision = true;
}

bool Juego::checkColisionEJ(Enemigo enemigo) {
    bool colision = false;
    if(jugador.getCirculoColision().intersects(enemigo.getCirculoColision()))
        colision = true;
}


bool Juego::checkColisionJA(Arma arma) {
    bool colision = false;
    if(jugador.getCirculoColision().intersects(arma.getGBnumero()))
        colision = true;
}


bool Juego::checkColisionDA(Arma arma, Disparo disparo) {
    bool colision = false;
    if (disparo.getGBounds().intersects(arma.getGBbola()))
        colision = true;
}
