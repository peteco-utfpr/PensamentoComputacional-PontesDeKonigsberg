#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "level.h"

class Game{

    private:
        sf::RenderWindow* gameRenderWindow;
        GraphicsManager* gameGraphicsManager;
        EventsManager* gameEventsManager;

        Level* currentLevel;

    public:
        Game();
        ~Game();

        void run();

        void update();
        void render();

};

#endif