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

    if(tipo == 4 || tipo == 5)
        circuloColision.setRadius(enemigo.getGlobalBounds().width/5.0);
    else
        circuloColision.setRadius(enemigo.getGlobalBounds().width/3.0);

    circuloColision.setOrigin(circuloColision.getGlobalBounds().width/2, circuloColision.getGlobalBounds().height/2);

    direccionEnemigo.x = direccion.x;
    direccionEnemigo.y = direccion.y;

    posXinicial = enemigo.getPosition().x;

    if(posXinicial >= Window::getInstancia()->getTamanyo().x/2)
        dirVelX = -1;
}


void Enemigo::mover(int velocidad) {

    switch(tipo) {

        // Se mueve horizontalmente y poco a poco va bajando
        case 1:
            if(aLaDerecha)
                enemigo.move(velocidad,0.5);
            else
                enemigo.move(-velocidad,0.5);


            if(enemigo.getPosition().x > posXinicial + 150)
                aLaDerecha = false;

            else if(enemigo.getPosition().x < posXinicial - 150)
                aLaDerecha = true;

            circuloColision.setPosition(enemigo.getPosition().x + 4, enemigo.getPosition().y + 4);
        break;


        //Coge la dirección del jugador en ese momento y se mueve en esa dirección
        case 2:
            enemigo.move(direccionEnemigo.x * (velocidad+2), direccionEnemigo.y * (velocidad+2));
            circuloColision.setPosition(enemigo.getPosition().x + 4, enemigo.getPosition().y + 4);
        break;


        //Se mueve siguiendo un arco parabólico
        case 3:
            velY += gravedad;
            enemigo.setPosition(enemigo.getPosition().x + velX * dirVelX, enemigo.getPosition().y + velY);
            circuloColision.setPosition(enemigo.getPosition().x + 4, enemigo.getPosition().y + 4);
        break;


        case 4:
            circuloColision.setPosition(enemigo.getPosition().x + 15, enemigo.getPosition().y + 4);
        break;
    }

}


void Enemigo::update() {
    mover(5);
}


bool Enemigo::dentroPantalla() {
    if(getRight() < 0  || getLeft() > Window::getInstancia()->getTamanyo().x || getBottom() < 0 || getTop() > Window::getInstancia()->getTamanyo().y)
        return false;

    else
        return true;
}


void Enemigo::render() {
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
