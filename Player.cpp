#include "Player.hpp"

Player::Player(){
    this->id = EMPTY;
    this->victoryPoints = 0;
    for (int i = 0; i < 5; i++) {
        this->resources[i] = 0;
    }
    this->cards = {};
}

void Player::setId(owner id){
    this->id = id;
}

