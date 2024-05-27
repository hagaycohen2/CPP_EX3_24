#include "CatanObject.hpp"
#include <vector>

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
    void load(int id, owner objowner, CatanObject* neighborhood[6], pair<int, resource> resources[3], bool isCity){
        this->setId(id);
        this->setOwner(objowner);
        this->setNeighborhood(neighborhood);
        for (int i = 0; i < 3; i++) {
            this->resources[i] = resources[i];
        }
        this->isCity = isCity;
    }
    string occupationAtempt(owner player);
    string toString();
    bool getIsCity() {
        return this->isCity;
    }

};
