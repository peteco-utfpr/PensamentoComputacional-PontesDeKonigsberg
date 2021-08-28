#ifndef LEVEL_H
#define LEVEL_H

#include "graphicsManager.h"
#include "eventsManager.h"
#include "bridge.h"


#define BACKGROUND_TEXTURE "./assets/fundo.png"
#define BRIDGE_TEXTURE "./assets/ponte.png"
#define EULER_TEXTURE "./assets/euler.png"
#define ISLAND_SOUTH_POSITION   {700, 850}
#define ISLAND_CENTER_POSITION  {800, 350}
#define ISLAND_NORTH_POSITION   {1250, 32}
#define ISLAND_EAST_POSITION    {1600, 540}

class Level{

    private:

        GraphicsManager* levelGraphicsManager;
        EventsManager* levelEventsManager;

        sf::Sprite background;
        sf::Sprite euler;

        Bridge bridge1;
        Bridge bridge2;
        Bridge bridge3;
        Bridge bridge4;
        Bridge bridge5;
        Bridge bridge6;
        Bridge bridge7;

    public:
        Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager);
        ~Level();

        void update();   
        void render();


};

#endif