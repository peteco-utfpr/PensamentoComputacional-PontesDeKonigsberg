#include "level.h"

Level::Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager):
background(*levelGraphicsManager->loadTexture(BACKGROUND_TEXTURE)),
euler(*levelGraphicsManager->loadTexture(EULER_TEXTURE)), 
bridge1(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {1220.0, 470.0},{7.0, 7.0}, 0),
bridge2(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {1250.0, 900.0},{7.0,7.0}, -10),
bridge3(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {1000.0, 660.0},{7.0,7.0}, 90),
bridge4(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {710.0, 610.0},{7.0,7.0}, 98),
bridge5(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {820.0, 260.0},{7.0,7.0}, 285),
bridge6(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {1070.0, 300.0},{7.0,7.0}, 285),
bridge7(levelGraphicsManager->loadTexture(BRIDGE_TEXTURE), {1550.0, 130.0},{7.0,7.0}, 85)
{
    printf("building level\n");
    this->levelGraphicsManager = levelGraphicsManager;
    this->levelEventsManager = levelEventsManager;
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(bridge1));
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(bridge2));
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(bridge3));
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(bridge4));
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(bridge5));
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(bridge6));
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(bridge7));
    printf("Clickables added\n");

    //setting up background
    background.setPosition(0, 0);
    sf::Vector2f canvasSize = levelGraphicsManager->getCanvasSize();
    sf::FloatRect backgroundRect = background.getGlobalBounds();
    background.scale(canvasSize.x/backgroundRect.width, canvasSize.y/backgroundRect.height);
    printf("Background loaded\n");

    //Setting the position of euler
    euler.setPosition({1600,540});
    euler.setScale({0.2, 0.2});

}

Level::~Level(){
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(bridge1));
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(bridge2));
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(bridge3));
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(bridge4));
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(bridge5));
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(bridge6));
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(bridge7));
}

void Level::update(){
    if(bridge1.isHovering())
        bridge1.setBright(true);
    else
        bridge1.setBright(false);

    if(bridge2.isHovering())
        bridge2.setBright(true);
    else
        bridge2.setBright(false);

    if(bridge3.isHovering())
        bridge3.setBright(true);
    else
        bridge3.setBright(false);
    
    if(bridge3.isHovering())
        bridge3.setBright(true);
    else
        bridge3.setBright(false);

    if(bridge4.isHovering())
        bridge4.setBright(true);
    else
        bridge4.setBright(false);
    
    if(bridge5.isHovering())
        bridge5.setBright(true);
    else
        bridge5.setBright(false);

    if(bridge6.isHovering())
        bridge6.setBright(true);
    else
        bridge6.setBright(false);

    if(bridge7.isHovering())
        bridge7.setBright(true);
    else
        bridge7.setBright(false);
}   

void Level::render(){
    //printf("rendering level\n");
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(background));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(euler));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge1));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge2));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge3));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge4));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge5));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge6));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(bridge7));
    //printf("rendered level\n");
}