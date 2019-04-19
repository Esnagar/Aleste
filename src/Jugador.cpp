#include "Jugador.h"
#include "Window.h"

Jugador::Jugador(std::string ruta) {}

Jugador::~Jugador() { }

Jugador::Jugador() {

    jugador.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    jugador.setTextureRect(sf::IntRect(0, 71, 78, 71));

    jugador.setOrigin(jugador.getGlobalBounds().width/2, jugador.getGlobalBounds().height/2);
    jugador.setScale(0.8f, 0.8f);
    jugador.setPosition(Window::getInstancia()->getTamanyo().x/2, Window::getInstancia()->getTamanyo().y - 100);

    circuloColision.setRadius(jugador.getGlobalBounds().width/3.0);
    circuloColision.setOrigin(circuloColision.getGlobalBounds().width/2, circuloColision.getGlobalBounds().height/2);

}



void Jugador::update(float segundosUpdate) {

    // Actualizar coordenadas
    if (Window::getInstancia()->inputs[0])  Window::getInstancia()->setFirst(0, -kVELOCIDAD * segundosUpdate);
    if (Window::getInstancia()->inputs[1])  Window::getInstancia()->setFirst(0, kVELOCIDAD * segundosUpdate);
    if (Window::getInstancia()->inputs[2])  Window::getInstancia()->setFirst(-kVELOCIDAD * segundosUpdate, 0);
    if (Window::getInstancia()->inputs[3])  Window::getInstancia()->setFirst(kVELOCIDAD * segundosUpdate, 0);

    jugador.setPosition(Window::getInstancia()->last*(1-Window::getInstancia()->percent) + Window::getInstancia()->first*Window::getInstancia()->percent);
    circuloColision.setPosition(jugador.getPosition().x, jugador.getPosition().y);
}


void Jugador::render() {
    Window::getInstancia()->renderWindow.draw(circuloColision);
    Window::getInstancia()->renderWindow.draw(jugador);
}


float Jugador::getPosX() {
    return jugador.getPosition().x;
}

float Jugador::getPosY() {
    return jugador.getPosition().y;
}

float Jugador::getRadioColision() {
    return circuloColision.getRadius();
}

void Jugador::mover(float x, float y) {
    jugador.setPosition(x, y);
    circuloColision.setPosition(jugador.getPosition().x, jugador.getPosition().y);
}

sf::FloatRect Jugador::getGBounds() {
    return jugador.getGlobalBounds();
}


