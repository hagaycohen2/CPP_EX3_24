/**
 * Authors: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */


#include "Card.hpp"

Card::Card(type t){
    this->cardType = t;
}

void Card::display(){
    switch (this->cardType) {
        case KNIGHT:
            cout << "Knight" << endl;
            cout << "Your knight count increases by one when you play this card" << endl;
            break;
        case VICTORY_POINT:
            cout << "Victory Point" << endl;
            cout << "You get a victory point when you play this card" << endl;
            break;
        case ROAD_BUILDING:
            cout << "Road Building" << endl;
            cout << "You can build two roads" << endl;
            break;
        case MONOPOLY:
            cout << "Monopoly" << endl;
            cout << "You can take all of a resource from all players" << endl;
            break;
        case YEAR_OF_PLENTY:
            cout << "Year of Plenty" << endl;
            cout << "You can take two resources of your choice" << endl;
            break;
        case GENERIC:
            cout << "Generic" << endl;
            cout << "This card does nothing" << endl;
            break;
    }
}