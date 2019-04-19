#include "Disparo.h"

Disparo::Disparo(std::string ruta, float x, float y) {

    disparo.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    disparo.setTextureRect(sf::IntRect(247, 142, 24, 71));
    disparo.setScale(0.7, 0.7);
    disparo.setOrigin(disparo.getGlobalBounds().width/2,disparo.getGlobalBounds().height/2);
    disparo.setPosition(x, y);
}

Disparo::~Disparo() {}


void Disparo::update() {
    //comprobar colisiones con el enemigo
    disparo.move(0, -7);
}


void Disparo::render() {
    Window::getInstancia()->renderWindow.draw(disparo);
}


bool Disparo::dentroPantalla() {
    if(getRight() < 0  || getLeft() > Window::getInstancia()->getTamanyo().x || getBottom() < 0 || getTop() >Window::getInstancia()->getTamanyo().y) {
        return false;

    } else {
        return true;
    }
}

bool Disparo::checkColisionDisparo(Enemigo enemigo) {
    bool colision = false;
    if (disparo.getGlobalBounds().intersects(enemigo.getCirculoColision())) {
        //disparo.cambiarSprite("explosion");
        colision = true;
    }
}

void Disparo::cambiarSprite(std::string estado) {

    if(estado == "explosion") {
        //Window::getInstancia()->renderWindow.draw(disparo);

    } else {
        std::cout << "No existe ese estado del disparo" << std::endl;
    }
}



int Disparo::getRight() {
    return disparo.getPosition().x + disparo.getGlobalBounds().width;
}

int Disparo::getLeft() {
    return disparo.getPosition().x;
}

int Disparo::getTop() {
    return disparo.getPosition().y;
}

int Disparo::getBottom() {
    return disparo.getPosition().y + disparo.getGlobalBounds().height;
}
