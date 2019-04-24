#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include <iostream>

#define UPDATE_TICK_TIME (1000/15)

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

        //Variables para el rectángulo de recorte de la textura
        //Se usarán para la animación del fondo moviéndose

        sf::Clock relojUpdate;
        sf::Clock relojInterp;

        sf::Clock relojDisparos;
        sf::Clock relojModoDios;

        sf::Vector2f first;
        sf::Vector2f last;

        float percent;

        void setFirst(float i, float j);

        bool modoDios = false;

    protected:

    private:
        static Window* window;

        bool terminada;
        void destroy();


        Window();
        ~Window();
};

#endif // WINDOW_H
