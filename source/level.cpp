#include "level.h"

Level::Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager):background(*levelGraphicsManager->loadTexture(BACKGROUND_TEXTURE)){
    background.setPosition(0, 0);
    sf::Vector2f canvasSize = levelGraphicsManager->getCanvasSize();
    sf::FloatRect backgroundRect = background.getGlobalBounds();
    background.scale(canvasSize.x/backgroundRect.width, canvasSize.y/backgroundRect.height);
    //background.scale(2.0,2.0);
    // 268x188 (esse eh o tamanho)
    this->levelGraphicsManager = levelGraphicsManager;
    this->levelEventsManager = levelEventsManager;
}

Level::~Level(){

}

void Level::update(){
    
}   

void Level::render(){
    printf("rendering level\n");
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(background));
    printf("rendered level\n");
}