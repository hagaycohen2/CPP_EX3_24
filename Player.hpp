#include "Road.hpp"
#include "Settlement.hpp"
#include <vector>

using std::vector;

class Player {
    private:
    owner id;
    int victoryPoints;
    int resources[5];

    public:
    Player(owner id);
    void incrementVictoryPoints(){
        this->victoryPoints++;
    }
    int getVictoryPoints(){
        return this->victoryPoints;
    }
    void incrementResource(resource res){
        this->resources[res]++;
    }
    void decrementResource(resource res){
        this->resources[res]--;
    }
    int getResource(resource res){
        return this->resources[res];
    }
    owner getId(){
        return this->id;
    }
};