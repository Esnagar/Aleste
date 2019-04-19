#include "TextureManager.h"
#include <iostream>


TextureManager* TextureManager::claseTextura = nullptr;

TextureManager* TextureManager::getInstancia() {
    if(claseTextura == nullptr)
        claseTextura = new TextureManager();

    return claseTextura;
}


TextureManager::TextureManager() {}


// Asignar un nombre (para acceder) y un path (para cargar) a la textura
void TextureManager::loadTexture(std::string nombre, std::string &path) {
    sf::Texture *texture = new sf::Texture();

    if(!texture->loadFromFile(path))
        texture = nullptr;

    textures[nombre] = texture;
}

// Get textura por nombre
sf::Texture *TextureManager::getTexture(std::string nombre) {
    if(textures.find(nombre) != textures.end()) {
        return textures[nombre];
    } else {
        return NULL;
    }
}


// Eliminar todas las texturas
TextureManager::~TextureManager() {

    sf::Texture *texture;
    std::map<std::string, sf::Texture*>::iterator iter = textures.begin();
    while(iter != textures.end()) {
        texture = iter->second;
        delete texture;
        iter++;
    }
}
