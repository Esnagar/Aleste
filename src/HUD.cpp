#include "HUD.h"
#include "Window.h"

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
    bandaNegra.setOutlineColor(sf::Color::Blue);
    bandaNegra.setOutlineThickness(2.5);
    bandaNegra.setSize(sf::Vector2f(Window::getInstancia()->getTamanyo().x, 35));
    bandaNegra.setPosition(0, marcoVerde.getOutlineThickness());


    fuente->loadFromFile("resources/arcade.TTF");

    crearText(sc, "SC", 65, 33);
    crearText(arm, "ARM  -", 435, 33);

    //NÚMEROS
    crearText(scNUM, std::to_string(puntuacion), 240, 33);
    crearText(armNUM, std::to_string(tipoArma), 463, 33);
    crearText(vidasNUM, std::to_string(numVidas), 740, 33);

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

    if(tipoEnemigo == 1) {
        puntuacion += 200;
        scNUM.setString(std::to_string(puntuacion));
    }
}

void HUD::updateVidas(int vidas) {

    numVidas += vidas;
    vidasNUM.setString(std::to_string(numVidas));

    if(numVidas <= 0)
        std::cout << "Has perdido!" << std::endl; //aquí reiniciar el juego

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
}


void HUD::crearText(sf::Text &texto, std::string str, float posX, float posY){
    texto.setFont(*fuente);
    texto.setCharacterSize(25);
    texto.setColor(sf::Color::White);
    texto.setString(str);
    texto.setOrigin(texto.getGlobalBounds().width/2, texto.getGlobalBounds().height/2);
    texto.setPosition(posX, posY);
}



