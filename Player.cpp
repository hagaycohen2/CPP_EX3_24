/**
 * Authors: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#include "Player.hpp"
#include "CatanObject.hpp"

Player::Player(){
    this->id = EMPTY;
    this->victoryPoints = 0;
    for (int i = 0; i < 5; i++) {
        this->resources[i] = 0;
    }
    this->cards = {};
}

string Player:: getColor() {
    switch (this->id) {
        case YELLOW:
            return "\033[1;33m";
        case BLUE:
            return "\033[1;34m";
        case RED:
            return "\033[1;31m";
        default:
            return "\033[0m";
    }
}

string Player::getOwner() {
    switch (this->id) {
        case YELLOW:
            return "Yellow";
        case BLUE:
            return "Blue";
        case RED:
            return "Red";
        default:
            return "Empty";
    }
}

int Player::getTotResources() {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += this->resources[i];
    }
    return total;
}

void Player::displayResources() {
    for (int i = 0; i < 5; i++) {
        cout << getResourceName(i) << ": ";
        cout << this->resources[i] << " ";
    }
    cout << endl;
}

void Player::displayCards() {
    for (int i = 0; i < this->cards.size(); i++) {
        cout << "Card " << i << ":\n";
       this->cards[i].display() ;
    }
}

type Player::removeCard(int index) {
    type temp = this->cards[index].getCardType();
    this->cards.erase(this->cards.begin() + index);
    return temp;
}

