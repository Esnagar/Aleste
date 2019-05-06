#include "Disparo.h"

Disparo::Disparo(int tipoDisparo, sf::IntRect areaRecorte, float escala, float x, float y, sf::Vector2f direccionDisparo) {

    tipo = tipoDisparo;

    disparo.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    disparo.setTextureRect(areaRecorte);
    disparo.setOrigin(disparo.getGlobalBounds().width/2,disparo.getGlobalBounds().height/2);
    disparo.setScale(escala, escala);
    disparo.setPosition(x, y);

    if(tipo == 4) {
        direcDisparo.x = direccionDisparo.x;
        direcDisparo.y = direccionDisparo.y;
    }

    tiempo = 0;

    antes.setPosX(disparo.getPosition().x);
    antes.setPosY(disparo.getPosition().y);
    despues.setPosX(disparo.getPosition().x);
    despues.setPosY(disparo.getPosition().y);
}

Disparo::~Disparo() {}


void Disparo::update(sf::Vector2f posicionJugador, float tiempoPasado) {

    switch(tipo) {

        case 1:
            posicionFinal.x = disparo.getPosition().x;
            posicionFinal.y = disparo.getPosition().y - 0.5*tiempoPasado;
        break;


        //Disparo que se mantiene encima del jugador como un escudo
        case 2:
            //Si el jugador no ha dejado de pulsar la barra espaciadora no se dispara, en caso contrario, avanza
            if(Window::getInstancia()->inputs[5] && !disparado) {
                posicionFinal.x = posicionJugador.x;
                posicionFinal.y = posicionJugador.y - 70;
            } else {
                posicionFinal.x = disparo.getPosition().x;
                posicionFinal.y = disparo.getPosition().y - (float)Window::getInstancia()->numUpdates/20*tiempoPasado;
                disparado = true;
            }
        break;

        //El movimiento del disparo sigue la forma de una onda sinusoidal:  pos x = amplitud * cos(2*pi*frecuencia*tiempo)
        case 3:
            //Se ha usado cos() en lugar de sin() para que el disparo salga centrado. También se ha tenido que pasar el contenido
            //del coseno de grados a radianes. En cuanto a la posición de y, el disparo sube de forma constante.
            //posicionFinal.x = disparo.getPosition().x + (250 * cos((2*3.14159*1500*tiempo*3.14159) / 180))*(float)tiempoPasado/1000;
            posicionFinal.x = disparo.getPosition().x + (10*(60/Window::getInstancia()->numUpdates) * cos((2*3.14159*1250*tiempo*3.14159) / 180));
            posicionFinal.y = disparo.getPosition().y - 0.25*tiempoPasado;
            tiempo += 0.001*(60/Window::getInstancia()->numUpdates);
        break;

        case 4:
            posicionFinal.x = disparo.getPosition().x + direcDisparo.x * (float)Window::getInstancia()->numUpdates/80 * tiempoPasado;
            posicionFinal.y = disparo.getPosition().y + direcDisparo.y * (float)Window::getInstancia()->numUpdates/80 * tiempoPasado;
        break;
    }

    antes.setPosX(despues.getPosX());
    antes.setPosY(despues.getPosY());
    despues.setPosX(posicionFinal.x);
    despues.setPosY(posicionFinal.y);
}


void Disparo::render(float percentTick) {
    disparo.setPosition(antes.getPosX()*(1 - percentTick) + despues.getPosX()*percentTick, antes.getPosY()*(1 - percentTick) + despues.getPosY()*percentTick);
    Window::getInstancia()->renderWindow.draw(disparo);
}


bool Disparo::dentroPantalla() {
    if(getRight() < 0  || getLeft() > Window::getInstancia()->getTamanyo().x || getBottom() < 0 || getTop() > Window::getInstancia()->getTamanyo().y)
        return false;
    else
        return true;

}


void Disparo::cambiarSprite(std::string estado) {

    if(estado == "explosion") {
        disparo.setTextureRect(sf::IntRect(78, 224, 78, 71));
        disparo.setOrigin(disparo.getGlobalBounds().width/2,disparo.getGlobalBounds().height/2);
        disparo.setScale(0.6, 0.6);

        explotado = true;

    } else if(estado == "miniexplosion") {
        disparo.setTextureRect(sf::IntRect(160, 222, 64, 61));
        disparo.setOrigin(disparo.getGlobalBounds().width/2,disparo.getGlobalBounds().height/2);
        disparo.setScale(0.6, 0.6);

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

sf::FloatRect Disparo::getGBounds() {
    return disparo.getGlobalBounds();
}

bool Disparo::getExplotado() {
    return explotado;
}

int Disparo::setNumUpdates(int num) {
    numUpdates += num;
}

int Disparo::getNumUpdates() {
    return numUpdates;
}

int Disparo::getNumUpdatesTotales() {
    return numUpdatesTotales;
}

int Disparo::getTipo() {
    return tipo;
}

bool Disparo::getDisparado() {
    return disparado;
}

