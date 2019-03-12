#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager() {}

map<string, sf::Texture*> TextureManager::textures;
std::vector<string> TextureManager::order;


// Asignar un nombre (para acceder) y un path (para cargar) a la textura
sf::Texture *TextureManager::loadTexture(string name, string path) {
    sf::Texture *texture = new sf::Texture();

    if(texture->loadFromFile(path)) {
        textures[name] = texture;

        order.push_back(name);
        return textures[name];

    } else {
        delete texture;
        return NULL;
    }
}


int TextureManager::getLength(){
    return textures.size();
}

// Get textura por nombre
sf::Texture *TextureManager::getTexture(string name) {
    if(textures.find(name) != textures.end()) {
        return textures[name];
    } else {
        return NULL;
    }
}


// Get textura por index
sf::Texture *TextureManager::getTexture(int index) {
    return getTexture(order.at(index));
}


// Eliminar todas las texturas
TextureManager::~TextureManager() {

    sf::Texture *texture;
    map<string, sf::Texture*>::iterator iter = textures.begin();
    while(iter != textures.end()) {
        texture = iter->second;
        delete texture;
        iter++;
    }
}
