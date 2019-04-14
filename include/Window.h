#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
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


        sf::Texture texFondo;
        sf::Sprite fondo;

        //Variables para el rectángulo de recorte de la textura
        //Se usarán para la animación del fondo moviéndose
        int tamanyo = 820;
        int posX = 0;
        int posY = 2460 - tamanyo;

        sf::Clock relojUpdate;
        sf::Clock relojInterp;
        sf::Vector2f first;
        sf::Vector2f last;

        float percent;
        void updateFondo();

        void setFirst(float i, float j);

    protected:

    private:
        static Window* window;

        bool terminada;
        void destroy();


        Window();
        ~Window();
};

#endif // WINDOW_H
