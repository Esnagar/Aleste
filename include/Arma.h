#ifndef ARMA_H
#define ARMA_H
#include "TextureManager.h"
#include "Window.h"

class Arma
{
    private:
        int idArma;
        sf::Sprite bola;
        sf::Sprite numeroSuelto;
        bool disparada = false;

    protected:

    public:
        Arma(int idArma, float x, float y);
        virtual ~Arma();

        void update();
        void render();

        int getTipo();

        void setDisparada();
        void armaActivada();

        bool getDisparada();

        sf::FloatRect getGBnumero();
        sf::FloatRect getGBbola();
};

#endif // ARMA_H
