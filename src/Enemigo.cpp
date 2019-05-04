#include "Enemigo.h"

Enemigo::~Enemigo() {}

Enemigo::Enemigo(int tipoEnemigo, sf::IntRect areaRecorte, float escala, sf::Vector2f posicion, sf::Vector2f direccion, int numeroVidas) {

    tipo = tipoEnemigo;

    numVidas = numeroVidas;

    enemigo.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    enemigo.setTextureRect(areaRecorte);
    enemigo.setPosition(posicion);
    enemigo.setScale(escala, escala);
    enemigo.setOrigin(enemigo.getGlobalBounds().width/2, enemigo.getGlobalBounds().height/2);

    if(tipo == 4)
        circuloColision.setRadius(enemigo.getGlobalBounds().width/5.0);
    else
        circuloColision.setRadius(enemigo.getGlobalBounds().width/3.0);

    circuloColision.setOrigin(circuloColision.getGlobalBounds().width/2, circuloColision.getGlobalBounds().height/2);

    direccionEnemigo.x = direccion.x;
    direccionEnemigo.y = direccion.y;

    posXinicial = enemigo.getPosition().x;

    if(posXinicial >= Window::getInstancia()->getTamanyo().x/2)
        dirVelX = -dirVelX;

    antes.setPosX(enemigo.getPosition().x);
    antes.setPosY(enemigo.getPosition().y);
    despues.setPosX(enemigo.getPosition().x);
    despues.setPosY(enemigo.getPosition().y);
}


void Enemigo::mover(float velocidad, float tiempoPasado) {

    switch(tipo) {

        // Se mueve horizontalmente y poco a poco va bajando
        case 1:
            if(!aLaDerecha)
                velocidad = -velocidad;

            if(enemigo.getPosition().x > posXinicial + 150)
                aLaDerecha = false;

            else if(enemigo.getPosition().x < posXinicial - 150)
                aLaDerecha = true;


            posicionFinal.x = enemigo.getPosition().x + velocidad*tiempoPasado;
            posicionFinal.y = enemigo.getPosition().y + 0.05f*tiempoPasado;
            circuloColision.setPosition(enemigo.getPosition().x + 4, enemigo.getPosition().y + 4);

        break;


        //Coge la dirección del jugador en ese momento y se mueve en esa dirección
        case 2:
            posicionFinal.x = enemigo.getPosition().x + (direccionEnemigo.x * (velocidad+0.03))*tiempoPasado;
            posicionFinal.y = enemigo.getPosition().y + (direccionEnemigo.y * (velocidad+0.03))*tiempoPasado;

            circuloColision.setPosition(enemigo.getPosition().x + 4, enemigo.getPosition().y + 4);
        break;


        //Se mueve siguiendo un arco parabólico
        case 3:
            velY += gravedad*(60/Window::getInstancia()->numUpdates);
            posicionFinal.x = enemigo.getPosition().x + velX*dirVelX*(float)tiempoPasado/5;
            posicionFinal.y = enemigo.getPosition().y + velY*tiempoPasado;

            circuloColision.setPosition(enemigo.getPosition().x + 4, enemigo.getPosition().y + 4);
        break;


        case 4:
            circuloColision.setPosition(enemigo.getPosition().x + 15, enemigo.getPosition().y);
        break;
    }
}


void Enemigo::update(float tiempoPasado) {

    mover(0.3, tiempoPasado);
    antes.setPosX(despues.getPosX());
    antes.setPosY(despues.getPosY());
    despues.setPosX(posicionFinal.x);
    despues.setPosY(posicionFinal.y);
}


bool Enemigo::dentroPantalla() {
    if(getRight() < 0  || getLeft() > Window::getInstancia()->getTamanyo().x || getBottom() < 0 || getTop() > Window::getInstancia()->getTamanyo().y)
        return false;

    else
        return true;
}


void Enemigo::render(float percentTick) {
    if(tipo != 4) {
        enemigo.setPosition(antes.getPosX()*(1 - percentTick) + despues.getPosX()*percentTick, antes.getPosY()*(1 - percentTick) + despues.getPosY()*percentTick);
        circuloColision.setPosition(enemigo.getPosition().x, enemigo.getPosition().y);
    }

    Window::getInstancia()->draw(enemigo);
    //Window::getInstancia()->draw(circuloColision);
}


float Enemigo::getPosX() {
    return enemigo.getPosition().x;
}

float Enemigo::getPosY() {
    return enemigo.getPosition().y;
}

int Enemigo::getTipo() {
    return tipo;
}

sf::FloatRect Enemigo::getCirculoColision() {
    return circuloColision.getGlobalBounds();
}

int Enemigo::getRight() {
    return enemigo.getPosition().x + enemigo.getGlobalBounds().width;
}

int Enemigo::getLeft() {
    return enemigo.getPosition().x;
}

int Enemigo::getTop() {
    return enemigo.getPosition().y;
}

int Enemigo::getBottom() {
    return enemigo.getPosition().y + enemigo.getGlobalBounds().height;
}

int Enemigo::getNumVidas() {
    return numVidas;
}

void Enemigo::setNumVidas(int num) {
    numVidas = num;
}
