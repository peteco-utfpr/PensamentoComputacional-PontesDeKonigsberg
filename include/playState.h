#ifndef _PLAYSTATE_H
#define _PLAYSTATE_H

#include "state.h"
#include "level.h"

class PlayState: public State{
    private:
        Level* currentLevel;

    public:
        PlayState(StateMachine* pStateMachine = NULL, GraphicsManager* stateGraphicsManager = NULL, EventsManager* stateEventsManager = NULL);
        virtual ~PlayState();

        virtual void enter(void* arg);
        virtual void exit();

        virtual void update();
        virtual void render();

};

#endif