#include "CatanObject.hpp"

/**
 * Road is a class that represents a road in the game.
 * The class inherits from CatanObject.
 * The class contains an owner attribute that will be used to determine the owner of the road.
 * And a neiborhood attribute of the settlements that are adjacent to the road.
 * Also in the neiborhood are the roads that are adjacent to the end settlements of the road.
 */
class Road : public CatanObject {
    public:
    Road();
    void load(int road_id, owner owner, CatanObject* neighborhood[6]){
        this->setId(road_id);
        this->setOwner(owner);
        this->setNeighborhood(neighborhood);
    }
    string occupationAtempt(owner player);
    string toString();
};