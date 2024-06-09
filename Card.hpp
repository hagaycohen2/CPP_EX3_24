#pragma once

#include <iostream>

enum type { KNIGHT,
            VICTORY_POINT,
            PREMOTION,
};

class Card {
   private:
    type cardType;

   protected:
    type getCardType() { return this->cardType; }

//    public:
//     virtual void display() = 0;
};