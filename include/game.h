#ifndef GAME_H
#define GAME_H

#include "graphicsManager.h"
#include "eventsManager.h"

class Game{

    private:
        sf::RenderWindow* gameRenderWindow;
        GraphicsManager* gameGraphicsManager;
        EventsManager* gameEventsManager;

    public:
        Game();
        ~Game();

        void run();

        void update();
        void render();

};

#endif