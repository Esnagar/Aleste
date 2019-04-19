#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureManager.h"

class HUD
{
    public:
        HUD();
        virtual ~HUD();
        void crearText(sf::Text &texto, std::string str, float posX, float posY);

        void updatePuntuacion(int tipoEnemigo);
        void updateVidas(int vidas);

        void render();

    protected:

    private:

        int puntuacion;
        int tipoArma;
        int disparosArma;
        int numVidas;

        sf::Font* fuente = new sf::Font;;
        sf::Text sc;
        sf::Text scNUM;
        sf::Text arm;
        sf::Text armNUM;
        sf::Text dispNUM;
        sf::Text vidasNUM;

        sf::Texture texMininave;
        sf::Sprite mininave;

        sf::RectangleShape bandaNegra;
        sf::RectangleShape marcoVerde;
};

#endif // HUD_H
