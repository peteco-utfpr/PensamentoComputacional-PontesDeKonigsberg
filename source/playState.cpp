#include "playState.h"

PlayState::PlayState(StateMachine* pStateMachine, GraphicsManager* stateGraphicsManager, EventsManager* stateEventsManager):
State(pStateMachine, stateGraphicsManager, stateEventsManager){

}

PlayState::~PlayState(){
    if(currentLevel){
        delete currentLevel;
        currentLevel = nullptr;
    }
}

void PlayState::enter(void* arg){
    currentLevel = new Level(stateGraphicsManager, stateEventsManager);
    printf("new level at %d\n", currentLevel);
}

void PlayState::exit(){
    if(currentLevel){
        delete currentLevel;
        currentLevel = nullptr;
    }
    printf("playstate done\n");
}

void PlayState::update(){
    printf("playstate update %d\n", currentLevel);
    if(currentLevel->update())
        pStateMachine->changeState(1, nullptr);
}

void PlayState::render(){
    currentLevel->render();
}