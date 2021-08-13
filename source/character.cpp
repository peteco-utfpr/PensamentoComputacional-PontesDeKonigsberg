#include "boat.h"
#include "character.h"
#include "sprites.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <bits/stdc++.h>

#define LEFTSIDE 0 //O lado esquerdo vale como 0;
#define BOATLEFTSIDE 1 //O barco no lado esqurdo vale 1;
#define BOATRIGHTSIDE 2 //O barco no lado direito vale 2;
#define RIGHTSIDE 3 //Quando está no lado direito, vale 3;

class Boat;

//------------------------------------------------------ CHARACTER ----------------------------------------------------------------------------

/*

Character::Character()

    É o grande construtor, ele inicializa todas as variáveis, até o de sua classe mãe.

@param
@return

*/
Character::Character(sf::Texture* texture, characterType type, int location, sf::Vector2f position, sf::Vector2f scale):sf::Sprite(), Clickable(){
    if(!texture)
        printf("WARNING: no texture set!\n");
    else
        this->setTexture(*texture);
    this->type = type;
    this->location = location;
    setScale(scale);
    setPosition(position);
    setClickBox(getGlobalBounds());
    
}

Character::~Character(){

}

/*

void moveTo (std::stack boatSpaces)

    Essa função serve para organizar os comandos de mover o personagem, para dentro do barco ou para fora.

@param std::stack<sf::Vector2f> &leftSpaces -> Como parâmetro, tem os espaços livres no lado esquerdo do rio.
@param std::stack<sf::Vector2f> &boatSpaces -> Nesse, não muito diferente, são os espaços livres dentro do barco.
@param std::stack<sf::Vector2f> &rightSpaces -> Também, nesse estão os lugares livres no lado direito do rio.
@param Boat &boat -> Passando o endereço de boat, onde será alterado alguns valores dentro do barco.
@return

*/
void Character::moveTo (std::stack<sf::Vector2f> &leftSpaces, std::stack<sf::Vector2f> &boatSpaces, std::stack<sf::Vector2f> &rightSpaces, Boat &boat) 
{
    bool isPossible = false; //Fazendo uma condição, caso ele passe dessa condição quer dizer que é um movimento válido.

    if (location == LEFTSIDE || location == RIGHTSIDE){
        if(location == RIGHTSIDE && boat.isOnTheLeft == false && boat.quantChar != 2) //Primeira situação, caso o jogador esteja na terra e o barco esteja no seu lado, no lado direito;
            isPossible = true;

        if(location == LEFTSIDE && boat.isOnTheLeft == true && boat.quantChar != 2) //Segunda situação, os dois no mesmo lado, porém esse no lado esquerdo;
            isPossible = true;

        if(isPossible) { //Aqui só entra se passou pelo menos em uma das verificações;
            if(location == RIGHTSIDE){ //Faz as devidas arrumações com o barco e com as pilhas;
                rightSpaces.push(getPosition()); //Caso ele esteja saindo do lado direito, colocando a posição que ele estava na pilha;

                location = BOATRIGHTSIDE; //Colocando sua nova posição, no barco na esquerda;
            }
            else{
                leftSpaces.push(getPosition()); //Colocando na pilha a sua posição antiga, no lado direito;

                location = BOATLEFTSIDE; //Sua nova posição, se localizando no barco no lado esquerdo;
            }
            setPosition(boatSpaces.top()); //Colocando o sprite no local disponível do barco;
            setClickBox(getGlobalBounds());
            //brightsprite.setPosition(boatSpaces.top()); //Colocando sua sprite de opção dentro do barco;

            boat.quantChar += 1; //Aumentando 1 na quantidade de pessoas que estão dentro do barco;

            boatSpaces.pop(); //Tirando a posição que agora ele ocupa dentro do barco;
        }
    }
    else{ //Caso ele não esteja em nenhuma das duas posições, ele necessáriamente está no barco então é necessário tratar essas duas opções;
        boatSpaces.push(getPosition()); //Colocando uma nova opção disponível no barco;

        if (location == BOATRIGHTSIDE) {
            location = RIGHTSIDE; //Sua nova posição é na terra do lado direito;

            setPosition(rightSpaces.top()); //Colocando o seu sprite no lado direto na vaga que está livre;
            setClickBox(getGlobalBounds());
            //brightsprite.setPosition(rightSpaces.top()); //Colocando a sua sprite de opção também dentro da vaga livre;

            rightSpaces.pop(); //Tirando o espaço que estava livre, que agora está sendo ocupado pelo personagem;
        }
        else{
            location = LEFTSIDE; //Sua nova posição é no lado esquerdo;

            setPosition(leftSpaces.top()); //Colocando sua sprite no lado esquerdo, na vaga que está livre;
            setClickBox(getGlobalBounds());
            //brightsprite.setPosition(leftSpaces.top()); //Colocando a sua sprite de opção no lado direito também;

            leftSpaces.pop(); //Tirando a posição que agora está sendo ocupada agora pelo personagem;
        }

        boat.quantChar -= 1; //Tirando o personagem que acabamos de tirar do barco;
    }
}

void Character::setLoadedTexture (sf::Texture* loadedTexture){
    if(loadedTexture)
        setTexture(*loadedTexture);
}

void Character::setLocation(int location){
    this->location = location;
}

void Character::setBright(bool bright){
    if(bright)
        setColor(sf::Color::Blue);
    else if(getColor() == sf::Color::Blue)
        setColor(sf::Color::White);
}

void Character::setDead(bool dead){
    if(dead)
        setColor(sf::Color::Red);
    else
        setColor(sf::Color::White);

}

int Character::getLocation(){
    return location;
}

Character::characterType Character::getType(){
    return type;
}

//---------------------------------------------------------------------------------------------------------------------------------------------