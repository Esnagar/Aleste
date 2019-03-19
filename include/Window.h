#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>

class Window
{
    public:
        Window();
        ~Window();

        void beginDraw();
        void endDraw();

        void update();
        void draw(sf::Drawable &p_dibujo);

        bool haTerminado();
        sf::Vector2u getTamanyo();


    protected:

    private:
        sf::RenderWindow ventana;
        bool terminada;
        void destroy();
};

#endif // WINDOW_H
