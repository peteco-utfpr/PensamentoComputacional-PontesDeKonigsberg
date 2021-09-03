#include "menuState.h"
#include "graphicsManager.h"
#include "eventsManager.h"


MenuState::MenuState(StateMachine* pStateMachine, GraphicsManager* stateGraphicsManager, EventsManager* stateEventsManager):
State(pStateMachine, stateGraphicsManager, stateEventsManager),
background(*stateGraphicsManager->loadTexture(MENUBACKGROUND_PATH)),
title("Pontes de Konigsberg", *stateGraphicsManager->loadFont("./assets/anirm__.ttf"), TITLE_SIZE),
playButton(stateGraphicsManager->loadFont("./assets/anirm__.ttf"), "Jogar", PLAY_BUTTON_SIZE, sf::Color::White, PLAY_BUTTON_POSITION),
exitButton(stateGraphicsManager->loadFont("./assets/anirm__.ttf"), "Sair", PLAY_BUTTON_SIZE, sf::Color::White, EXIT_BUTTON_POSITION)
{
    background.setPosition(0, 0);
    sf::Vector2f canvasSize = stateGraphicsManager->getCanvasSize();
    sf::FloatRect backgroundRect = background.getGlobalBounds();
    background.scale(canvasSize.x/backgroundRect.width, canvasSize.y/backgroundRect.height);

    title.setPosition(TITLE_POSITION);
    title.setFillColor(sf::Color::White);

    background.setColor(sf::Color(180, 180, 180, 255));

    stateEventsManager->addClickable(GET_CLICKABLE_POINTER(playButton));
    stateEventsManager->addClickable(GET_CLICKABLE_POINTER(exitButton));
}

MenuState::~MenuState(){
    stateEventsManager->removeClickable(GET_CLICKABLE_POINTER(playButton));
    stateEventsManager->removeClickable(GET_CLICKABLE_POINTER(exitButton));
}


void MenuState::update(){
    if(playButton.isHovering()){
        playButton.setFillColor(sf::Color::Blue);
        if(playButton.wasClicked())
            pStateMachine->changeState(2, nullptr);
    }
    else
        playButton.setFillColor(sf::Color::White);

    if(exitButton.isHovering()){
        exitButton.setFillColor(sf::Color::Blue);
        if(exitButton.wasClicked())
            stateEventsManager->closeWindow();
    }
    else
        exitButton.setFillColor(sf::Color::White);


}

void MenuState::render(){
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(background));
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(title));
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(playButton));
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(exitButton));
}