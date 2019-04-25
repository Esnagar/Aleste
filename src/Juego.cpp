#include "Juego.h"

Juego::Juego() {
    fondo.setTexture(*TextureManager::getInstancia()->getTexture("fondo"));
}

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

    //Update del fondo
    updateFondo();

    //Generar enemigos
    if(!stopEnemigos)
        generarEnemigos();


    //ZONA DE BOSSES. Si se pasa cierto tiempo en la zona de los bosses, se sigue avanzando
    if(primerBoss && relojBoss1.getElapsedTime().asSeconds() >= 30.f){
        primerBoss = false;
        irAlSegundoBoss = true;
        posYfondo -= 4;

        delete vectorEnemigos[0];
        vectorEnemigos[0] = nullptr;
        vectorEnemigos.erase(vectorEnemigos.begin());
    }

    if(segundoBoss && relojBoss2.getElapsedTime().asSeconds() >= 100.f){
        segundoBoss = false;
        posYfondo -= 4;

        int enemigosRestantes = vectorEnemigos.size() - 1;
        while(enemigosRestantes >= 0) {
            delete vectorEnemigos[enemigosRestantes];
            vectorEnemigos[enemigosRestantes] = nullptr;
            vectorEnemigos.erase(vectorEnemigos.begin() + enemigosRestantes);
            enemigosRestantes--;
        }
    }

    //Updatear armas
    for(int i = 0; i < vectorArmas.size(); i++)
        vectorArmas[i]->update();


    //Updatear enemigos
    for(int i = 0; i < vectorEnemigos.size(); i++) {
        vectorEnemigos[i]->update();

        if(!vectorEnemigos[i]->dentroPantalla()) {
            delete vectorEnemigos[i];
            vectorEnemigos[i] = nullptr;
            vectorEnemigos.erase(vectorEnemigos.begin() + i);
        }
    }

    comprobarColisiones();
}



void Juego::render() {

    Window::getInstancia()->beginDraw();

    Window::getInstancia()->renderWindow.draw(fondo);

    for(int i = 0; i < vectorArmas.size(); i++)
        vectorArmas[i]->render();

    for(int i = 0; i < vectorEnemigos.size(); i++)
        vectorEnemigos[i]->render();

    jugador.render();

    hud.render();

    Window::getInstancia()->endDraw();
}


void Juego::updateFondo() {

    if(!primerBoss && !segundoBoss) {
        stopArmas = false;
        stopEnemigos = false;
        stopFondo = false;
    }

    //Si el IntRect del fondo llega hasta el final (arriba), salta a la siguiente columna
    if(posYfondo <= 0) {
        posYfondo = 3280 - tamanyo;

        if(posXfondo == 3280 && irAlSegundoBoss)
            posXfondo = 0 - tamanyo;

        if(posXfondo == 2460 && irAlSegundoBoss)
            posXfondo = 4100 - tamanyo;

        //FIN DEL JUEGO
        if(posXfondo == 4100) {
            posYfondo = 0;
            posXfondo -= tamanyo;
            stopFondo = true;
        }

        posXfondo += tamanyo;
    }


    //En las zonas de los bosses, que ya no se generen armas ni más enemigos
    if(posXfondo >= tamanyo*4) {
        stopArmas = true;
        stopEnemigos = true;

        //Entramos en la zona del primer boss
        if(posYfondo == 768 && posXfondo == 3280) {
            //Que solo genere el Boss la primera vez que entra
            if(!primerBoss) {
                vectorEnemigos.insert(vectorEnemigos.begin(), factoriaEnem.crearEnemigo(4, sf::Vector2f(396, 122), 0));
                relojBoss1.restart();
            }

            stopFondo = true;
            primerBoss = true;
        }

        //Entramos en la zona del segundo boss
        if(posYfondo == 768 && posXfondo == 4100) {
            if(!segundoBoss) {
                vectorEnemigos.insert(vectorEnemigos.begin(), factoriaEnem.crearEnemigo(4, sf::Vector2f(95, 122), 0));
                vectorEnemigos.insert(vectorEnemigos.begin(), factoriaEnem.crearEnemigo(4, sf::Vector2f(396, 270), 0));
                vectorEnemigos.insert(vectorEnemigos.begin(), factoriaEnem.crearEnemigo(4, sf::Vector2f(695, 122), 0));
                relojBoss2.restart();
            }

            stopFondo = true;
            segundoBoss = true;
        }
    }

    // Generamos las armas del juego de forma que se coloquen en las azoteas de los edificios
    if(!stopArmas)
        generarArmas();

    if(!stopFondo)
        posYfondo -= 4;

    fondo.setTextureRect(sf::IntRect(posXfondo, posYfondo, tamanyo, tamanyo));
}


