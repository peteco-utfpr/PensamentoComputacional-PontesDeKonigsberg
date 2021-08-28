#ifndef LEVEL_H
#define LEVEL_H

#include "graphicsManager.h"
#include "eventsManager.h"
#include "bridge.h"


#include "levelData.h"


class Level{

    private:

        GraphicsManager* levelGraphicsManager;
        EventsManager* levelEventsManager;

        sf::Sprite background;
        sf::Sprite euler;

        Bridge* levelBridges;
        const int totalLoadedBridges;

    public:
        Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager);
        ~Level();

        void update();   
        void render();


};

#endif