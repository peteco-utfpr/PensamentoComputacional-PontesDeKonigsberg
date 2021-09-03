#include "state.h"

//State-------------------------------------------------------
State::State(StateMachine* pStateMachine, GraphicsManager* stateGraphicsManager, EventsManager* stateEventsManager){
    setStateMachine(pStateMachine);
    this->stateGraphicsManager = stateGraphicsManager;
    this->stateEventsManager = stateEventsManager;
}

State::~State(){

}

void State::setStateMachine(StateMachine* pStateMachine){
    this->pStateMachine = pStateMachine;
}

StateMachine* State::getStateMachine(){
    return pStateMachine;
}


//StateMachine-------------------------------------------------

StateMachine::StateMachine(){
    currentStateID = -1;
}

StateMachine::~StateMachine(){
    for(auto i = 0; i<states.size(); i++)
        delete states[i];

}

void StateMachine::addState(State* state){
    states.push_back(state);
}

void StateMachine::changeState(stateID nextStateID, void* arg){
    if(currentStateID != -1)//Se houver um estado atual
        states[currentStateID]->exit();
    currentStateID = nextStateID;
    states[currentStateID]->enter(arg);

}

void StateMachine::update(){
    states[currentStateID]->update();
}

void StateMachine::render(){
    states[currentStateID]->render();
}

const stateID StateMachine::getCurrentState() const{
    return currentStateID;
}
    
void StateMachine::setCurrentState(const stateID state){
    currentStateID = state;
}
