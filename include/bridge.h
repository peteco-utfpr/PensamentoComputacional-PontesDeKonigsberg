#ifndef BRIDGE_H
#define BRIDGE_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "clickable.h"

class Bridge : public sf::Sprite, public Clickable{

    private:
        sf::Texture *texture;

    public:
        Bridge(sf::Texture* texture = NULL, sf::Vector2f position = {0.0f, 0.0f}, sf::Vector2f scale = {1.0f, 1.0f}); //Construtor básico da classe;
        virtual ~Bridge();
        void setBright(bool bright);
};

#endif /* BRIDGE_H */