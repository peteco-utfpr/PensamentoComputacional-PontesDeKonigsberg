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
    printf("abrindo kk\n");
    while(!gameEventsManager->isWindowClosed()){
        update();
        render();
    }
    printf("fechando kk\n");
}

void Game::update(){
    gameEventsManager->pollAll();
    printf("update\n");
}

void Game::render(){

    printf("render\n");
    currentLevel->render();
    printf("level rendered\n");
    gameGraphicsManager->render();
    printf("game rendered\n");
}