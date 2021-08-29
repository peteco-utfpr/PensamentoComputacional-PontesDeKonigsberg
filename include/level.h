#ifndef LEVEL_H
#define LEVEL_H

#include "graphicsManager.h"
#include "eventsManager.h"
#include "bridge.h"
#include "graph.h"


#include "levelData.h"


class Level{

    private:

        GraphicsManager* levelGraphicsManager;
        EventsManager* levelEventsManager;

        sf::Sprite background;
        sf::Sprite euler;

        Bridge* levelBridges;
        const int totalLoadedBridges;
        Graph* levelGraph;
        int eulerPosition;

        std::vector<Bridge*> crossedBridges;

    public:
        Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager);
        ~Level();

        void update();   
        void render();

        void moveEuler(int destination);


};

#endif