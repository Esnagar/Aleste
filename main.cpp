#include <iostream>
#include <SFML/Graphics.hpp>
#include "Disparo.h"
#include "Enemigo.h"
#include "Jugador.h"

#define kVELOCIDAD 5

int main() {

    sf::RenderWindow window(sf::VideoMode(640, 480), "Aleste");
    sf::Clock timer;


    // Declaración de los personajes/objetos
    Jugador jugador("resources/nave.png");
    Enemigo enemigo("resources/sprites.png");
    std::vector <Disparo> vectorDisparos;


    // Input del jugador
    bool arriba      = false;
    bool abajo       = false;
    bool izquierda   = false;
    bool derecha     = false;
    bool haDisparado = false;
    bool aLaDerecha  = true;


    while (window.isOpen()) {

        window.setFramerateLimit(60);

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::KeyPressed) {

                switch (event.key.code) {
                    case sf::Keyboard::Up :     arriba      = true; break;
                    case sf::Keyboard::Down:    abajo       = true; break;
                    case sf::Keyboard::Left:    izquierda   = true; break;
                    case sf::Keyboard::Right:   derecha     = true; break;
                    case sf::Keyboard::Space:   haDisparado = true; break;

                    case sf::Keyboard::Escape: window.close(); break;

                    default: break;
                }
            }


            // Si se suelta una tecla
            if (event.type == sf::Event::KeyReleased) {

                switch (event.key.code) {
                    case sf::Keyboard::Up :     arriba      = false; break;
                    case sf::Keyboard::Down:    abajo       = false; break;
                    case sf::Keyboard::Left:    izquierda   = false; break;
                    case sf::Keyboard::Right:   derecha     = false; break;

                    default : break;
                }
            }
        }

        // Actualizar coordenadas
        if (izquierda)  jugador.mover(-kVELOCIDAD, 0);
        if (derecha)    jugador.mover(kVELOCIDAD, 0);
        if (arriba)     jugador.mover(0, -kVELOCIDAD);
        if (abajo)      jugador.mover(0, kVELOCIDAD);


        ///////////////////////////////////////////////////////JUGADOR///////////////////////////////////////////////////////////

        window.clear();
        jugador.draw(window);

        ///////////////////////////////////////////////////////ENEMIGOS//////////////////////////////////////////////////////////

        if(aLaDerecha) {
            enemigo.mover(3,0);

            if(enemigo.getPosX() > 630) aLaDerecha = false;

        } else {
            enemigo.mover(-3,0);

            if(enemigo.getPosX() < 50)  aLaDerecha = true;
        }


        for (int i = 0; i < vectorDisparos.size(); i++) {
            enemigo.checkColision(vectorDisparos[i]);
        }

        enemigo.draw(window);

        //////////////////////////////////////////////////////DISPAROS///////////////////////////////////////////////////////////

        if(haDisparado) {
            Disparo disparo("resources/disparos.png", jugador.getPosX(), jugador.getPosY() - 70);
            disparo.draw(window);
            vectorDisparos.push_back(disparo);
            haDisparado = false;
        }

        for (int i = 0; i < vectorDisparos.size(); i++) {
            vectorDisparos[i].mover(0, -3);
            vectorDisparos[i].draw(window);
        }


        window.display();
    }

    return 0;
}
