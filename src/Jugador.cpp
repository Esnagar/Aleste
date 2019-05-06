#include "Jugador.h"

Jugador::~Jugador() { }

Jugador::Jugador() {

    jugador.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    jugador.setTextureRect(sf::IntRect(0, 71, 78, 71));

    jugador.setOrigin(jugador.getGlobalBounds().width/2, jugador.getGlobalBounds().height/2);
    jugador.setScale(0.7f, 0.7f);
    jugador.setPosition(Window::getInstancia()->getTamanyo().x/2, Window::getInstancia()->getTamanyo().y/2 + 200);

    antes.setPosX(jugador.getPosition().x);
    antes.setPosY(jugador.getPosition().y);
    despues.setPosX(jugador.getPosition().x);
    despues.setPosY(jugador.getPosition().y);

    circuloColision.setRadius(jugador.getGlobalBounds().width/3.0);
    circuloColision.setOrigin(circuloColision.getGlobalBounds().width/2, circuloColision.getGlobalBounds().height/2);

    arma = 1;
}

void Jugador::crearDisparo() {
    vectorDisparos.push_back(factoriaDisp.crearDisparo(1, jugador.getPosition(), sf::Vector2f(0,0)));

    if(arma == 2 && !escudoActivado) { //Para que no genere disparos del tipo 2 mientras se tiene pulsada la barra espaciadora
        vectorDisparos.push_back(factoriaDisp.crearDisparo(2, jugador.getPosition(), sf::Vector2f(0,0)));
        escudoActivado = true;
    }

    if(arma == 3)
        vectorDisparos.push_back(factoriaDisp.crearDisparo(3, jugador.getPosition(), sf::Vector2f(0,0)));
}

void Jugador::setArma(int tipo) {
    arma = tipo;
    escudoActivado = false;
    std::cout << "Activada el arma: " << arma << std::endl;
}

int Jugador::getArma() {
    return arma;
}

void Jugador::update(float tiempoPasado) {
    if(inmortal && relojInmortal.getElapsedTime().asSeconds() > 3) {
        cambiarSprite("normal");
        inmortal = false;
    }

    updateDisparos(tiempoPasado);

    // Actualizar coordenadas

    kVELOCIDADx = 0;
    kVELOCIDADy = 0;

    if (Window::getInstancia()->inputs[0])  kVELOCIDADy = -0.5;
    if (Window::getInstancia()->inputs[1])  kVELOCIDADy = 0.5;
    if (Window::getInstancia()->inputs[2])  kVELOCIDADx = -0.5;
    if (Window::getInstancia()->inputs[3])  kVELOCIDADx = 0.5;

    //Para que no se salga de la pantalla
    if(jugador.getPosition().x + jugador.getGlobalBounds().width/2 > 802)
        posicionFinal.x = 802 - jugador.getGlobalBounds().width/2;

    if(jugador.getPosition().x - jugador.getGlobalBounds().width/2 < 18)
        posicionFinal.x = 18 + jugador.getGlobalBounds().width/2;

    if(jugador.getPosition().y + jugador.getGlobalBounds().height/2 > 622)
        posicionFinal.y = 622 - jugador.getGlobalBounds().height/2;

    if(jugador.getPosition().y - jugador.getGlobalBounds().height/2 < 53)
        posicionFinal.x = 53 + jugador.getGlobalBounds().height/2;

    posicionFinal.x = jugador.getPosition().x + kVELOCIDADx*tiempoPasado;
    posicionFinal.y = jugador.getPosition().y + kVELOCIDADy*tiempoPasado;

    antes.setPosX(despues.getPosX());
    antes.setPosY(despues.getPosY());
    despues.setPosX(posicionFinal.x);
    despues.setPosY(posicionFinal.y);
}

void Jugador::updateDisparos(float tiempoPasado) {
    //Updatear disparos
    for(int i=0; i<vectorDisparos.size(); i++) {
        vectorDisparos[i]->update(jugador.getPosition(), tiempoPasado);

        if(vectorDisparos[i]->getTipo() == 2 && vectorDisparos[i]->getDisparado())
            escudoActivado = false;

        //Eliminar los que salgan fuera de la pantalla
        if(!vectorDisparos[i]->dentroPantalla()) {
            if(vectorDisparos[i]->getTipo() == 2)
                escudoActivado = false;

            delete vectorDisparos[i];
            vectorDisparos[i] = nullptr;
            vectorDisparos.erase(vectorDisparos.begin() + i);
        }
    }
}


void Jugador::render(float percentTick) {

    jugador.setPosition((float)antes.getPosX()*(1 - percentTick) + despues.getPosX()*percentTick, (float)antes.getPosY()*(1 - percentTick) + despues.getPosY()*percentTick);
    circuloColision.setPosition(jugador.getPosition().x, jugador.getPosition().y);

    for(int i = 0; i < vectorDisparos.size(); i++)
        vectorDisparos[i]->render(percentTick);

    //Window::getInstancia()->renderWindow.draw(circuloColision);
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

sf::FloatRect Jugador::getGBounds() {
    return jugador.getGlobalBounds();
}

std::vector <Disparo*> Jugador::getDisparos() {
    return vectorDisparos;
}

void Jugador::setInmortal() {
    inmortal = true;
    cambiarSprite("inmortal");
    relojInmortal.restart();
}

bool Jugador::getInmortal() {
    return inmortal;
}

void Jugador::borrarDisparo(int posicion) {
    if(vectorDisparos[posicion]->getTipo() == 2)
        escudoActivado = false;

    delete vectorDisparos[posicion];
    vectorDisparos[posicion] = nullptr;
    vectorDisparos.erase(vectorDisparos.begin() + posicion);
}

void Jugador::cambiarSprite(std::string estado) {

    if(estado == "inmortal") {
        jugador.setTextureRect(sf::IntRect(78, 71, 78, 71));
        jugador.setScale(0.7f, 0.7f);
        jugador.setOrigin(jugador.getOrigin().x, jugador.getOrigin().y);

    } else if(estado == "normal") {
        jugador.setTextureRect(sf::IntRect(0, 71, 78, 71));
        jugador.setScale(0.7f, 0.7f);
        jugador.setOrigin(jugador.getOrigin().x, jugador.getOrigin().y);

    } else {
        std::cout << "No existe ese estado del jugador" << std::endl;
    }
}

