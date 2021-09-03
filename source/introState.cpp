#include "introState.h"


IntroState::IntroState(StateMachine* pStateMachine, GraphicsManager* stateGraphicsManager, EventsManager* stateEventsManager):State(pStateMachine, stateGraphicsManager, stateEventsManager){

}
IntroState::~IntroState(){

}

void IntroState::update(){
    pStateMachine->changeState(1, nullptr);
}
void IntroState::render(){

}