#ifndef BRIDGE_H
#define BRIDGE_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "clickable.h"

class Bridge : public sf::Sprite, public Clickable{

    private:
        int id;
        sf::Texture *texture;
        float rotation; //angle

    public:
        Bridge(sf::Texture* texture = NULL, sf::Vector2f position = {0.0f, 0.0f}, sf::Vector2f scale = {1.0f, 1.0f}, float rotation = 0.0f, int id = -1); //Construtor básico da classe;
        virtual ~Bridge();
        void setId(int id);
        int getId();
        void setBright(bool bright);
};

#endif /* BRIDGE_H */