#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;

enum type { KNIGHT,
            VICTORY_POINT,
            ROAD_BUILDING,
            MONOPOLY,
            YEAR_OF_PLENTY,
            GENERIC
};

class Card {
    private:
    type cardType;
   public:
    Card(type t) ;
    type getCardType(){
        return cardType;
    }
    void display();
};