void Juego::generarEnemigos() {

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

    if(relojEnemigos2.getElapsedTime().asSeconds() > 3.5 && relojEnemigos2.getElapsedTime().asMilliseconds() % 4 == 0) {
        vectorEnemigos.push_back(factoriaEnem.crearEnemigo(2, sf::Vector2f(jugador.getPosX(), jugador.getPosY()), 0));
        relojEnemigos2.restart();
    }

    if(relojEnemigos3.getElapsedTime().asSeconds() > 5 && relojEnemigos2.getElapsedTime().asMilliseconds() % 4 == 0) {
        vectorEnemigos.push_back(factoriaEnem.crearEnemigo(3, sf::Vector2f(jugador.getPosX(), jugador.getPosY()), 0));
        relojEnemigos3.restart();
    }
}


void Juego::generarArmas() {
    if(posYfondo / 820.f == 1) {
        srand(time(NULL));
        int tipoArma = (rand() % 3 + 1);
        vectorArmas.push_back(factoriaArma.crearArma(tipoArma, 1));
    }

    if(posYfondo / 820.f == 2) {
        srand(time(NULL));
        int tipoArma = (rand() % (3 - 1)) + 1;
        vectorArmas.push_back(factoriaArma.crearArma(tipoArma, 2));
    }

    if(posYfondo / 820.f == 3) {
        srand(time(NULL));
        int tipoArma = (rand() % (3 - 1)) + 1;
        vectorArmas.push_back(factoriaArma.crearArma(tipoArma, 0));
    }
}


void Juego::comprobarColisiones() {

    //Comprobar la colisión enemigo-disparo
    for(int i = 0; i < jugador.getDisparos().size(); i++)
        for(int j = 0; j < vectorEnemigos.size(); j++)
            if(jugador.getDisparos().size() > 0 && checkColisionED(*vectorEnemigos[j], *jugador.getDisparos()[i])) { //si estan colisionando

                jugador.borrarDisparo(i);
                hud.updatePuntuacion(vectorEnemigos[j]->getTipo());

                vectorEnemigos[j]->setNumVidas(vectorEnemigos[j]->getNumVidas() - 1);

                if(vectorEnemigos[j]->getNumVidas() == 0) {

                    if(vectorEnemigos[j]->getTipo() == 4) {
                        if(primerBoss) {
                            primerBoss = false;
                            irAlSegundoBoss = true;
                            posYfondo -= 4;
                        }

                        //Si hemos matado al último boss del nivel 2, el vector de enemigos en ese momento solo tendrá a ese boss
                        if(segundoBoss && vectorEnemigos.size() == 1) {
                            segundoBoss = false;
                            posYfondo -= 4;
                        }
                    }

                    delete vectorEnemigos[j];
                    vectorEnemigos[j] = nullptr;
                    vectorEnemigos.erase(vectorEnemigos.begin() + j);
                }
            }


    //Comprobar la colisión enemigo-jugador (solo si el modo dios está desactivado)
    if(!Window::getInstancia()->modoDios)
        for(int i = 0; i < vectorEnemigos.size(); i++)
            if(checkColisionEJ(*vectorEnemigos[i]))
                hud.updateVidas(-1);


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


bool Juego::checkColisionED(Enemigo enemigo, Disparo disparo) {
    bool colision = false;
    if (disparo.getGBounds().intersects(enemigo.getCirculoColision()))
        colision = true;

    return colision;
}

bool Juego::checkColisionEJ(Enemigo enemigo) {
    bool colision = false;
    if(jugador.getCirculoColision().intersects(enemigo.getCirculoColision()))
        colision = true;

    return colision;
}


bool Juego::checkColisionJA(Arma arma) {
    bool colision = false;
    if(jugador.getCirculoColision().intersects(arma.getGBnumero()))
        colision = true;

    return colision;
}


bool Juego::checkColisionDA(Arma arma, Disparo disparo) {
    bool colision = false;
    if (disparo.getGBounds().intersects(arma.getGBnumero()))
        colision = true;

    return colision;
}

sf::Vector2f Juego::getPosicionJugador() {
    return sf::Vector2f(jugador.getPosX(), jugador.getPosY());
}
