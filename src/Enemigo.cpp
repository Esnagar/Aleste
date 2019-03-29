#include "Enemigo.h"


Enemigo::Enemigo(int tipoEnemigo) {

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
}


void Enemigo::mover(int velocidad) {

    if(aLaDerecha) {
        enemigo.move(velocidad,0.05);

        if(enemigo.getPosition().x > Window::getInstancia()->getTamanyo().x - 150) aLaDerecha = false;

    } else {
        enemigo.move(-velocidad,0.05);

        if(enemigo.getPosition().x < 150)  aLaDerecha = true;
    }

    circuloColision.setPosition(enemigo.getPosition().x + 4, enemigo.getPosition().y + 4);

}


void Enemigo::update() {
    mover(5);
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


Enemigo::~Enemigo() {}
