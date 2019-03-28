#include "Enemigo.h"


Enemigo::Enemigo(int tipoEnemigo) {

    if(tipoEnemigo == 1) {
        tipo = tipoEnemigo;

        TextureManager::loadTexture("enemigo1", "resources/enemigos.png");
        texEnemigo = TextureManager::getTexture("enemigo1");

        enemigo.setTexture(*texEnemigo);
        enemigo.setPosition(320, 100);

        aLaDerecha = true;
    }
}


void Enemigo::mover(int velocidad) {

    if(aLaDerecha) {
        enemigo.move(velocidad,0.05);

        if(enemigo.getPosition().x > Window::getInstancia()->getTamanyo().x - 150) aLaDerecha = false;

    } else {
        enemigo.move(-velocidad,0.05);

        if(enemigo.getPosition().x < 150)  aLaDerecha = true;
    }
}


void Enemigo::update() {
    mover(2);
}


void Enemigo::render() {
    enemigo.setTexture(*texEnemigo);
    enemigo.setTextureRect(sf::IntRect(400, 165, 70, 70));
    enemigo.setScale(0.8, 0.8);
    enemigo.setOrigin(enemigo.getGlobalBounds().width/2,enemigo.getGlobalBounds().height/2);

    Window::getInstancia()->draw(enemigo);
}


bool Enemigo::checkColisionDisparo(Disparo disparo) {
    bool colision = false;
    if (enemigo.getGlobalBounds().intersects(disparo.getGBounds())) {
        disparo.cambiarSprite("explosion");
        colision = true;
    }
}


bool Enemigo::checkColisionJugador(Jugador jugador) {
    bool colision = false;

    if (enemigo.getGlobalBounds().intersects(jugador.getGBounds())) {
        colision = true;
    }
}


float Enemigo::getPosX() {
    return enemigo.getPosition().x;
}

float Enemigo::getPosY() {
    return enemigo.getPosition().y;
}

int Enemigo::getTipo() {
    return tipo;
}


Enemigo::~Enemigo() {}
