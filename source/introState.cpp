#include "introState.h"

IntroState::IntroState(StateMachine* pStateMachine, GraphicsManager* stateGraphicsManager, EventsManager* stateEventsManager):
State(pStateMachine, stateGraphicsManager, stateEventsManager),
background(*stateGraphicsManager->loadTexture(INTRO_BACKGROUND_PATH)),
logo(*stateGraphicsManager->loadTexture(LOGO_PETECO_PATH)),
title("Pontes de Konigsberg", *stateGraphicsManager->loadFont("../assets/anirm__.ttf"), INTRO_TITLE_SIZE){

    background.setPosition(0, 0);
    sf::Vector2f canvasSize = stateGraphicsManager->getCanvasSize();
    sf::FloatRect backgroundRect = background.getGlobalBounds();
    background.scale(canvasSize.x/backgroundRect.width, canvasSize.y/backgroundRect.height);

    title.setPosition(INTRO_TITLE_INITIAL_POSITION);
    title.setFillColor(sf::Color(255, 255, 255, 0));

    logo.setPosition(LOGO_POSITION);

    frame = 0;

}
IntroState::~IntroState(){

}

void IntroState::update(){

    if(frame < STATIC_LOGO_FRAMES){

    }
    else if(frame < LOGO_FADEOUT_ANIMATION_FRAMES + STATIC_LOGO_FRAMES){
        logo.setColor(sf::Color(255,255,255,255-((frame-STATIC_LOGO_FRAMES)*(255.0/(LOGO_FADEOUT_ANIMATION_FRAMES)))));
    }
    else if(frame < TITLE_FADEIN_ANIMATION_FRAMES + LOGO_FADEOUT_ANIMATION_FRAMES + STATIC_LOGO_FRAMES){
        title.setColor(sf::Color(255,255,255, (frame-LOGO_FADEOUT_ANIMATION_FRAMES - STATIC_LOGO_FRAMES)*(255.0/TITLE_FADEIN_ANIMATION_FRAMES)));
        background.setColor(sf::Color(255,255,255, 255 - (frame-LOGO_FADEOUT_ANIMATION_FRAMES - STATIC_LOGO_FRAMES)*(75.0/TITLE_FADEIN_ANIMATION_FRAMES)));
    }
    else{
        title.move(0, ((float)(TITLE_FINAL_HEIGHT-TITLE_INITIAL_HEIGHT)/TITLE_SLIDE_ANIMATION_FRAMES));
    }

    frame++;

    if(frame > TITLE_SLIDE_ANIMATION_FRAMES + TITLE_FADEIN_ANIMATION_FRAMES + LOGO_FADEOUT_ANIMATION_FRAMES + STATIC_LOGO_FRAMES)
        pStateMachine->changeState(1, nullptr);
}
void IntroState::render(){
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(background));
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(title));
    stateGraphicsManager->draw(GET_DRAWABLE_POINTER(logo));
}