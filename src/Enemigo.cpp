#include "Enemigo.h"


Enemigo::Enemigo(int tipo) {

    if(tipo == 1) {
        TextureManager::loadTexture("enemigo1", "resources/enemigos.png");
        texEnemigo = TextureManager::getTexture("enemigo1");

        enemigo.setTexture(*texEnemigo);
        enemigo.setPosition(320, 100);

        aLaDerecha = true;
    }
}


void Enemigo::mover(int velocidad) {

    if(aLaDerecha) {
        enemigo.move(velocidad,0);

        if(enemigo.getPosition().x > Window::getInstancia()->getTamanyo().x - 50) aLaDerecha = false;

    } else {
        enemigo.move(-velocidad,0);

        if(enemigo.getPosition().x < 50)  aLaDerecha = true;
    }
}


void Enemigo::update() {
    mover(2);
}


void Enemigo::render() {
    enemigo.setTexture(*texEnemigo);
    enemigo.setTextureRect(sf::IntRect(400, 165, 70, 70));
    enemigo.setScale(0.8, 0.8);
    enemigo.setOrigin(enemigo.getGlobalBounds().width/2,enemigo.getGlobalBounds().height/2);

    Window::getInstancia()->draw(enemigo);
}


/*void Enemigo::checkColision(Disparo disparo) {

    if (enemigo.getGlobalBounds().intersects(disparo.getGlobalBounds())) {
        enemigo.setPosition(sf::Vector2f(4234432, 4234423)); //Eliminar al enemigo pero no se como aun jj
        disparo.cambiarSprite("explosion");
    }
}*/



float Enemigo::getPosX() {
    return enemigo.getPosition().x;
}

float Enemigo::getPosY() {
    return enemigo.getPosition().y;
}


Enemigo::~Enemigo() {}
