#include "Window.h"
#include "TextureManager.h"

Window* Window::window = nullptr;

Window* Window::getInstancia() {

    if(window == nullptr)
        window = new Window();

    return window;
}

//Por defecto
Window::Window() {
    renderWindow.create(sf::VideoMode(640, 480), "Aleste");
    renderWindow.setFramerateLimit(60);

    //Esto lo borrare supongo
    TextureManager::loadTexture("fondoCiudad", "resources/fondoCiudad.png");
    texFondo = TextureManager::getTexture("fondoCiudad")[0];

    fondo.setTexture(texFondo);
    fondo.setOrigin(fondo.getGlobalBounds().width/2,fondo.getGlobalBounds().height/2);
    fondo.setScale(0.65, 0.65);
    fondo.setPosition(320, 240);
}

Window::~Window() {
    destroy();
}

void Window::destroy() {
    renderWindow.close();
}


void Window::procesarInput() {

    bool arriba      = false;
    bool abajo       = false;
    bool izquierda   = false;
    bool derecha     = false;
    bool haDisparado = false;


    //Si no se pone el loop este la ventana se pone como gris
    sf::Event event;
    while (renderWindow.pollEvent(event)) {

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            haDisparado = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        arriba = true;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        abajo = true;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        izquierda = true;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        derecha = true;


    inputs[0] = arriba;
    inputs[1] = abajo;
    inputs[2] = izquierda;
    inputs[3] = derecha;
    inputs[4] = haDisparado;
    //inputs = {arriba, abajo, izquierda, derecha, haDisparado};
}

void Window::draw(sf::Drawable &dibujo) { renderWindow.draw(dibujo); }


void Window::beginDraw() { renderWindow.clear(); }
void Window::endDraw() { renderWindow.display(); }


bool Window::haTerminado() { return terminada; }

sf::Vector2u Window::getTamanyo() { return renderWindow.getSize(); }


void Window::resetDisparos() {
    numDisparos = 0;
}
