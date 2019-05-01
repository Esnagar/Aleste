#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Window
{
    public:

        static Window* getInstancia();

        int numDisparos;
        void resetDisparos();
        sf::RenderWindow renderWindow;
        bool inputs[5];

        void beginDraw();
        void endDraw();

        void procesarInput();
        void draw(sf::Drawable &p_dibujo);

        bool haTerminado();
        sf::Vector2u getTamanyo();

        sf::Clock relojDisparos;
        sf::Clock relojModoDios;

        bool modoDios = false;

        float numUpdates = 15.f;
        float UPDATE_TICK_TIME = 1000.f/numUpdates;

    protected:

    private:
        static Window* window;

        bool terminada;
        void destroy();


        Window();
        ~Window();
};

#endif // WINDOW_H
