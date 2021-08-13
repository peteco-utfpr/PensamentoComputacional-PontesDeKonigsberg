#include "eventsManager.h"

EventsManager::EventsManager(sf::RenderWindow* pWindow){
    if(pWindow == NULL)
        printf("WARNING: no window set\n");

    window = pWindow;
    windowClosed = false;
}

EventsManager::~EventsManager(){
    
}

void EventsManager::addClickable(Clickable* clkbl){
    if(clkbl){
        clickables.push_back(clkbl);
    }

}

void EventsManager::removeClickable(Clickable* clkbl){
    if(clkbl){
        for(auto i = clickables.begin(); i != clickables.end(); i++)
            if(*i == clkbl){
                clickables.erase(i);
                break;
            }
    }
}

void EventsManager::pollAll(){
    while(window->pollEvent(currentEvent)){
            switch (currentEvent.type){
                case sf::Event::MouseMoved:{
                    //printf("mouse move event\n"); //Tratando todas as possibilidades na hora de trocar as cores, caso tenha ou não tenha palavras.
                    auto mousePos = window->mapPixelToCoords(mouse.getPosition(*window));
                    for(auto i = clickables.begin(); i != clickables.end(); i++){
                        if((*i)->clickBox.contains((float)mousePos.x, (float)mousePos.y))
                            (*i)->hovering = true;
                        else{
                            (*i)->hovering = false;
                        }
                    }
                    break;
                }
                case sf::Event::Closed: //Evento da janela fechada, no "X" da janela mesmo;
                    windowClosed = true;
                    break;

                case sf::Event::MouseButtonPressed:{ //Caso alguma tecla do mouse seja ativada;
                //printf("mouse button pressed event\n");
                    auto mousePos = window->mapPixelToCoords(mouse.getPosition(*window));
                    for(auto i = clickables.begin(); i != clickables.end(); i++){//busca pelo clicavel selecionado e clica
                        if((*i)->clickBox.contains(mousePos.x, mousePos.y))
                            (*i)->clicked = true;
                    }
                    break;
                }
                case sf::Event::MouseButtonReleased: //Caso alguma tecla do mouse seja desativada;
                //printf("mouse button rel event\n");
                    for(auto i = clickables.begin(); i != clickables.end(); i++)//desclica todos os clicaveis
                            (*i)->clicked = false;
                    break;

                //case sf::Event::Resized:
                    //sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    
                // window.setView(sf::View(visibleArea));
            // break;
            }
        }
}

void EventsManager::closeWindow(){
    windowClosed = true;
}

bool EventsManager::isWindowClosed(){
    if(windowClosed)
        window->close();

    return windowClosed;
}