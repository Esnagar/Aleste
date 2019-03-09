#include <iostream>
#include <SFML/Graphics.hpp>

#define SPRITE_SPEED 1

int main()
{
    //Creamos una ventana
    sf::RenderWindow window(sf::VideoMode(640, 480), "P0. Fundamentos de los Videojuegos. DCCIA");

    //Cargo la imagen donde reside la textura del sprite
    sf::Texture tex;
    if (!tex.loadFromFile("resources/nave.png"))
    {
        std::cerr << "Error cargando la imagen nave.png";
        exit(0);
    }


    sf::Texture laser;
    if (!laser.loadFromFile("resources/disparos.png"))
    {
        std::cerr << "Error cargando la imagen disparos.png";
        exit(0);
    }



    //Y creo el spritesheet a partir de la imagen anterior
    sf::Sprite sprite(tex);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    sprite.setScale(0.3f, 0.3f);
    sprite.setPosition(320, 240);



    sf::Sprite disparo(laser);
    disparo.setOrigin(disparo.getGlobalBounds().width/2,disparo.getGlobalBounds().height/2);
    disparo.setTextureRect(sf::IntRect(190, 90, 50, 20));
    disparo.setRotation(90);


// Sprite coordinates
    int x=window.getSize().x/2.;
    int y=window.getSize().y/2.;

    tex.setSmooth(true);
    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;
    bool disparar=false;
    bool disparado=false;

    sf::Clock timer;
    while (window.isOpen())
    {
        window.setFramerateLimit(1000); //esto aun no me queda claro para que es

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
                case sf::Keyboard::Space:   disparar=true; break;

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

        if(disparar){
            window.draw(disparo);
            disparo.setPosition(sprite.getPosition().x, sprite.getPosition().y - 20);
            disparado = true;
        }

        if(disparado){
            std::cout << "buenos dias" << std::endl;
            disparo.setPosition(disparo.getPosition().x,disparo.getPosition().y + 5);
        }

        window.display();
    }

    return 0;
}
