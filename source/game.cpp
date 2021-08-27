#include "game.h"


Game::Game(){
    gameRenderWindow = new sf::RenderWindow(sf::VideoMode(1200,600), "Pontes de Konigsberg", sf::Style::Default);

    gameGraphicsManager = new GraphicsManager(gameRenderWindow);
    gameEventsManager = new EventsManager(gameRenderWindow);
    currentLevel = new Level(gameGraphicsManager, gameEventsManager);
}

Game::~Game(){

    delete gameEventsManager;
    delete gameGraphicsManager;
    delete gameRenderWindow;
    delete currentLevel;

}

void Game::run(){

    while(!gameEventsManager->isWindowClosed()){
        update();
        render();
    }

}

void Game::update(){
    gameEventsManager->pollAll();
    currentLevel->update();
}

void Game::render(){

    currentLevel->render();
    gameGraphicsManager->render();
}