#include "bridge.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

Bridge::Bridge(sf::Texture* texture, sf::Vector2f position, sf::Vector2f scale, float rotation, int id):sf::Sprite(), Clickable(){
    
    if(!texture)
        printf("WARNING: no texture set!\n");
    else
        setTexture(*texture);

    setRotation(rotation);
    setScale(scale);
    setPosition(position);
    this->id = id;
    setClickBox(getGlobalBounds());
    crossed = false;
    
}

Bridge::~Bridge(){

}

void Bridge::setId(int Id){
    this->id = Id;
}

int Bridge::getId(){
    return id;
}

void Bridge::setBright(bool bright){
    if(bright)
        setColor(sf::Color::Yellow);
    else if(getColor() == sf::Color::Yellow)
        setColor(sf::Color::White);
}

void Bridge::setCrossed(bool crossed){
    this->crossed = crossed;
}

bool Bridge::isCrossed(){
    return crossed;
}

//---------------------------------------------------------------------------------------------------------------------------------------------