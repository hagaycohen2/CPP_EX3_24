/**
 * Authors: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

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

    void init(); // initialize the game board and deck
    void shuffleCards(); 
    void displayBoard();

    void prepRound(); // the round before the game starts

    int diceRoll();
    void diceRoll_7(); // if the dice roll is 7
    void distributeResources(int dice);
    void addPayment(owner player, pair<int, resource>* resourceVec); // add resources to the payment vector

    bool buildSettlement(int playerId, int settlement_id);
    bool buildRoad(int playerId, int road_id);
    bool buildCity(int playerId, int settlement_id);

    bool buyCard(int playerId);
    int playerCards(int playerId);
    void playCard(int playerId, type card);
    void playMonopoly(int playerId);
    void playYearOfPlenty(int playerId);
    void playRoadBuilding(int playerId);

    resource intToResource(int res);
    bool tradeValues(vector<pair<resource, int>>& values); // input values for trade
    bool makeAnOffer(int playerId, vector<pair<resource, int>>& give, vector<pair<resource, int>>& receive);
    void makeTrade(int playerId, vector<pair<resource, int>>& give, int otherPlayerId, vector<pair<resource, int>>& receive);

    bool victroryCheck(int playerId);

   public:
    CatanGame(); // constructor
    int play(); // main game loop, all user input will be here, incapsulate the game
    int demo(); // demo of one round of the game
};
