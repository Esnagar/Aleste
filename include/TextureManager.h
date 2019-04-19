#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {

    private:
        static TextureManager* claseTextura;
        std::map<std::string, sf::Texture*> textures;

        TextureManager();
        virtual ~TextureManager();


    public:
        static TextureManager* getInstancia();
        void loadTexture(std::string nombre, std::string &path);
        sf::Texture* getTexture(std::string nombre);
};


#endif // TEXTUREMANAGER_H
