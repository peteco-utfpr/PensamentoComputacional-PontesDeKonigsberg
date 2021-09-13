#ifndef LEVEL_H
#define LEVEL_H


#include "graphicsManager.h"
#include "eventsManager.h"
#include "bridge.h"
#include "graph.h"
#include "textButton.h"
#include <SFML/Audio.hpp>

#include "levelData.h"


class Level{

    private:

        GraphicsManager* levelGraphicsManager;
        EventsManager* levelEventsManager;

        sf::Sprite background;
        sf::Sprite euler;
        sf::Sprite whiteFlag;
        sf::Text winMessage;

        Bridge* levelBridges;
        int totalLoadedBridges;
        Graph* levelGraph;
        int eulerPosition;
        int tries;

        sf::Sound crossingSound;
        sf::SoundBuffer stepSoundBuffer;

        std::vector<Bridge*> crossedBridges;

        bool stuck;
        bool won;

        TextButton retryButton;
        TextButton giveUpButton;
        TextButton exitButton;

    public:
        Level(GraphicsManager* levelGraphicsManager = NULL, EventsManager* levelEventsManager = NULL, bool possible = false);
        ~Level();

        bool update();   
        void render();

        void moveEuler(int destination);
        void reset();


};

#endif