#include "menuState.h"
#include "graphicsManager.h"
#include "eventsManager.h"


MenuState::MenuState(StateMachine* pStateMachine, GraphicsManager* stateGraphicsManager, EventsManager* stateEventsManager):
State(pStateMachine, stateGraphicsManager, stateEventsManager),
background(*stateGraphicsManager->loadTexture(MENUBACKGROUND_PATH)),
title("Pontes de Konigsberg", *stateGraphicsManager->loadFont("./assets/anirm__.ttf"), TITLE_SIZE),
play1Button(stateGraphicsManager->loadFont("./assets/anirm__.ttf"), "Jogar Primeira Fase", PLAY1_BUTTON_SIZE, sf::Color::White, PLAY1_BUTTON_POSITION),
play2Button(stateGraphicsManager->loadFont("./assets/anirm__.ttf"), "Jogar Segunda Fase", PLAY2_BUTTON_SIZE, sf::Color::White, PLAY2_BUTTON_POSITION),
exitButton(stateGraphicsManager->loadFont("./assets/anirm__.ttf"), "Sair", EXIT_BUTTON_SIZE, sf::Color::White, EXIT_BUTTON_POSITION)
{
    background.setPosition(0, 0);
    sf::Vector2f canvasSize = stateGraphicsManager->getCanvasSize();
    sf::FloatRect backgroundRect = background.getGlobalBounds();
    background.scale(canvasSize.x/backgroundRect.width, canvasSize.y/backgroundRect.height);

    title.setPosition(TITLE_POSITION);
    title.setFillColor(sf::Color::White);

    background.setColor(sf::Color(180, 180, 180, 255));

    stateEventsManager->addClickable(GET_CLICKABLE_POINTER(play1Button));
    stateEventsManager->addClickable(GET_CLICKABLE_POINTER(play2Button));
    stateEventsManager->addClickable(GET_CLICKABLE_POINTER(exitButton));
}

MenuState::~MenuState(){
    stateEventsManager->removeClickable(GET_CLICKABLE_POINTER(play1Button));
    stateEventsManager->removeClickable(GET_CLICKABLE_POINTER(play2Button));
    stateEventsManager->removeClickable(GET_CLICKABLE_POINTER(exitButton));
}


void MenuState::update(){
    if(play1Button.isHovering()){
        play1Button.setFillColor(sf::Color::Blue);
        if(play1Button.wasClicked())
            pStateMachine->changeState(2, (void*)((bool&&)false));
    }
    else
        play1Button.setFillColor(sf::Color::White);

    if(play2Button.isHovering()){
        play2Button.setFillColor(sf::Color::Blue);
        if(play2Button.wasClicked())
            pStateMachine->changeState(2, (void*)((bool&&)true));
    }
    else
        play2Button.setFillColor(sf::Color::White);

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
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(play1Button));
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(play2Button));
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(exitButton));
}