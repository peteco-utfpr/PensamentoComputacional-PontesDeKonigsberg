#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


#include "TextButton.h"

TextButton::TextButton(sf::Font* font, std::string text, int size, sf::Color color, sf::Vector2f position): sf::Text(text, *font, size), Clickable(){
    if(!font)
        printf("WARNING: no font set!\n");
    
    setPosition(position);
    setClickBox(getGlobalBounds());
    setFillColor(color);
    
    //setScale(sf::Vector2f(0.5, 0.5));
}


void TextButton::setLoadedFont(sf::Font* font){

    if(font){
        this->font = font;
        this->setFont(*font);
    }

}

