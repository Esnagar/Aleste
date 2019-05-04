#include "Arma.h"

Arma::Arma(int id, float x, float y) {

    idArma = id;
    id--; //Para obtener su IntRect correspondiente

    bola.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    bola.setTextureRect(sf::IntRect(id*78, 0, 78, 71));
    bola.setScale(0.6, 0.6);
    bola.setOrigin(bola.getGlobalBounds().width/2, bola.getGlobalBounds().height/2);
    bola.setPosition(x, y);

    numeroSuelto.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    numeroSuelto.setTextureRect(sf::IntRect(312 + id*39, 0, 39, 71));
    numeroSuelto.setScale(0.6, 0.6);
    numeroSuelto.setOrigin(numeroSuelto.getGlobalBounds().width/2, numeroSuelto.getGlobalBounds().height/2);
    numeroSuelto.setPosition(bola.getPosition().x + 5, bola.getPosition().y - 15);

    antes.setPosX(bola.getPosition().x);
    antes.setPosY(bola.getPosition().y);
    despues.setPosX(bola.getPosition().x);
    despues.setPosY(bola.getPosition().y);

    antes2.setPosX(numeroSuelto.getPosition().x);
    antes2.setPosY(numeroSuelto.getPosition().y);
    despues2.setPosX(numeroSuelto.getPosition().x);
    despues2.setPosY(numeroSuelto.getPosition().y);
}

Arma::~Arma() {}

void Arma::update(float tiempoPasado) {
    bola.setPosition(bola.getPosition().x, bola.getPosition().y + (float)4.82*tiempoPasado/30);

    if(disparada)
        numeroSuelto.setPosition(numeroSuelto.getPosition().x, numeroSuelto.getPosition().y - 1.2*tiempoPasado/30);
    else
        numeroSuelto.setPosition(bola.getPosition().x + 5, bola.getPosition().y - 15);

    antes.setPosX(despues.getPosX());
    antes.setPosY(despues.getPosY());
    despues.setPosX(bola.getPosition().x);
    despues.setPosY(bola.getPosition().y);

    antes2.setPosX(despues2.getPosX());
    antes2.setPosY(despues2.getPosY());
    despues2.setPosX(numeroSuelto.getPosition().x);
    despues2.setPosY(numeroSuelto.getPosition().y);
}

void Arma::render(float percentTick, int numVidas) {

    if(numVidas > 0)
        bola.setPosition(antes.getPosX()*(1 - percentTick) + despues.getPosX()*percentTick, antes.getPosY()*(1 - percentTick) + despues.getPosY()*percentTick);

    Window::getInstancia()->draw(bola);

    if(disparada) {
        if(numVidas > 0)
            numeroSuelto.setPosition(antes2.getPosX()*(1 - percentTick) + despues2.getPosX()*percentTick, antes2.getPosY()*(1 - percentTick) + despues2.getPosY()*percentTick);
        Window::getInstancia()->draw(numeroSuelto);
    }
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

