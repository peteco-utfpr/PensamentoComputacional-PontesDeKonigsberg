#ifndef CLICKABLE_H
#define CLICKABLE_H

#include <SFML/Graphics.hpp>

class Clickable{
    protected:
        sf::FloatRect clickBox;
        bool hovering;
        bool clicked;

    public:
        Clickable(sf::FloatRect clickBox = {0.0f, 0.0f, 0.0f, 0.0f});
        ~Clickable();

        bool isHovering();
        bool wasClicked();
        void setClickBox(sf::FloatRect clickBox);
        //void click();
        //void hover();
        //void clear();

        friend class EventsManager;

};

#endif