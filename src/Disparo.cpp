#include "Disparo.h"


sf::Texture texDisparo;
sf::Sprite disparo;
float posX, posY;

Disparo::Disparo(std::string ruta, float x, float y) {

    TextureManager::loadTexture("disparo1", ruta);
    texDisparo = TextureManager::getTexture("disparo1")[0];
    disparo.setTexture(texDisparo);
    disparo.setTextureRect(sf::IntRect(190, 90, 50, 20));

    disparo.setOrigin(disparo.getGlobalBounds().width/2,disparo.getGlobalBounds().height/2);
    disparo.setRotation(90);
    disparo.setPosition(x, y);

}

void Disparo::mover(float x, float y) {
    disparo.move(x, y);
}


void Disparo::draw(sf::RenderWindow &window) {
    disparo.setTexture(texDisparo);
    disparo.setTextureRect(sf::IntRect(190, 90, 50, 20));
    window.draw(disparo);
}


bool Disparo::dentroPantalla(sf::RenderWindow &window) {
    if(getRight() < 0  || getLeft() > window.getSize().x || getBottom() < 0 || getTop() > window.getSize().y) {
        return false;

    } else {
        return true;
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


Disparo::~Disparo() {
}
