#ifndef TEXTURA_H_INCLUDED
#define TEXTURA_H_INCLUDED


class Textura
{
    private:
        std::vector<sf::Texture> texturas;

    protected:



    public:

        Textura(std::string ruta) {

            sf::Texture text;
            text.loadFromFile(ruta);
            text.setSmooth(true);
            texturas.push_back(text);

        }

        sf::Texture* getTextura(unsigned int ID) {
                if (texturas.size() <= ID) {
                        return &texturas[0];
                }
                else {
                        return &texturas[ID];
                }
        }

};



#endif // TEXTURA_H_INCLUDED
