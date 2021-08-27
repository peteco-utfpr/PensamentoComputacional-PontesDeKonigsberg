#include "Bridge.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

Bridge::Bridge(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale):sf::Sprite(), Clickable(){
    if(!texture)
        printf("WARNING: no texture set!\n");
    else
        setTexture(*texture);

    setScale(scale);
    setPosition(position);
    setClickBox(getGlobalBounds());
    
}

Bridge::~Bridge(){

}

void Bridge::setBright(bool bright){
    if(bright)
        setColor(sf::Color::Blue);
    else if(getColor() == sf::Color::Blue)
        setColor(sf::Color::White);
}

//---------------------------------------------------------------------------------------------------------------------------------------------