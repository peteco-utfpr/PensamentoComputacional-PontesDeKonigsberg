#include "level.h"

Level::Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager):background(*levelGraphicsManager->loadTexture(BACKGROUND_TEXTURE)), 
bridge1(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {0.0, 0.0}),
bridge2(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {40.0, 40.0}){
    
    this->levelGraphicsManager = levelGraphicsManager;
    this->levelEventsManager = levelEventsManager;

    //setting up background
    background.setPosition(0, 0);
    sf::Vector2f canvasSize = levelGraphicsManager->getCanvasSize();
    sf::FloatRect backgroundRect = background.getGlobalBounds();
    background.scale(canvasSize.x/backgroundRect.width, canvasSize.y/backgroundRect.height);

    

}

Level::~Level(){

}

void Level::update(){
    
}   

void Level::render(){
    printf("rendering level\n");
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(background));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge1));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge2));
    printf("rendered level\n");
}