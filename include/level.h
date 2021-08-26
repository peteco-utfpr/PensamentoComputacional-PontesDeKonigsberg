#ifndef LEVEL_H
#define LEVEL_H

#include "graphicsManager.h"
#include "eventsManager.h"
#include "bridge.h"

#define BACKGROUND_TEXTURE "./assets/fundo.png" //não deveria ser ./assets/fundo.png ?

class Level{

    private:

        GraphicsManager* levelGraphicsManager;
        EventsManager* levelEventsManager;

        sf::Sprite background;

        Bridge ponte1;

    public:
        Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager);
        ~Level();

        void update();   
        void render();


};

#endif