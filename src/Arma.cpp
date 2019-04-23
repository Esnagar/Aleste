#include "Arma.h"

Arma::Arma(int id) {

    idArma = id;
    id--; //Para obtener su IntRect correspondiente

    bola.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    bola.setTextureRect(sf::IntRect(id*78, 0, 78, 71));
    bola.setScale(0.7, 0.7);
    bola.setOrigin(bola.getGlobalBounds().width/2, bola.getGlobalBounds().height/2);
    bola.setPosition(100, 100);

    numeroSuelto.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    numeroSuelto.setTextureRect(sf::IntRect(312 + id*39, 0, 39, 71));
    numeroSuelto.setScale(0.7, 0.7);
    numeroSuelto.setOrigin(numeroSuelto.getGlobalBounds().width/2, numeroSuelto.getGlobalBounds().height/2);
    numeroSuelto.setPosition(bola.getPosition().x + 5, bola.getPosition().y - 15);
}

Arma::~Arma() {}

void Arma::update() {
    bola.move(0, 4);

    if(disparada)
        numeroSuelto.move(0, -0.5);
    else
        numeroSuelto.setPosition(bola.getPosition().x + 5, bola.getPosition().y - 15);
}

void Arma::render() {
    Window::getInstancia()->draw(bola);

    if(disparada)
        Window::getInstancia()->draw(numeroSuelto);
}

void Arma::armaActivada() {
    numeroSuelto.setTextureRect(sf::IntRect(0,0,0,0));
}

void Arma::setDisparada() {
    disparada = true;
    bola.setTextureRect(sf::IntRect(234, 0, 78, 71));
}

bool Arma::getDisparada() {
    return disparada;
}

int Arma::getTipo() {
    return idArma;
}

sf::FloatRect Arma::getGBnumero() {
    return numeroSuelto.getGlobalBounds();
}

sf::FloatRect Arma::getGBbola() {
    return bola.getGlobalBounds();
}

