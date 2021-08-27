#include "level.h"

Level::Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager):background(*levelGraphicsManager->loadTexture(BACKGROUND_TEXTURE)), 
bridge1(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {1220.0, 470.0},{6.0, 6.0}),
bridge2(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {1260.0, 900.0},{6.0,6.0}){
    
    this->levelGraphicsManager = levelGraphicsManager;
    this->levelEventsManager = levelEventsManager;
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(bridge1));
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(bridge2));

    //setting up background
    background.setPosition(0, 0);
    sf::Vector2f canvasSize = levelGraphicsManager->getCanvasSize();
    sf::FloatRect backgroundRect = background.getGlobalBounds();
    background.scale(canvasSize.x/backgroundRect.width, canvasSize.y/backgroundRect.height);

    

}

Level::~Level(){

}

void Level::update(){
    if(bridge2.isHovering())
        bridge2.setBright(true);
    else
        bridge2.setBright(false);

    if(bridge1.isHovering())
        bridge1.setBright(true);
    else
        bridge1.setBright(false);
}   

void Level::render(){
    //printf("rendering level\n");
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(background));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge1));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge2));
    //printf("rendered level\n");
}