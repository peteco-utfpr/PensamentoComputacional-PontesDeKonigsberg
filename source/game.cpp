#include "game.h"

int main(){

    return 0;
}

Game::Game(){
    gameRenderWindow = new sf::RenderWindow(sf::VideoMode(1200,600), "Pontes de Konigsberg", sf::Style::Default);

    gameGraphicsManager = new GraphicsManager(gameRenderWindow);
    gameEventsManager = new EventsManager(gameRenderWindow);
}

Game::~Game(){

    delete gameEventsManager;
    delete gameGraphicsManager;
    delete gameRenderWindow;

}

void Game::run(){
    while(!gameEventsManager->isWindowClosed()){
        update();
        render();
    }
}

void Game::update(){

}

void Game::render(){


    gameGraphicsManager->render();
}