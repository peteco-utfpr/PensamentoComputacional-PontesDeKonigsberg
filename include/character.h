#ifndef CHARACTER_H
#define CHARACTER_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <bits/stdc++.h>

#include "clickable.h"

/*


VARIÁVEIS PÚBLICAS:
- bool isPriest -> Tem o objetivo único de saber se trata de um missionário (true) ou um canibal (false).
- int location -> Essa variável armazena qual é o local do personagem, se ele está no lado esquerdo (0), no barco (1) ou no lado direito (2).

FUNÇÕES PÚBLICAS:
- Character () -> É o grande construtor, ele inicializa todas as variáveis, até o de sua classe mãe.
- void setCharacter () -> Essa função, importantíssima, serve como um constutor, porém como é instanciado um vetor no main, é necessário uma função para tratar com cada objeto,
onde se encontra essa função.
- void moveTo () -> Essa função serve para organizar os comandos de mover o personagem, para dentro do barco ou para fora.

*/
class Character : public sf::Sprite, public Clickable{

    private:
        sf::Texture *texture;

    public:
        Character(sf::Texture* texture = NULL, sf::Vector2f position = {0.0f, 0.0f}, sf::Vector2f scale = {1.0f, 1.0f}); //Construtor básico da classe;
        virtual ~Character();
        void setBright(bool bright);
};

#endif /* CHARACTER_H */