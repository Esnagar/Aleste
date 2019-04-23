#include "Window.h"
#include "TextureManager.h"

Window* Window::window = nullptr;

Window* Window::getInstancia() {

    if(window == nullptr)
        window = new Window();

    return window;
}

Window::Window() {
    renderWindow.create(sf::VideoMode(820, 640), "Aleste");
    renderWindow.setFramerateLimit(60);

    texFondo = *TextureManager::getInstancia()->getTexture("fondo");
    fondo.setTexture(texFondo);

    first.x = 0.0f;
    first.y = 0.0f;
}

Window::~Window() { destroy(); }

void Window::destroy() { renderWindow.close(); }


void Window::procesarInput() {

    bool arriba            = false;
    bool abajo             = false;
    bool izquierda         = false;
    bool derecha           = false;
    bool haDisparado       = false;
    bool mantenerDisparo   = false;


    sf::Event event;
    while (renderWindow.pollEvent(event)){}
        /*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && relojDisparos.getElapsedTime().asSeconds() > 0.1) {
            haDisparado = true;
            relojDisparos.restart();
        }*/


    //if (Window::getInstancia()->relojInterp.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME) {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    arriba = true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  abajo = true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  izquierda = true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) derecha = true;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            mantenerDisparo = true;

        std::cout << haDisparado << std::endl;

            if(relojDisparos.getElapsedTime().asSeconds() > 0.3) {
                haDisparado = true;
                relojDisparos.restart();
            }
        }

        inputs[0] = arriba;
        inputs[1] = abajo;
        inputs[2] = izquierda;
        inputs[3] = derecha;
        inputs[4] = haDisparado;
        inputs[5] = mantenerDisparo;
    //}
}

void Window::draw(sf::Drawable &dibujo) { renderWindow.draw(dibujo); }

void Window::beginDraw() { renderWindow.clear(); }

void Window::endDraw() { renderWindow.display(); }

bool Window::haTerminado() { return terminada; }

sf::Vector2u Window::getTamanyo() { return renderWindow.getSize(); }

void Window::resetDisparos() { numDisparos = 0; }

void Window::setFirst(float i, float j) {
    first.x += i;
    first.y += j;
}

void Window::updateFondo() {

    ///Tiempo hasta llegar al primer boss =~ 45 seg
    ///Tiempo desde el primer boss hasta el segundo =~ 1 min 25 seg

    ///Tiempo desde que empieza hasta que acaba este fondo =~ 45 seg
    posY -= 4;
    if(posY <= 0) {
        posY = 3280 - tamanyo;
        posX += tamanyo;
    }

    fondo.setTextureRect(sf::IntRect(posX, posY, tamanyo, tamanyo));
}
