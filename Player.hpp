#include "Road.hpp"
#include "Settlement.hpp"
#include "Card.hpp"
#include <vector>

using std::vector;

class Player {
    private:
    owner id;
    int victoryPoints;
    int resources[5];
    vector<Card> cards;


    public:
    Player(owner id);
    int getTotResources();
    void displayResources();
    void displayCards();

    void addCard(Card& card){
         cards.push_back(card); 
    }
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