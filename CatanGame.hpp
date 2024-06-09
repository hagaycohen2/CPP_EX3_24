#pragma once

#include "Player.hpp"
#include "iostream"

using std::string;
using std::vector;
using std::pair;
using std::cout;
using std::endl;

class CatanGame{
    private:
    Player players[3];
    int knightCount[3];
    Settlement settlements[54];
    Road roads[72];
    vector<pair<owner, resource>> paiment[11];
    vector<Card> cards;  // 3 knights, 4 victory points, 2 road building, 2 monopoly, 2 year of plenty

    void init();
    void shuffleCards();
    void displayBoard();

    void prepRound();

    int diceRoll();
    void distributeResources(int dice);

    // bool buildSettlement(owner player, int settlement_id);
    // bool buildRoad(owner player, int road_id);
    // bool buildCity(owner player, int settlement_id);

    // bool buyCard(owner player);
    // void playCard(owner player, Card card);

    // bool makeAnOffer(owner player, resource give, resource receive);
    // bool makeTrade(owner player, resource give, resource receive);

    // bool victroryCheck(owner player);


    


    public:
    CatanGame();
    int play();
};
