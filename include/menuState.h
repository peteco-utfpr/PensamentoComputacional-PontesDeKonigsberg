#ifndef _MENUSTATE_H
#define _MENUSTATE_H
#include "state.h"
#include "textButton.h"

#define MENUBACKGROUND_PATH "assets/konigsberg-1581-22.jpg"
#define MENU_FONT_PATH "./assets/anirm__.ttf"

#define TITLE_SIZE            70
#define PLAY_BUTTON_SIZE      50
#define EXIT_BUTTON_SIZE      50
#define TITLE_POSITION        {405.0f, 200.0f}
#define PLAY_BUTTON_POSITION  {860.0f, 500.0f}
#define EXIT_BUTTON_POSITION  {860.0f, 650.0f}

class MenuState: public State{
private:
     sf::Sprite background;
     sf::Text title;     
     TextButton playButton;
     TextButton exitButton;

public:
     MenuState(StateMachine* pStateMachine = NULL, GraphicsManager* stateGraphicsManager = NULL, EventsManager* stateEventsManager = NULL);
     virtual ~MenuState();

     virtual void enter(void* arg){}
     virtual void exit(){}

     virtual void update();
     virtual void render();

};

#endif