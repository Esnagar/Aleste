#include "Window.h"

//Por defecto
Window::Window() { ventana.create(sf::VideoMode(640, 480), "Aleste"); }

Window::~Window() { destroy(); }

void Window::destroy() { ventana.close(); }


void Window::update() {

    sf::Event event;
    while(ventana.pollEvent(event)) {
        if(event.type == sf::Event::Closed){
            terminada = true;
        }
    }
}

void Window::draw(sf::Drawable &dibujo) { ventana.draw(dibujo); }


void Window::beginDraw() { ventana.clear(); }
void Window::endDraw() { ventana.display(); }


bool Window::haTerminado() { return terminada; }

sf::Vector2u Window::getTamanyo() { return ventana.getSize(); }
