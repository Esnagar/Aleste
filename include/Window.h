#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

class Window{
    private:
        void Setup(const std::string& p_titulo, const sf::Vector2u& p_tamanyo) {

            titulo = p_titulo;
            tamanyo = p_tamanyo;
            estaHecha = false;
            pantallaCompleta = false;
        }

        void Destroy() {
            window.close();
        }
        void Create();
        sf::RenderWindow window;
        sf::Vector2u tamanyo;
        std::string titulo;
        bool estaHecha;
        bool pantallaCompleta;

    public:

        Window(const std::string& titulo, const sf::Vector2u& tamanyo){
            Setup(titulo, tamanyo);
        }


        ~Window(){ Destroy(); }

        void BeginDraw(); // Clear the window.
        void EndDraw(); // Display the changes.
        void Update();
        bool IsDone();
        bool IsFullscreen();
        sf::Vector2u GetWindowSize();
        void ToggleFullscreen();
        void Draw(sf::Drawable& l_drawable);

};

#endif // WINDOW_H_INCLUDED
