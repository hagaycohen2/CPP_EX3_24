#pragma once

#include "CatanObject.hpp"
#include "Player.hpp"
#include "iostream"

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::swap;
using std::vector;

class CatanGame {
   private:
    Player players[3];
    int knightCount[3];
    Settlement settlements[54];
    Road roads[72];
    vector<pair<owner, resource>> payment[11];  // exsmple: payment[3] = { {YELLOW, WOOD}, {RED, BRICK} }
    vector<Card> cards;                         // 3 knights, 4 victory points, 2 road building, 2 monopoly, 2 year of plenty

    void init();
    void shuffleCards();
    void displayBoard();

    void prepRound();

    int diceRoll();
    void diceRoll_7();
    void distributeResources(int dice);
    void addPayment(owner player, pair<int, resource>* resourceVec);

    bool buildSettlement(int playerId, int settlement_id);
    bool buildRoad(int playerId, int road_id);
    bool buildCity(int playerId, int settlement_id);

    bool buyCard(int playerId);
    int getCardIndex(int playerId);
    void playCard(int playerId, type card);
    void playMonopoly(int playerId);
    void playYearOfPlenty(int playerId);
    void playRoadBuilding(int playerId);

    resource intToResource(int res);
    bool tradeValues(vector<pair<resource, int>>* values);
    bool makeAnOffer(int playerId, vector<pair<resource, int>> give, vector<pair<resource, int>> receive);
    void makeTrade(int playerId, vector<pair<resource, int>> give, int otherPlayerId, vector<pair<resource, int>> receive);

    bool victroryCheck(int playerId);

   public:
    CatanGame();
    int play();
};
