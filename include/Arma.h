#ifndef ARMA_H
#define ARMA_H
#include "TextureManager.h"
#include "Window.h"
#include "Interpolacion.h"

class Arma
{
    private:
        int idArma;
        sf::Sprite bola;
        sf::Sprite numeroSuelto;
        bool disparada = false;

        Interpolacion antes;
        Interpolacion despues;
        Interpolacion antes2;
        Interpolacion despues2;

    protected:

    public:
        Arma(int idArma, float x, float y);
        virtual ~Arma();

        void update(float tiempoPasado);
        void render(float percentTick, int numVidas);

        int getTipo();

        void setDisparada();
        void armaActivada();

        bool getDisparada();

        sf::FloatRect getGBnumero();
        sf::FloatRect getGBbola();
};

#endif // ARMA_H
