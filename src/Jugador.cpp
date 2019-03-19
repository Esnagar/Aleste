#include "Jugador.h"


sf::Texture texJugador;
sf::Sprite jugador;

Jugador::Jugador() {}


Jugador::Jugador(std::string ruta) {

    if (!texJugador.loadFromFile(ruta)) {
        std::cerr << "Error cargando la imagen " << ruta;
        exit(0);
    }

    texJugador.setSmooth(true);

    jugador.setTexture(texJugador);
    jugador.setOrigin(jugador.getGlobalBounds().width/2, jugador.getGlobalBounds().height/2);
    jugador.setScale(0.3f, 0.3f);
    jugador.setPosition(320, 240);
}

void Jugador::mover(float x, float y) {
    jugador.move(x, y);
}


void Jugador::checkColision(Enemigo enemigo) {

    /*if (enemigo.getPosX() > jugador.getPosition().x &&
        enemigo.getPosY() < jugador.getPosition().y + jugador.getLocalBounds().height &&
        enemigo.getBottom() > jugador.getPosition().y) {

        jugador.setPosition(sf::Vector2f(4234432, 4234423));
    }*/
}


void Jugador::draw(Window &window) {
    window.draw(jugador);
}

float Jugador::getPosX() {
    return jugador.getPosition().x;
}

float Jugador::getPosY() {
    return jugador.getPosition().y;
}


Jugador::~Jugador() { }
