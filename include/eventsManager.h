#ifndef EVENTS_MANAGER_H
#define EVENTS_MANAGER_H

#include "clickable.h"
#include <vector>

#define GET_CLICKABLE_POINTER(x)  static_cast<Clickable*>(&x)

class EventsManager{

    private:
        sf::RenderWindow* window;
        float canvasWidth, canvasHeight;
        sf::Mouse mouse;
        sf::Event currentEvent;
        std::vector<Clickable*> clickables;
        bool windowClosed;
    
    public:
        EventsManager(sf::RenderWindow* pWindow = NULL);
        ~EventsManager();

        void addClickable(Clickable* clkbl);
        void removeClickable(Clickable* clkbl);

        void pollAll();
        void closeWindow();
        bool isWindowClosed();


};

#endif