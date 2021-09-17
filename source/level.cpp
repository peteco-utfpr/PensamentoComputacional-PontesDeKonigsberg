#include "level.h"

Level::Level(GraphicsManager* levelGraphicsManager, EventsManager* levelEventsManager, bool possible):
background(*levelGraphicsManager->loadTexture(BACKGROUND_TEXTURE)),
euler(*levelGraphicsManager->loadTexture(EULER_TEXTURE)),
whiteFlag(*levelGraphicsManager->loadTexture(WHITE_FLAG_TEXTURE)),
totalLoadedBridges(possible ? POSSIBLE_LEVEL_NUMBER_OF_BRIDGES : IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES),
winMessage("Voce Conseguiu!", *levelGraphicsManager->loadFont("./assets/anirm__.ttf"), 50),
retryButton(levelGraphicsManager->loadFont(BUTTON_FONT_PATH), "tentar novamente", 50, sf::Color::Yellow),
giveUpButton(levelGraphicsManager->loadFont(BUTTON_FONT_PATH), "Desistir", 50, sf::Color::Yellow, GIVE_UP_BUTTON_POSITION),
exitButton(levelGraphicsManager->loadFont(BUTTON_FONT_PATH), "Sair", 50, sf::Color::Yellow, LEVEL_EXIT_BUTTON_POSITION)
{


    this->levelGraphicsManager = levelGraphicsManager;
    this->levelEventsManager = levelEventsManager;

    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(retryButton));
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(giveUpButton));
    levelEventsManager->addClickable(GET_CLICKABLE_POINTER(exitButton));

    //setting up bridges---------------
    levelBridges = new Bridge[possible ? POSSIBLE_LEVEL_NUMBER_OF_BRIDGES : IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES];

    levelGraph = new Graph(4);

    if(possible){
        sf::Vector2f levelBridgesPositions[POSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = POSSIBLE_LEVEL_BRIDGE_POSITION_VECTOR;
        sf::Vector2f levelBridgesScales[POSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = POSSIBLE_LEVEL_BRIDGE_SCALE_VECTOR;
        float levelBridgesRotations[POSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = POSSIBLE_LEVEL_BRIDGE_ROTATION_VECTOR;
        Island levelBridgesSources[POSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = POSSIBLE_LEVEL_BRIDGE_SOURCE_VECTOR;
        Island levelBridgesDestinations[POSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = POSSIBLE_LEVEL_BRIDGE_DEST_VECTOR;

        for(int i = 0; i < totalLoadedBridges; i++){
            levelBridges[i].setTexture(*levelGraphicsManager->loadTexture(BRIDGE_TEXTURE));
            levelBridges[i].setPosition(levelBridgesPositions[i]);
            levelBridges[i].setScale(levelBridgesScales[i]);
            levelBridges[i].setRotation(levelBridgesRotations[i]);
            levelBridges[i].setId(i);
            levelBridges[i].setClickBox(levelBridges[i].getGlobalBounds());

            levelEventsManager->addClickable(GET_CLICKABLE_POINTER(levelBridges[i]));

            levelGraph->addEdge(levelBridgesSources[i], levelBridgesDestinations[i], false, &levelBridges[i]);
        }
    }
    else{
        sf::Vector2f levelBridgesPositions[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = IMPOSSIBLE_LEVEL_BRIDGE_POSITION_VECTOR;
        sf::Vector2f levelBridgesScales[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = IMPOSSIBLE_LEVEL_BRIDGE_SCALE_VECTOR;
        float levelBridgesRotations[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = IMPOSSIBLE_LEVEL_BRIDGE_ROTATION_VECTOR;
        Island levelBridgesSources[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES] = IMPOSSIBLE_LEVEL_BRIDGE_SOURCE_VECTOR;
        Island levelBridgesDestinations[IMPOSSIBLE_LEVEL_NUMBER_OF_BRIDGES] =IMPOSSIBLE_LEVEL_BRIDGE_DEST_VECTOR;

        for(int i = 0; i < totalLoadedBridges; i++){
            levelBridges[i].setTexture(*levelGraphicsManager->loadTexture(BRIDGE_TEXTURE));
            levelBridges[i].setPosition(levelBridgesPositions[i]);
            levelBridges[i].setScale(levelBridgesScales[i]);
            levelBridges[i].setRotation(levelBridgesRotations[i]);
            levelBridges[i].setId(i);
            levelBridges[i].setClickBox(levelBridges[i].getGlobalBounds());

            levelEventsManager->addClickable(GET_CLICKABLE_POINTER(levelBridges[i]));

            levelGraph->addEdge(levelBridgesSources[i], levelBridgesDestinations[i], false, &levelBridges[i]);
        }
    }
    
    //-------------

    //setting up background---------
    background.setPosition(0, 0);
    sf::Vector2f canvasSize = levelGraphicsManager->getCanvasSize();
    sf::FloatRect backgroundRect = background.getGlobalBounds();
    background.scale(canvasSize.x/backgroundRect.width, canvasSize.y/backgroundRect.height);
    //-------------

    //Setting up Euler------
    eulerPosition = Island::north;
    euler.setPosition(ISLAND_NORTH_POSITION);
    euler.setScale({0.2, 0.2});
    //-------------
    winMessage.setPosition(WIN_MESSAGE_POSITION);

    whiteFlag.setPosition(WHITE_FLAG_POSITION);
    whiteFlag.setScale(WHITE_FLAG_SCALE);

    tries = 0;

    stepSoundBuffer.loadFromFile(CROSSING_SOUND_PATH);
    crossingSound.setBuffer(stepSoundBuffer);

}

Level::~Level(){
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(retryButton));
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(giveUpButton));
    levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(exitButton));

    for(int i = 0; i < totalLoadedBridges; i++)
        levelEventsManager->removeClickable(GET_CLICKABLE_POINTER(levelBridges[i]));
    delete[] levelBridges;

    delete levelGraph;
}

bool Level::update(){
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

    //checking if player won
    won = true;
    for(int i = 0; i < Island::total; i++){
        levelGraph->iterateBySource(i);
        Node* it = levelGraph->getNextNode();
        while(it){
            if(!it->linkedBridge->isCrossed()){
                won = false;
                break;
            }
            it = levelGraph->getNextNode();
        }
    }

    if(retryButton.isHovering()){
        retryButton.setFillColor(sf::Color::Blue);
        if(stuck && retryButton.wasClicked())
            reset();
    }
    else
        retryButton.setFillColor(sf::Color::Yellow);

    if(giveUpButton.isHovering()){
        giveUpButton.setFillColor(sf::Color::Blue);
        if(stuck && tries > 10 && giveUpButton.wasClicked())
            return true;//quit
    }
    else
        giveUpButton.setFillColor(sf::Color::Yellow);
    
    if(exitButton.isHovering()){
        exitButton.setFillColor(sf::Color::Blue);
        if(won && exitButton.wasClicked())
            return true;//quit
    }
    else
        exitButton.setFillColor(sf::Color::Yellow);

    return false;

}   

void Level::render(){
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(background));
    levelGraphicsManager->draw(GET_DRAWABLE_POINTER(euler));

    for(int i = 0; i < totalLoadedBridges; i++)
        levelGraphicsManager->draw(GET_DRAWABLE_POINTER(levelBridges[i]));

    if(stuck)
        levelGraphicsManager->draw(GET_DRAWABLE_POINTER(retryButton));

    if(stuck && tries > 10){
        levelGraphicsManager->draw(GET_DRAWABLE_POINTER(whiteFlag));
        levelGraphicsManager->draw(GET_DRAWABLE_POINTER(giveUpButton));
    }
    if(won){
        levelGraphicsManager->draw(GET_DRAWABLE_POINTER(winMessage));
        levelGraphicsManager->draw(GET_DRAWABLE_POINTER(exitButton));
    }
}

void Level::moveEuler(int destination){
    crossingSound.play();
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
    tries++;
    for(int i = 0; i < totalLoadedBridges; i++){
        levelBridges[i].setCrossed(false);
        levelBridges[i].setColor(sf::Color::White);
    }

    moveEuler(Island::north);
}