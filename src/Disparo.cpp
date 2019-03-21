#include "Disparo.h"


Disparo::Disparo(std::string ruta, float x, float y) {

    TextureManager::loadTexture("disparo1", ruta);
    texDisparo = TextureManager::getTexture("disparo1")[0];
    disparo.setTexture(texDisparo);
    disparo.setTextureRect(sf::IntRect(190, 90, 50, 20));

    disparo.setOrigin(disparo.getGlobalBounds().width/2,disparo.getGlobalBounds().height/2);
    disparo.setRotation(90);
    disparo.setPosition(x, y);
}

Disparo::~Disparo() {}


void Disparo::update() {
    //comprobar colisiones con el enemigo
    disparo.move(0, -4);
}


void Disparo::render() {
    disparo.setTexture(texDisparo);
    disparo.setTextureRect(sf::IntRect(190, 90, 50, 20));
    Window::getInstancia()->renderWindow.draw(disparo);
}


bool Disparo::dentroPantalla() {
    if(getRight() < 0  || getLeft() > Window::getInstancia()->getTamanyo().x || getBottom() < 0 || getTop() >Window::getInstancia()->getTamanyo().y) {
        return false;

    } else {
        return true;
    }
}

void Disparo::cambiarSprite(string estado) {

    if(estado == "explosion") {
        disparo.setTexture(texDisparo);
        disparo.setTextureRect(sf::IntRect(200, 100, 50, 20));
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
