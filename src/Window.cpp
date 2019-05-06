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
}

Window::~Window() { destroy(); }

void Window::destroy() {
    renderWindow.close();
    terminada = true;
}

void Window::procesarInput() {

    bool arriba            = false;
    bool abajo             = false;
    bool izquierda         = false;
    bool derecha           = false;
    bool haDisparado       = false;
    bool mantenerDisparo   = false;


    sf::Event event;
    while (renderWindow.pollEvent(event))
        if (event.type == sf::Event::Closed)
            destroy();


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    arriba = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  abajo = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  izquierda = true;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) derecha = true;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        mantenerDisparo = true;

        if(relojDisparos.getElapsedTime().asSeconds() > 0.3) {
            haDisparado = true;
            relojDisparos.restart();
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G) && relojModoDios.getElapsedTime().asSeconds() > 0.3) {
        if(modoDios) {
            modoDios = false;
            std::cout << "Modo dios desactivado" << std::endl;
        } else {
            modoDios = true;
            std::cout << "Modo dios activado!" << std::endl;
        }

        relojModoDios.restart();
    }

    inputs[0] = arriba;
    inputs[1] = abajo;
    inputs[2] = izquierda;
    inputs[3] = derecha;
    inputs[4] = haDisparado;
    inputs[5] = mantenerDisparo;
}

void Window::draw(sf::Drawable &dibujo) { renderWindow.draw(dibujo); }

void Window::beginDraw() { renderWindow.clear(); }

void Window::endDraw() { renderWindow.display(); }

bool Window::haTerminado() { return terminada; }

sf::Vector2u Window::getTamanyo() { return renderWindow.getSize(); }

void Window::resetDisparos() { numDisparos = 0; }
