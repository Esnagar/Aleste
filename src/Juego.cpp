#include "Juego.h"
#include "Jugador.h"
#include "Window.h"
#include "Disparo.h"

Juego::Juego(): ventana(), jugador("resources/nave.png"){ }

Juego::~Juego() {}



void Juego::update() {
    ventana.update();

    for (int i = 0; i < vectorDisparos.size(); i++) {
        vectorDisparos[i].update();

        if(!vectorDisparos[i].dentroPantalla(ventana))
            vectorDisparos.erase(vectorDisparos.begin() + i);
    }

    //disparo.update();
    procesarInput();
}


void Juego::procesarInput() {

    sf::Event event;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        jugador.mover(-kVELOCIDAD, 0);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        jugador.mover(kVELOCIDAD, 0);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        jugador.mover(0, -kVELOCIDAD);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        jugador.mover(0, kVELOCIDAD);

    /*        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            Disparo disparo("resources/disparos.png", jugador.getPosX(), jugador.getPosY() - 70);
            anyadirDisparo(disparo);
        }*/

}

void Juego::anyadirDisparo(Disparo disparo) {
     vectorDisparos.push_back(disparo);
}


void Juego::render() {
    ventana.beginDraw();
    jugador.draw(ventana);
    for (int i = 0; i < vectorDisparos.size(); i++) {
        vectorDisparos[i].draw(ventana);
    }
    ventana.endDraw();
}



Window* Juego::getWindow() { return &ventana; }
