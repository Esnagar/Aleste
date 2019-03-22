#include "HUD.h"
#include "Window.h"

HUD::HUD() {
    puntuacion = 0;
    numVidas = 3;
    tipoArma = 1;

    caja.setFillColor(sf::Color::Black);
    caja.setOutlineColor(sf::Color::Blue);
    caja.setOutlineThickness(2.5);
    caja.setSize(sf::Vector2f(640, 35));

    fuente->loadFromFile("resources/arcade.TTF");

    crearText(sc, "SC", 40, 15);
    crearText(arm, "ARM  -", 352, 15);

    //NÚMEROS
    crearText(scNUM, std::to_string(puntuacion), 200, 15);
    crearText(armNUM, std::to_string(tipoArma), 385, 15);
    crearText(vidasNUM, std::to_string(numVidas), 600, 15);

    texMininave.loadFromFile("resources/nave2.png");
    texMininave.setSmooth(true);

    mininave.setTexture(texMininave);
    mininave.setOrigin(mininave.getGlobalBounds().width/2, mininave.getGlobalBounds().height/2);
    mininave.setScale(0.033f, 0.05f);
    mininave.setPosition(550, 15);

}

HUD::~HUD() {}


void HUD::updatePuntuacion(int tipoEnemigo) {

    if(tipoEnemigo == 1) {
        puntuacion += 200;
        scNUM.setString(std::to_string(puntuacion));
    }
}


void HUD::render() {
    Window::getInstancia()->renderWindow.draw(caja);
    Window::getInstancia()->renderWindow.draw(sc);
    Window::getInstancia()->renderWindow.draw(arm);
    Window::getInstancia()->renderWindow.draw(mininave);
    Window::getInstancia()->renderWindow.draw(scNUM);
    Window::getInstancia()->renderWindow.draw(armNUM);
    Window::getInstancia()->renderWindow.draw(vidasNUM);
}


void HUD::crearText(sf::Text &texto, std::string str, float posX, float posY){
    texto.setFont(*fuente);
    texto.setCharacterSize(25);
    texto.setColor(sf::Color::White);
    texto.setString(str);
    texto.setOrigin(texto.getGlobalBounds().width/2, texto.getGlobalBounds().height/2);
    texto.setPosition(posX, posY);
}



