#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

#define GET_DRAWABLE_POINTER(x)  static_cast<sf::Drawable*>(&x)

class GraphicsManager{
    private:
        sf::RenderWindow* window;
        std::map<std::string, sf::Font*> loadedFonts;
        std::map<std::string, sf::Texture*> loadedTextures;
    public:
        GraphicsManager(sf::RenderWindow* pWindow = NULL);
        ~GraphicsManager();

        sf::Font* loadFont(std::string fontPath);
        sf::Texture* loadTexture(std::string TexturePath);
        void draw(sf::Drawable* drwbl);
        void render();
};

#endif