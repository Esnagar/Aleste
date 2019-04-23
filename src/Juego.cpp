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

    //Generar enemigos de tipo 1 aleatoriamente

    if(enemigosTipo1 == -1) {
        srand(time(NULL));
        posEnemigo1 = (rand() % (650 - 300)) + 300;
        enemigosTipo1 = (rand() % (8 - 3)) + 3;
    }

    if(relojEnemigos1.getElapsedTime().asSeconds() > 0.3 && enemigosTipo1 > 0) {
        vectorEnemigos.push_back(factoriaEnem.crearEnemigo(1, sf::Vector2f(jugador.getPosX(), jugador.getPosY()), posEnemigo1));
        relojEnemigos1.restart();
        enemigosTipo1--;
    }


    if(relojEnemigos1.getElapsedTime().asSeconds() > 10) {
        enemigosTipo1 = -1;
        relojEnemigos1.restart();
    }



    //Generar enemigos de tipo 2 aleatoriamente

    if(relojEnemigos2.getElapsedTime().asSeconds() > 3.5 && relojEnemigos2.getElapsedTime().asMilliseconds() % 4 == 0) {
        vectorEnemigos.push_back(factoriaEnem.crearEnemigo(2, sf::Vector2f(jugador.getPosX(), jugador.getPosY()), 0));
        relojEnemigos2.restart();
    }



    if(relojEnemigos3.getElapsedTime().asSeconds() > 5 && relojEnemigos2.getElapsedTime().asMilliseconds() % 4 == 0) {
        vectorEnemigos.push_back(factoriaEnem.crearEnemigo(3, sf::Vector2f(jugador.getPosX(), jugador.getPosY()), 0));
        relojEnemigos3.restart();
    }

    //Crear enemigos
    if (haEntrado <= 2) {
        if(haEntrado == 1)
            vectorArmas.push_back(new Arma(3));
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
            if(jugador.getDisparos().size() > 0 && checkColisionED(*vectorEnemigos[j], *jugador.getDisparos()[i])) { //si estan colisionando

                hud.updatePuntuacion(vectorEnemigos[j]->getTipo());

                delete vectorEnemigos[j];
                vectorEnemigos[j] = nullptr;
                vectorEnemigos.erase(vectorEnemigos.begin() + j);

                jugador.borrarDisparo(i);
                //i--;
                //j--;
            }


    //Comprobar la colisión enemigo-jugador
    for(int i = 0; i < vectorEnemigos.size(); i++)
        if(checkColisionEJ(*vectorEnemigos[i])) {
            hud.updateVidas(-1);
        }


    //Comprobar la colisión disparo-arma
    for(int i = 0; i < vectorArmas.size(); i++)
        for(int j = 0; j < jugador.getDisparos().size(); j++)
            if(checkColisionDA(*vectorArmas[i], *jugador.getDisparos()[j])) {
                vectorArmas[i]->setDisparada();
                jugador.borrarDisparo(j); //mejorar para que no se vea tan pocho
            }

    //Comprobar la colisión jugador-arma
    for(int i = 0; i < vectorArmas.size(); i++)
        if(checkColisionJA(*vectorArmas[i]) && vectorArmas[i]->getDisparada()) {
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
    if (disparo.getGBounds().intersects(arma.getGBnumero()))
        colision = true;
}
