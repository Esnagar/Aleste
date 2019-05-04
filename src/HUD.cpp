#include "HUD.h"

HUD::HUD() {
    puntuacion = 0;
    numVidas = 3;
    tipoArma = 1;

    marcoVerde.setFillColor(sf::Color::Transparent);
    marcoVerde.setOutlineColor(sf::Color(0, 75, 0));
    marcoVerde.setOutlineThickness(18);
    marcoVerde.setSize(sf::Vector2f(Window::getInstancia()->getTamanyo().x - marcoVerde.getOutlineThickness()*2,
                                    Window::getInstancia()->getTamanyo().y - marcoVerde.getOutlineThickness()*2));
    marcoVerde.setPosition(18, 18);

    bandaNegra.setFillColor(sf::Color::Black);
    bandaNegra.setSize(sf::Vector2f(Window::getInstancia()->getTamanyo().x, 35));
    bandaNegra.setPosition(0, marcoVerde.getOutlineThickness());

    fuente->loadFromFile("resources/arcade.TTF");

    crearText(sc, "SC", 25, 65, 33);
    crearText(arm, "ARM  -", 25, 435, 33);
    crearText(gameOver, "GAME\nOVER", 70, Window::getInstancia()->getTamanyo().x/2, Window::getInstancia()->getTamanyo().y/2);

    //NÚMEROS
    crearText(scNUM, std::to_string(puntuacion), 25, 220, 33);
    crearText(armNUM, std::to_string(tipoArma), 25, 463, 33);
    crearText(vidasNUM, std::to_string(numVidas), 25, 740, 33);

    mininave.setTexture(*TextureManager::getInstancia()->getTexture("Spritesheet"));
    mininave.setTextureRect(sf::IntRect(0, 71, 78, 71));
    mininave.setOrigin(mininave.getGlobalBounds().width/2, mininave.getGlobalBounds().height/2);
    mininave.setScale(0.3f, 0.3f);
    mininave.setPosition(690, 33);

}

HUD::~HUD() {}

void HUD::setArma(int tipoArma) {
    if(tipoArma != 1) {
        disparosArma = 80;
        arm.setString("ARM  - " + std::to_string(disparosArma));
    } else {
        arm.setString("ARM  - ");
    }

    armNUM.setString(std::to_string(tipoArma));
}

void HUD::updateDisparosArma() {
    disparosArma--;
    arm.setString("ARM  - " + std::to_string(disparosArma));
}

int HUD::getDisparosArma() {
    return disparosArma;
}

void HUD::updatePuntuacion(int tipoEnemigo) {

    switch(tipoEnemigo) {
        case 1: puntuacion += 100; puntuacion2 += 100; break;
        case 2: puntuacion += 500; puntuacion2 += 500; break;
        case 3: puntuacion += 300; puntuacion2 += 300; break;
        case 4: puntuacion += 5000; puntuacion2 += 5000; break;
    }

    if(puntuacion2/6000 > 0) {
        updateVidas(1);
        puntuacion2 = 0;
    }

    scNUM.setString(std::to_string(puntuacion));
}

void HUD::updateVidas(int vidas) {
    numVidas += vidas;
    vidasNUM.setString(std::to_string(numVidas));
}

void HUD::updateMarco() {
    if(Window::getInstancia()->modoDios)
        marcoVerde.setOutlineColor(sf::Color(255, 242, 0));
    else
        marcoVerde.setOutlineColor(sf::Color(0, 75, 0));
}

void HUD::render() {
    Window::getInstancia()->renderWindow.draw(bandaNegra);
    Window::getInstancia()->renderWindow.draw(marcoVerde);
    Window::getInstancia()->renderWindow.draw(sc);
    Window::getInstancia()->renderWindow.draw(arm);
    Window::getInstancia()->renderWindow.draw(mininave);
    Window::getInstancia()->renderWindow.draw(scNUM);
    Window::getInstancia()->renderWindow.draw(armNUM);
    Window::getInstancia()->renderWindow.draw(vidasNUM);

    if(numVidas <= 0)
        Window::getInstancia()->renderWindow.draw(gameOver);
}


void HUD::crearText(sf::Text &texto, std::string str, int tamanyo, float posX, float posY){
    texto.setFont(*fuente);
    texto.setCharacterSize(tamanyo);
    texto.setColor(sf::Color::White);
    texto.setString(str);
    texto.setOrigin(texto.getGlobalBounds().width/2, texto.getGlobalBounds().height/2);
    texto.setPosition(posX, posY);
}


int HUD::getNumVidas() {
    return numVidas;
}


