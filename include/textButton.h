#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include <iostream>
#include <string>

#include "clickable.h"


class TextButton: public Clickable, public sf::Text{

    private:
        sf::Font* font;

    public:
        TextButton(sf::Font* font = NULL, std::string text = "", int size = 10, sf::Color color = sf::Color::White, sf::Vector2f position = {0.0f, 0.0f});
        void draw(sf::RenderWindow* window);
        void setLoadedFont(sf::Font* font);
};

#endif /* TextButton_H */
