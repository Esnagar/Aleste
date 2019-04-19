#ifndef ARMA_H
#define ARMA_H
#include "TextureManager.h"
#include "Window.h"

class Arma
{
    public:
        Arma();
        Arma(int idArma);
        virtual ~Arma();

        void update();
        void render();

        int getTipo();

        void setDisparada();
        void armaActivada();

        sf::FloatRect getGBnumero();
        sf::FloatRect getGBbola();

    protected:

    private:
        int idArma;
        sf::Sprite bola;
        sf::Sprite numeroSuelto;

        bool disparada = false;
};

#endif // ARMA_H
