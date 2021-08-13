#ifndef CHARACTER_H
#define CHARACTER_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <bits/stdc++.h>

#include "clickable.h"

class Character : public sf::Sprite, public Clickable{

    private:
        sf::Texture *texture;

    public:
        Character(sf::Texture* texture = NULL, sf::Vector2f position = {0.0f, 0.0f}, sf::Vector2f scale = {1.0f, 1.0f}); //Construtor básico da classe;
        virtual ~Character();
        void setBright(bool bright);
};

#endif /* CHARACTER_H */