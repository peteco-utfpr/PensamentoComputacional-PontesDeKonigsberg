#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "level.h"
#include <SFML/Audio.hpp>
#include "state.h"

typedef enum{
    introStateID,
    menuStateID,
    playStateID,
    numberOfStates
}GameState;

#include "introState.h"
#include "playState.h"
#include "menuState.h"

#define MUSIC_PATH "../assets/music.ogg"

class Game{

    private:
        sf::RenderWindow* gameRenderWindow;
        GraphicsManager* gameGraphicsManager;
        EventsManager* gameEventsManager;
        StateMachine* gameStateMachine;
        IntroState* gameIntroState;
        PlayState* gamePlayState;
        MenuState* gameMenuState;

    public:
        Game();
        ~Game();

        void run();

        void update();
        void render();

};

#endif