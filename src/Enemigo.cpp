#include "Enemigo.h"


sf::Texture texEnemigo;
sf::Sprite enemigo;


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
}


void Enemigo::mover(float x, float y) {
    enemigo.move(x, y);
}


void Enemigo::checkColision(Disparo disparo) {

    if (enemigo.getPosition().x < disparo.getRight() &&
        enemigo.getPosition().x + enemigo.getGlobalBounds().width > disparo.getLeft() &&
        enemigo.getPosition().y < disparo.getBottom() &&
        enemigo.getPosition().y + enemigo.getGlobalBounds().height > disparo.getTop()) {

        enemigo.setPosition(sf::Vector2f(4234432, 4234423));
    }
}


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
