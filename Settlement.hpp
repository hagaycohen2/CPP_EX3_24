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
    Settlement();

    void load(int id, owner objowner, CatanObject* neighborhood[6], pair<int, resource> resources[3]);
    bool occupationAtempt(owner player);
    string toString();

    pair<int, resource>* getResources() { return this->resources; }
    bool getIsCity() { return this->isCity; }
    void setIsCity(bool isCity) { this->isCity = isCity; }
};
