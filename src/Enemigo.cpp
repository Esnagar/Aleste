#include "Enemigo.h"


Enemigo::Enemigo(int tipoEnemigo, sf::Vector2f posicionJugador) {

    if(tipoEnemigo == 1) {
        tipo = tipoEnemigo;

        TextureManager::loadTexture("enemigo1", "resources/enemigos.png");
        texEnemigo = TextureManager::getTexture("enemigo1");

        enemigo.setTexture(*texEnemigo);
        enemigo.setPosition(320, 100);
        enemigo.setTextureRect(sf::IntRect(403, 165, 67, 70));
        enemigo.setScale(0.8, 0.8);
        enemigo.setOrigin(enemigo.getGlobalBounds().width/2, enemigo.getGlobalBounds().height/2);

        circuloColision.setRadius(enemigo.getGlobalBounds().width/3.0);
        circuloColision.setOrigin(circuloColision.getGlobalBounds().width/2, circuloColision.getGlobalBounds().height/2);

        aLaDerecha = true;
    }

    if(tipoEnemigo == 2) {
        tipo = tipoEnemigo;

        TextureManager::loadTexture("enemigo2", "resources/enemigos.png");
        texEnemigo = TextureManager::getTexture("enemigo2");

        enemigo.setTexture(*texEnemigo);
        enemigo.setPosition(500, 100);
        enemigo.setTextureRect(sf::IntRect(403, 165, 67, 70));
        enemigo.setScale(0.8, 0.8);
        enemigo.setOrigin(enemigo.getGlobalBounds().width/2, enemigo.getGlobalBounds().height/2);

        circuloColision.setRadius(enemigo.getGlobalBounds().width/3.0);
        circuloColision.setOrigin(circuloColision.getGlobalBounds().width/2, circuloColision.getGlobalBounds().height/2);

        float modulo = sqrt((enemigo.getPosition().x * posicionJugador.x) + (enemigo.getPosition().y * posicionJugador.y));
        direccionEnemigo.x = (posicionJugador.x - enemigo.getPosition().x) / modulo; //vector normalizado
        direccionEnemigo.y = (posicionJugador.y - enemigo.getPosition().y) / modulo; //vector normalizado
    }
}


void Enemigo::mover(int velocidad) {

    if(tipo == 1) {
        if(aLaDerecha) {
            enemigo.move(velocidad,0.05);

            if(enemigo.getPosition().x > Window::getInstancia()->getTamanyo().x - 150) aLaDerecha = false;

        } else {
            enemigo.move(-velocidad,0.05);

            if(enemigo.getPosition().x < 150)  aLaDerecha = true;
        }

        circuloColision.setPosition(enemigo.getPosition().x + 4, enemigo.getPosition().y + 4);
    }

    if(tipo == 2) {
        enemigo.move(direccionEnemigo.x * velocidad, direccionEnemigo.y * velocidad);
        circuloColision.setPosition(enemigo.getPosition().x + 4, enemigo.getPosition().y + 4);
    }

}


void Enemigo::update() {
    mover(5);
}


bool Enemigo::dentroPantalla() {
    if(getRight() < 0  || getLeft() > Window::getInstancia()->getTamanyo().x || getBottom() < 0 || getTop() >Window::getInstancia()->getTamanyo().y) {
        return false;

    } else {
        return true;
    }
}


void Enemigo::render() {
    enemigo.setTexture(*texEnemigo);
    enemigo.setTextureRect(sf::IntRect(403, 165, 67, 70));
    enemigo.setScale(0.8, 0.8);
    enemigo.setOrigin(enemigo.getGlobalBounds().width/2,enemigo.getGlobalBounds().height/2);

    Window::getInstancia()->draw(enemigo);
    Window::getInstancia()->draw(circuloColision);

}



bool Enemigo::checkColisionJugador(Jugador jugador) {
    bool colision = false;

    //if (enemigo.getGlobalBounds().intersects(jugador.getGBounds())) {
    if(sqrt(pow(jugador.getPosX() - enemigo.getPosition().x,2) + pow(jugador.getPosY() - enemigo.getPosition().y,2) )
        < (circuloColision.getRadius() + jugador.getRadioColision())) {
        colision = true;
    }
}


float Enemigo::getPosX() {
    return enemigo.getPosition().x;
}

float Enemigo::getPosY() {
    return enemigo.getPosition().y;
}

int Enemigo::getTipo() {
    return tipo;
}

sf::FloatRect Enemigo::getCirculoColision() {
    return circuloColision.getGlobalBounds();
}

int Enemigo::getRight() {
    return enemigo.getPosition().x + enemigo.getGlobalBounds().width;
}

int Enemigo::getLeft() {
    return enemigo.getPosition().x;
}

int Enemigo::getTop() {
    return enemigo.getPosition().y;
}

int Enemigo::getBottom() {
    return enemigo.getPosition().y + enemigo.getGlobalBounds().height;
}


Enemigo::~Enemigo() {}
