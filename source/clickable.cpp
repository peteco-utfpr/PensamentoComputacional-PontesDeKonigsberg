#include "clickable.h"

Clickable::Clickable(sf::FloatRect clickBox){
    this->clickBox = clickBox;
    hovering = false;
    clicked = false;
}

Clickable::~Clickable(){

}

bool Clickable::isHovering(){
    return hovering;
}

bool Clickable::wasClicked(){
    if(clicked){
        clicked = !clicked;
        return true;
    }
    else
        return false;
}

void Clickable::setClickBox(sf::FloatRect clickBox){
    this->clickBox = clickBox;
}