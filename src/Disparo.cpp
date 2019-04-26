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
}

Disparo::~Disparo() {}


void Disparo::update(sf::Vector2f posicionJugador) {

    switch(tipo) {

        case 1:
            disparo.move(0, -8);
        break;


        //Disparo que se mantiene encima del jugador como un escudo
        case 2:
            //Si el jugador no ha dejado de pulsar la barra espaciadora no se dispara, en caso contrario, avanza
            if(Window::getInstancia()->inputs[5])
                disparo.setPosition(posicionJugador.x, posicionJugador.y - 70);
            else
                disparo.move(0, -9);
        break;

        //El movimiento del disparo sigue la forma de una onda sinusoidal:  pos x = amplitud * cos(2*pi*frecuencia*tiempo)
        case 3:
            //Se ha usado cos() en lugar de sin() para que el disparo salga centrado. También se ha tenido que pasar el contenido
            //del coseno de grados a radianes. En cuanto a la posición de y, el disparo sube de forma constante.
            disparo.setPosition(disparo.getPosition().x + 10 * cos((2*3.14159*1250*tiempo * 3.14159) / 180), disparo.getPosition().y - 5);
            tiempo += 0.001;
        break;

        case 4:
            disparo.move(direcDisparo.x * 5, direcDisparo.y * 5);
        break;
    }
}


void Disparo::render() {
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
        disparo.setPosition(disparo.getPosition().x - 1, disparo.getPosition().y);

        explotado = true;

    } else if(estado =="miniexplosion") {
        disparo.setTextureRect(sf::IntRect(160, 222, 64, 61));
        disparo.setOrigin(disparo.getGlobalBounds().width/2,disparo.getGlobalBounds().height/2);
        disparo.setScale(0.6, 0.6);
        disparo.setPosition(disparo.getPosition().x - 3, disparo.getPosition().y);

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
