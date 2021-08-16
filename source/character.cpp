#include "character.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


Character::Character(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale):sf::Sprite(), Clickable(){
    if(!texture)
        printf("WARNING: no texture set!\n");
    else
        setTexture(*texture);

    setScale(scale);
    setPosition(position);
    setClickBox(getGlobalBounds());
    
}

Character::~Character(){

}

void Character::setBright(bool bright){
    if(bright)
        setColor(sf::Color::Blue);
    else if(getColor() == sf::Color::Blue)
        setColor(sf::Color::White);
}



//---------------------------------------------------------------------------------------------------------------------------------------------