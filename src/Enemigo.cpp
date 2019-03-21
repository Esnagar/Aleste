#include "Enemigo.h"


Enemigo::Enemigo(std::string ruta) {

    if (!texEnemigo.loadFromFile(ruta)) {
        std::cerr << "Error cargando la imagen " << ruta;
        exit(0);
    }

    texEnemigo.setSmooth(true);

    enemigo.setTexture(texEnemigo);
    enemigo.setTextureRect(sf::IntRect(0*75, 0*75, 75, 75));
    enemigo.setOrigin(enemigo.getGlobalBounds().width/2,enemigo.getGlobalBounds().height/2);
    enemigo.setPosition(320, 50);

    aLaDerecha = true;
}


void Enemigo::mover(int velocidad) {

    if(aLaDerecha) {
        enemigo.move(velocidad,0);

        if(enemigo.getPosition().x > 630) aLaDerecha = false;

    } else {
        enemigo.move(-velocidad,0);

        if(enemigo.getPosition().x < 50)  aLaDerecha = true;
    }
}


/*void Enemigo::checkColision(Disparo disparo) {

    if (enemigo.getGlobalBounds().intersects(disparo.getGlobalBounds())) {
        enemigo.setPosition(sf::Vector2f(4234432, 4234423)); //Eliminar al enemigo pero no se como aun jj
        disparo.cambiarSprite("explosion");
    }
}*/


void Enemigo::draw(sf::RenderWindow &window) {
    window.draw(enemigo);
}

float Enemigo::getPosX() {
    return enemigo.getPosition().x;
}

float Enemigo::getPosY() {
    return enemigo.getPosition().y;
}


Enemigo::~Enemigo() {

}
