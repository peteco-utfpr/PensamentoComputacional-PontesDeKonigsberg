#include "level.h"

Level::Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager):
background(*levelGraphicsManager->loadTexture(BACKGROUND_TEXTURE)),
euler(*levelGraphicsManager->loadTexture(EULER_TEXTURE)),
totalLoadedBridges(IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES),
retryButton(levelGraphicsManager->loadFont(BUTTON_FONT_PATH), "tentar novamente", 50, sf::Color::Yellow)
{
    printf("building level\n");

    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(retryButton));
    eulerPosition = Island::east;

    sf::Vector2f levelBridgesPositions[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = IMPOSSIBLE_LEVEL_BRIDGE_POSITION_VECTOR;
    sf::Vector2f levelBridgesScales[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES]= IMPOSSIBLE_LEVEL_BRIDGE_SCALE_VECTOR;
    float levelBridgesRotations[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES]= IMPOSSIBLE_LEVEL_BRIDGE_ROTATION_VECTOR;
    Island levelBridgesSources[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES]= IMPOSSIBLE_LEVEL_BRIDGE_SOURCE_VECTOR;
    Island levelBridgesDestinations[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES]= IMPOSSIBLE_LEVEL_BRIDGE_DEST_VECTOR;


    this->levelGraphicsManager = levelGraphicsManager;
    this->levelEventsManager = levelEventsManager;

    //setting up bridges---------------
    levelBridges = new Bridge[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES];

    
    for(int i = 0; i < totalLoadedBridges; i++){
        levelBridges[i].setTexture(*levelGraphicsManager->loadTexture(BRIDGE_TEXTURE));
        levelBridges[i].setPosition(levelBridgesPositions[i]);
        levelBridges[i].setScale(levelBridgesScales[i]);
        levelBridges[i].setRotation(levelBridgesRotations[i]);
        levelBridges[i].setId(i);
        levelBridges[i].setClickBox(levelBridges[i].getGlobalBounds());
        levelEventsManager->addClickable(GET_CLICKABLE_POINTER(levelBridges[i]));
    }
    
    //-------------

    //setting up background---------
    background.setPosition(0, 0);
    sf::Vector2f canvasSize = levelGraphicsManager->getCanvasSize();
    sf::FloatRect backgroundRect = background.getGlobalBounds();
    background.scale(canvasSize.x/backgroundRect.width, canvasSize.y/backgroundRect.height);
    //-------------

    //Setting up Euler------
    euler.setPosition({1600,540});
    euler.setScale({0.2, 0.2});
    //-------------

    levelGraph = new Graph(4);

    for(int i = 0; i < totalLoadedBridges; i++)
        levelGraph->addEdge(levelBridgesSources[i], levelBridgesDestinations[i], false, &levelBridges[i]);
    printf("built level\n");
}

Level::~Level(){
    for(int i = 0; i < totalLoadedBridges; i++)
        levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(levelBridges[i]));
    delete[] levelBridges;

    delete levelGraph;
}

void Level::update(){
    for(int i = 0; i < totalLoadedBridges; i++)
        if(levelBridges[i].isHovering())
            levelBridges[i].setBright(true);
        else
            levelBridges[i].setBright(false);

    //checking for movement
    for(int i = 0; i < totalLoadedBridges; i++)
        if(levelBridges[i].wasClicked() && !levelBridges[i].isCrossed()){
            levelGraph->iterateBySource(eulerPosition);
            Node* it = levelGraph->getNextNode();
            while(it){
                if(levelBridges[i].getId() == it->linkedBridge->getId()){
                    moveEuler(it->dstID);
                    levelBridges[i].setCrossed(true);
                    crossedBridges.push_back(it->linkedBridge);
                }

                it = levelGraph->getNextNode();
            }
        }

    for(auto i = crossedBridges.begin(); i != crossedBridges.end(); i++)
        (*i)->setColor(sf::Color::Red);

    //checking if player is stuck
    stuck = true;
    levelGraph->iterateBySource(eulerPosition);
    Node* it = levelGraph->getNextNode();
    while(it){
        if(!it->linkedBridge->isCrossed()){
            stuck = false;
            break;
        }
        it = levelGraph->getNextNode();
    }

    if(retryButton.isHovering()){
        retryButton.setFillColor(sf::Color::Blue);
        if(stuck && retryButton.wasClicked())
        reset();
    }
    else
        retryButton.setFillColor(sf::Color::Yellow);

    


}   

void Level::render(){
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(background));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(euler));
    for(int i = 0; i < totalLoadedBridges; i++)
        levelGraphicsManager->draw(GET_DRAWABLE_POINTER(levelBridges[i]));

    if(stuck)
        levelGraphicsManager->draw(GET_DRAWABLE_POINTER(retryButton));
}

void Level::moveEuler(int destination){
    switch (destination){
        case Island::north:
            eulerPosition = Island::north;
            euler.setPosition(ISLAND_NORTH_POSITION);
        break;

        case Island::east:
            eulerPosition = Island::east;
            euler.setPosition(ISLAND_EAST_POSITION);
        break;

        case Island::south:
            eulerPosition = Island::south;
            euler.setPosition(ISLAND_SOUTH_POSITION);
        break;

        case Island::center:
            eulerPosition = Island::center;
            euler.setPosition(ISLAND_CENTER_POSITION);
        break;
    }
}

void Level::reset(){
    crossedBridges.clear();
    for(int i = 0; i < totalLoadedBridges; i++){
        levelBridges[i].setCrossed(false);
        levelBridges[i].setColor(sf::Color::White);
    }

    moveEuler(Island::east);
}