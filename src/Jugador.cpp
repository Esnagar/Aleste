#include "Jugador.h"
#include "Window.h"

Jugador::~Jugador() { }

Jugador::Jugador() {

    jugador.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    jugador.setTextureRect(sf::IntRect(0, 71, 78, 71));

    jugador.setOrigin(jugador.getGlobalBounds().width/2, jugador.getGlobalBounds().height/2);
    jugador.setScale(0.8f, 0.8f);
    jugador.setPosition(Window::getInstancia()->getTamanyo().x/2, Window::getInstancia()->getTamanyo().y - 100);

    circuloColision.setRadius(jugador.getGlobalBounds().width/3.0);
    circuloColision.setOrigin(circuloColision.getGlobalBounds().width/2, circuloColision.getGlobalBounds().height/2);

    arma = 1;
}

void Jugador::crearDisparo() {
    vectorDisparos.push_back(factoriaDisp.crearDisparo(1, jugador.getPosition()));

    if(arma != 1)
        vectorDisparos.push_back(factoriaDisp.crearDisparo(arma, jugador.getPosition()));
}

void Jugador::setArma(int tipo) {
    arma = tipo;
    std::cout << "Activada el arma: " << arma << std::endl;
}

int Jugador::getArma() {
    return arma;
}

void Jugador::update(float segundosUpdate) {

    //cambiarSprite();

    updateDisparos();

    // Actualizar coordenadas
    if (Window::getInstancia()->inputs[0])  Window::getInstancia()->setFirst(0, -kVELOCIDAD * segundosUpdate);
    if (Window::getInstancia()->inputs[1])  Window::getInstancia()->setFirst(0, kVELOCIDAD * segundosUpdate);
    if (Window::getInstancia()->inputs[2])  Window::getInstancia()->setFirst(-kVELOCIDAD * segundosUpdate, 0);
    if (Window::getInstancia()->inputs[3])  Window::getInstancia()->setFirst(kVELOCIDAD * segundosUpdate, 0);

    jugador.setPosition(Window::getInstancia()->last*(1-Window::getInstancia()->percent) + Window::getInstancia()->first*Window::getInstancia()->percent);
    circuloColision.setPosition(jugador.getPosition().x, jugador.getPosition().y);
}

void Jugador::updateDisparos() {
    //Updatear disparos
    for(int i=0; i<vectorDisparos.size(); i++) {
        vectorDisparos[i]->update(jugador.getPosition());

        //Eliminar los que salgan fuera de la pantalla
        if(!vectorDisparos[i]->dentroPantalla()) {
            delete vectorDisparos[i];
            vectorDisparos[i] = nullptr;
            vectorDisparos.erase(vectorDisparos.begin() + i);
            ///HACER i-- ???????????????????????
        }
    }
}

/*
void Jugador::cambiarSprite() {
    if(numSprite > 2)
        numSprite = 0;

    jugador.setTextureRect(sf::IntRect(numSprite*78, 71, 78, 71));
    numSprite++;
}*/


void Jugador::render() {

    for(int i = 0; i < vectorDisparos.size(); i++)
        vectorDisparos[i]->render();

    Window::getInstancia()->renderWindow.draw(circuloColision);
    Window::getInstancia()->renderWindow.draw(jugador);
}

float Jugador::getPosX() {
    return jugador.getPosition().x;
}

float Jugador::getPosY() {
    return jugador.getPosition().y;
}

sf::FloatRect Jugador::getCirculoColision() {
    return circuloColision.getGlobalBounds();
}

void Jugador::mover(float x, float y) {
    jugador.setPosition(x, y);
    circuloColision.setPosition(jugador.getPosition().x, jugador.getPosition().y);
}

sf::FloatRect Jugador::getGBounds() {
    return jugador.getGlobalBounds();
}


std::vector <Disparo*> Jugador::getDisparos() {
    return vectorDisparos;
}


void Jugador::borrarDisparo(int posicion) {
    delete vectorDisparos[posicion];
    vectorDisparos[posicion] = nullptr;
    vectorDisparos.erase(vectorDisparos.begin() + posicion);
}


