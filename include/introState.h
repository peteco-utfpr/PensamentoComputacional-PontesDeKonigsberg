#include "state.h"

class IntroState: public State{
private:

public:
     IntroState(StateMachine* pStateMachine = NULL, GraphicsManager* stateGraphicsManager = NULL, EventsManager* stateEventsManager = NULL);
     virtual ~IntroState();

     virtual void enter(void* arg){}
     virtual void exit(){}

     virtual void update();
     virtual void render();

};
