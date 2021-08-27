#include "graphicsManager.h"

GraphicsManager::GraphicsManager(sf::RenderWindow* pWindow): mainView(sf::FloatRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT)){
    if(!pWindow)
        printf("WARNING: no window set");
    window = pWindow;

    window->setView(mainView);
    window->setFramerateLimit(60);

    window->clear();

}

GraphicsManager::~GraphicsManager(){
    for(auto i = loadedFonts.begin(); i != loadedFonts.end(); i++)
        delete i->second;
    for(auto i = loadedTextures.begin(); i != loadedTextures.end(); i++)
        delete i->second;
}

sf::Font* GraphicsManager::loadFont(std::string fontPath){
    if(loadedFonts.find(fontPath) == loadedFonts.end()){
        sf::Font* loadedFont = new sf::Font();
        if(!loadedFont->loadFromFile(fontPath)){
            printf("ERROR: could not load font!\n");
            return NULL;
        }
        loadedFonts.insert({fontPath, loadedFont});
        
    }
    return loadedFonts[fontPath];

}

sf::Texture* GraphicsManager::loadTexture(std::string TexturePath){
    if(loadedTextures.find(TexturePath) == loadedTextures.end()){
        sf::Texture* loadedTexture = new sf::Texture();
        if(!loadedTexture->loadFromFile(TexturePath)){
            printf("ERROR: could not load texture!\n");
            return NULL;
        }
        loadedTextures.insert({TexturePath, loadedTexture});
    }
    return loadedTextures[TexturePath];

}

const sf::Vector2f GraphicsManager::getCanvasSize(){
    return {CANVAS_WIDTH, CANVAS_HEIGHT};
}

void GraphicsManager::draw(sf::Drawable* drwbl){
    window->draw(*drwbl);

}

void GraphicsManager::render(){
    window->display();
    window->clear(sf::Color::Black);
}