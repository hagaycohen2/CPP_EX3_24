#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;

enum type { KNIGHT,
            VICTORY_POINT,
            ROAD_BUILDING,
            MONOPOLY,
            YEAR_OF_PLENTY
};

class Card {
   public:
    type getCardType();
    void display(){};
};

class KnightCard : public Card {
   public:
    type getCardType() {
        return KNIGHT;
    }
    void display() {
        cout << "Knight" << endl;
        cout << "Your knight count increases by one when you play this card" << endl;
    }
};

class VictoryPointCard : public Card {
   public:
    type getCardType() {
        return VICTORY_POINT;
    }
    void display() {
        cout << "Victory Point" << endl;
        cout << "You get a victory point when you play this card" << endl;
    }
};

class RoadBuildingCard : public Card {
   public:
    type getCardType() {
        return ROAD_BUILDING;
    }
    void display() {
        cout << "Road Building" << endl;
        cout << "You can build two roads" << endl;
    }
};

class MonopolyCard : public Card {
   public:
    type getCardType() {
        return MONOPOLY;
    }
    void display() {
        cout << "Monopoly" << endl;
        cout << "You can take all of one resource type from all players" << endl;
    }
};

class YearOfPlentyCard : public Card {
   public:
    type getCardType() {
        return YEAR_OF_PLENTY;
    }
    void display() {
        cout << "Year of Plenty" << endl;
        cout << "You can take any two resources from the bank" << endl;
    }
};
