#ifndef DISPARO_H
#define DISPARO_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Disparo
{
    private:
        sf::Texture texDisparo;
        sf::Sprite disparo;
        float posX, posY;


    protected:



    public:

        Disparo(std::string ruta) {

            if (!texDisparo.loadFromFile(ruta)) {
                std::cerr << "Error cargando la imagen " << ruta;
                exit(0);
            }

            texDisparo.setSmooth(true);
            sf::Texture::bind(&texDisparo);

            disparo.setTexture(texDisparo);
            disparo.setOrigin(disparo.getGlobalBounds().width/2,disparo.getGlobalBounds().height/2);
            disparo.setTextureRect(sf::IntRect(190, 90, 50, 20));
            disparo.setRotation(90);
        }

        void mover(float x, float y) {
            posX = x;
            posY = y;
            //disparo.setPosition(posX, posY);
            disparo.move(posX, posY);
        }

        void setPosicion(float x, float y) {
            posX = x;
            posY = y;
            //disparo.setPosition(posX, posY);
            disparo.setPosition(posX, posY);
        }


        void draw(sf::RenderWindow &window) {
            window.draw(disparo);
        }

        float getPosX() {
            return posX;
        }

        float getPosY() {
            return posY;
        }
};

#endif // DISPARO_H

Spaceship::Spaceship(const sf::RenderWindow& window) {
    // Some stuff
    ss_ship_texture.loadFromFile("path/to/ship/image");
    ss_ship.setTexture(ss_ship_texture);
}s

