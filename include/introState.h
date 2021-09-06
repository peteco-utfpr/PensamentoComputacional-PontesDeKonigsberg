#include "state.h"

#include "graphicsManager.h"
#include "eventsManager.h"

#define INTRO_BACKGROUND_PATH "assets/konigsberg-1581-22.jpg"
#define INTRO_FONT_PATH "./assets/anirm__.ttf"
#define LOGO_PETECO_PATH "./assets/LogoPETECO.png"

#define LOGO_POSITION                        {610.0f, 400.0f}
#define INTRO_TITLE_SIZE                     70
#define INTRO_TITLE_INITIAL_POSITION         {405.0f, 520.0f}
#define TITLE_INITIAL_HEIGHT                 520
#define TITLE_FINAL_HEIGHT                   200
#define STATIC_LOGO_FRAMES                   200
#define LOGO_FADEOUT_ANIMATION_FRAMES        60
#define TITLE_FADEIN_ANIMATION_FRAMES        120
#define TITLE_SLIDE_ANIMATION_FRAMES         60

class IntroState: public State{
private:
     sf::Sprite background;
     sf::Sprite logo;
     sf::Text title;

     int frame;
public:
     IntroState(StateMachine* pStateMachine = NULL, GraphicsManager* stateGraphicsManager = NULL, EventsManager* stateEventsManager = NULL);
     virtual ~IntroState();

     virtual void enter(void* arg){}
     virtual void exit(){}

     virtual void update();
     virtual void render();

};
