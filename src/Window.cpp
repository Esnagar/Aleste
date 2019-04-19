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

    //Esto lo borrare supongo
    std::string url("resources/fondoPrueba.png");
    TextureManager::getInstancia()->loadTexture("fondo", url);
    texFondo = *TextureManager::getInstancia()->getTexture("fondo");

    fondo.setTexture(texFondo);
    //fondo.setOrigin(fondo.getGlobalBounds().width/2,fondo.getGlobalBounds().height/2);
    //fondo.setScale(1.2, 1.2);
    //fondo.setPosition(renderWindow.getSize().x/2, renderWindow.getSize().y/2);

    first.x = 0.0f;
    first.y = 0.0f;
}

Window::~Window() { destroy(); }

void Window::destroy() { renderWindow.close(); }


void Window::procesarInput() {

    bool arriba      = false;
    bool abajo       = false;
    bool izquierda   = false;
    bool derecha     = false;
    bool haDisparado = false;


    sf::Event event;
    while (renderWindow.pollEvent(event))
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)   haDisparado = true;



    if (Window::getInstancia()->relojInterp.getElapsedTime().asMilliseconds() > UPDATE_TICK_TIME) {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    arriba = true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  abajo = true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  izquierda = true;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) derecha = true;

        inputs[0] = arriba;
        inputs[1] = abajo;
        inputs[2] = izquierda;
        inputs[3] = derecha;
        inputs[4] = haDisparado;
    }
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

    ///Tiempo desde que empieza hasta que acaba este fondo =~ 50 seg
    posY -= 2;
    if(posY <= 0) {
        posY = 2460 - tamanyo;
        posX += tamanyo;
    }

    fondo.setTextureRect(sf::IntRect(posX, posY, tamanyo, tamanyo));
}
