#include "FactoryArma.h"

FactoryArma::FactoryArma() { }

FactoryArma::~FactoryArma() { }

Arma* FactoryArma::crearArma(int p_tipo, int posicion) {

    tipo = p_tipo;

    switch(posicion) {

        case 0: //izquierda
            posX = 120;
            posY = -190;
        break;

        case 1: //centro
            posX = 380;
            posY = -195;
        break;

        case 2: //derecha
            posX = 680;
            posY = -190;
        break;
    }

    return new Arma(tipo, posX, posY);

}
