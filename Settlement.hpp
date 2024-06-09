#pragma once

#include <vector>

#include "CatanObject.hpp"

// using std::vector;
using std::pair;

/**
 * Settlement is a class that represents a settlement in the game.
 * The class inherits from CatanObject.
 * The class contains an owner attribute that will be used to determine the owner of the settlement.
 * And a neiborhood attribute of the settlements that are adjacent to the settlement.
 * Also in the neiborhood are the roads that are adjacent to the settlement.
 * The class contains a resources attribute that will be used to determine the resources that the settlement produces.
 * The class contains a bool attribute that will be used to determine if the settlement is a city.
 */

class Settlement : public CatanObject {
   private:
    pair<int, resource> resources[3];
    bool isCity;

   public:

    void load(int id, owner objowner, CatanObject* s1, CatanObject* s2, CatanObject* s3, CatanObject* r1, CatanObject* r2, CatanObject* r3,
              pair<int, resource> p1, pair<int, resource> p2, pair<int, resource> p3);
    bool occupationAtempt(owner player);
    // string toString();

    pair<int, resource>* getResources() { return this->resources; }
    bool getIsCity() { return this->isCity; }
    void setIsCity() { this->isCity = true; }
    string getChar() { return this->isCity ? " █ " : " ▄ "; }
};
