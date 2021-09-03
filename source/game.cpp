#include "game.h"
#include "state.h"

Game::Game(){
    gameRenderWindow = new sf::RenderWindow(sf::VideoMode(1200,600), "Pontes de Konigsberg", sf::Style::Default);

    gameGraphicsManager = new GraphicsManager(gameRenderWindow);
    gameEventsManager = new EventsManager(gameRenderWindow);

    gameStateMachine = new StateMachine();
    gameIntroState = new IntroState(gameStateMachine, gameGraphicsManager, gameEventsManager);
    gamePlayState = new PlayState(gameStateMachine, gameGraphicsManager, gameEventsManager);
    gameMenuState = new MenuState(gameStateMachine, gameGraphicsManager, gameEventsManager);
    gameStateMachine->addState(GET_STATE_POINTER(*gameIntroState));
    gameStateMachine->addState(GET_STATE_POINTER(*gameMenuState));
    gameStateMachine->addState(GET_STATE_POINTER(*gamePlayState));
    gameStateMachine->changeState(0, nullptr);
    
}

Game::~Game(){
    delete gameStateMachine;
    delete gameEventsManager;
    delete gameGraphicsManager;
    delete gameRenderWindow;

}

void Game::run(){

    sf::Music music;
    if(!music.openFromFile(MUSIC_PATH)){
        printf("ERROR: could not load music\n");
    }

    music.play();

    while(!gameEventsManager->isWindowClosed()){
        update();
        render();
    }

}

void Game::update(){
    //verificar qual estado está???
    gameEventsManager->pollAll();
    gameStateMachine->update(); 
}

void Game::render(){
    gameStateMachine->render();
    gameGraphicsManager->render();
}