#include "Jugador.h"
#include "Window.h"

Jugador::Jugador() {}

Jugador::~Jugador() { }

Jugador::Jugador(std::string ruta) {

    if (!texJugador.loadFromFile(ruta)) {
        std::cerr << "Error cargando la imagen " << ruta;
        exit(0);
    }

    texJugador.setSmooth(true);

    jugador.setTexture(texJugador);
    jugador.setOrigin(jugador.getGlobalBounds().width/2, jugador.getGlobalBounds().height/2);
    jugador.setScale(0.1f, 0.15f);
    jugador.setPosition(Window::getInstancia()->getTamanyo().x/2, Window::getInstancia()->getTamanyo().y/2);
}



/*void Jugador::checkColision(Enemigo enemigo) {

    /*if (enemigo.getPosX() > jugador.getPosition().x &&
        enemigo.getPosY() < jugador.getPosition().y + jugador.getLocalBounds().height &&
        enemigo.getBottom() > jugador.getPosition().y) {

        jugador.setPosition(sf::Vector2f(4234432, 4234423));
    }*/
//}



void Jugador::update() {

    // Actualizar coordenadas
    if (Window::getInstancia()->inputs[0])  jugador.move(0, -kVELOCIDAD);
    if (Window::getInstancia()->inputs[1])  jugador.move(0, kVELOCIDAD);
    if (Window::getInstancia()->inputs[2])  jugador.move(-kVELOCIDAD, 0);
    if (Window::getInstancia()->inputs[3])  jugador.move(kVELOCIDAD, 0);

}


void Jugador::render() {
    Window::getInstancia()->renderWindow.draw(jugador);
}


float Jugador::getPosX() {
    return jugador.getPosition().x;
}

float Jugador::getPosY() {
    return jugador.getPosition().y;
}
