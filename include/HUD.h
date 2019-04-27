#ifndef HUD_H
#define HUD_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureManager.h"
#include "Window.h"

class HUD
{
    public:
        HUD();
        virtual ~HUD();
        void crearText(sf::Text &texto, std::string str, int tamanyo, float posX, float posY);

        void updatePuntuacion(int tipoEnemigo);
        void updateVidas(int vidas);
        void updateDisparosArma();
        void updateMarco();

        void setArma(int tipoArma);
        int getDisparosArma();
        int getNumVidas();

        void render();

    protected:

    private:

        int puntuacion;
        int puntuacion2;
        int tipoArma;
        int disparosArma = 80;
        int numVidas;

        sf::Font* fuente = new sf::Font;
        sf::Text sc;
        sf::Text scNUM;
        sf::Text arm;
        sf::Text armNUM;
        sf::Text dispNUM;
        sf::Text vidasNUM;
        sf::Text gameOver;

        sf::Texture texMininave;
        sf::Sprite mininave;

        sf::RectangleShape bandaNegra;
        sf::RectangleShape marcoVerde;
};

#endif // HUD_H
