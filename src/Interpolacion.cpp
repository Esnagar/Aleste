#include "Interpolacion.h"

Interpolacion::Interpolacion() {}

Interpolacion::~Interpolacion() {}


void Interpolacion::setPosX(float x) {
    posX = x;
}

void Interpolacion::setPosY(float y) {
    posY = y;
}

float Interpolacion::getPosX() {
    return posX;
}

float Interpolacion::getPosY() {
    return posY;
}
