#include <iostream>
#include <SFML/Graphics.hpp>
#include "Disparo.h"

#define SPRITE_SPEED 5

int main()
{
    //Creamos una ventana
    sf::RenderWindow window(sf::VideoMode(640, 480), "Aleste");

    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex;
    if (!tex.loadFromFile("resources/nave.png"))
    {
        std::cerr << "Error cargando la imagen nave.png";
        exit(0);
    }



    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite sprite(tex);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    sprite.setScale(0.3f, 0.3f);
    sprite.setPosition(320, 240);



// Sprite coordinates
    int x=window.getSize().x/2.;
    int y=window.getSize().y/2.;

    tex.setSmooth(true);
    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;
    bool haDisparado=false;
    bool disparado=false;

    sf::Clock timer;
    std::vector <Disparo> vectorDisparos;

    while (window.isOpen())
    {
        window.setFramerateLimit(60); //esto aun no me queda claro para que es

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close the window if a key is pressed or if requested
            if (event.type == sf::Event::Closed) window.close();

            // If a key is pressed
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                // If escape is pressed, close the application
                case  sf::Keyboard::Escape : window.close(); break;

                // Process the up, down, left and right keys
                case sf::Keyboard::Up :     upFlag=true; break;
                case sf::Keyboard::Down:    downFlag=true; break;
                case sf::Keyboard::Left:    leftFlag=true; break;
                case sf::Keyboard::Right:   rightFlag=true; break;
                case sf::Keyboard::Space:   haDisparado=true; break;

                default : break;
                }
            }

            // If a key is released
            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                // Process the up, down, left and right keys
                case sf::Keyboard::Up :     upFlag=false; break;
                case sf::Keyboard::Down:    downFlag=false; break;
                case sf::Keyboard::Left:    leftFlag=false; break;
                case sf::Keyboard::Right:   rightFlag=false; break;
                default : break;
                }
            }
        }

        // Update coordinates
        if (leftFlag) x-=SPRITE_SPEED;
        if (rightFlag) x+=SPRITE_SPEED;
        if (upFlag) y-=SPRITE_SPEED;
        if (downFlag) y+=SPRITE_SPEED;

        sprite.setPosition(x,y);
        //sprite.setRotation( timer.getElapsedTime().asSeconds() / M_PI * 90.f );

        window.clear();
        window.draw(sprite);

        if(haDisparado){
            Disparo disparo("resources/disparos.png");
            disparo.setPosicion(sprite.getPosition().x, sprite.getPosition().y);
            disparo.draw(window);
            vectorDisparos.push_back(disparo);
            haDisparado = false;
        }

        for (int i=0; i<vectorDisparos.size(); i++) {
            vectorDisparos[i].mover(0, -3);
            vectorDisparos[i].draw(window);
        }


        window.display();
    }

    return 0;
}
