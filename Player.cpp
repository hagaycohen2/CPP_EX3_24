#include "Player.hpp"

Player::Player(owner id){
    this->id = id;
    this->victoryPoints = 0;
    for (int i = 0; i < 5; i++) {
        this->resources[i] = 0;
    }
}