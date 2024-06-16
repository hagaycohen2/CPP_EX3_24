#include "Card.hpp"
#include "CatanGame.hpp"
#include "CatanObject.hpp"
#include "Player.hpp"
#include "Road.hpp"
#include "Settlement.hpp"
#include "doctest.h"

using namespace std;

Settlement s, s1, s2, s3;
Road r1, r2, r3, r4, r5, r6;
pair<int, resource> p1 = {1, WOOD};
pair<int, resource> p2 = {2, BRICK};
pair<int, resource> p3 = {3, SHEEP};
Card c1(KNIGHT), c2(VICTORY_POINT), c3(ROAD_BUILDING), c4(MONOPOLY), c5(YEAR_OF_PLENTY);
Player player1, player2, player3;

TEST_CASE("Settlements") {
    SUBCASE("constructor") {
        Settlement s;
        CHECK(s.getIsCity() == false);
    }
    SUBCASE("load") {
        s.load(1, YELLOW, &s1, &s2, &s3, &r1, &r2, &r3, p1, p2, p3);
        CHECK(s.getOwner() == YELLOW);
        CHECK(s.getIsCity() == false);
        CHECK(s.getId() == 1);
        CHECK(s.getResources()[0] == p1);
        CHECK(s.getResources()[1] == p2);
        CHECK(s.getResources()[2] == p3);
    }
    SUBCASE("occupationAtempt") {
        s.load(1, EMPTY, nullptr, nullptr, nullptr, &r1, &r2, &r3, p1, p2, p3);
        r1.load(1, YELLOW, &s, &s1, &r2, &r4, &r5, &r6);
        CHECK(s.occupationAtempt(BLUE) == false);
        CHECK(s.occupationAtempt(YELLOW) == true);
    }
    SUBCASE("preOccupationAtempt") {
        s.load(1, EMPTY, &s1, nullptr, nullptr, &r1, &r2, &r3, p1, p2, p3);
        s1.load(2, EMPTY, &s, nullptr, nullptr, &r1, &r2, &r3, p1, p2, p3);
        CHECK(s.preOccupationAtempt(YELLOW) == true);
        CHECK(s.preOccupationAtempt(BLUE) == false);
        CHECK(s1.preOccupationAtempt(YELLOW) == false);
    }
}
TEST_CASE("Roads") {
    SUBCASE("load") {
        r1.load(1, YELLOW, &s, &s1, &r2, &r4, &r5, &r6);
        CHECK(r1.getOwner() == YELLOW);
    }
    SUBCASE("occupationAtempt") {
        r1.load(1, EMPTY, &s, &s1, &r2, &r4, &r5, &r6);
        s.load(1, YELLOW, nullptr, nullptr, nullptr, &r1, &r2, &r3, p1, p2, p3);
        s1.load(2, BLUE, nullptr, nullptr, nullptr, &r1, &r2, &r3, p1, p2, p3);
        CHECK(r1.occupationAtempt(BLUE) == true);
        CHECK(r1.occupationAtempt(YELLOW) == false);
    }
    SUBCASE("occupationAtempt_empty_settlements") {
        r1.load(1, EMPTY, &s, &s1, &r2, &r4, &r5, &r6);
        s.load(1, EMPTY, nullptr, nullptr, nullptr, &r1, &r2, &r3, p1, p2, p3);
        s1.load(2, EMPTY, nullptr, nullptr, nullptr, &r1, &r2, &r3, p1, p2, p3);
        CHECK(r1.occupationAtempt(BLUE) == false);
        r2.load(2, BLUE, &s, &s1, &r1, &r3, &r5, &r6);
        CHECK(r1.occupationAtempt(BLUE) == true);
    }
    SUBCASE("occupationAtempt_occ_settlement") {
        r1.load(1, EMPTY, &s, &s1, &r2, &r4, &r5, &r6);
        s.load(1, YELLOW, nullptr, nullptr, nullptr, &r1, &r2, &r3, p1, p2, p3);
        s1.load(2, EMPTY, nullptr, nullptr, nullptr, &r1, &r2, &r3, p1, p2, p3);
        r2.load(2, BLUE, &s, &s1, &r1, &r3, &r5, &r6);
        CHECK(r1.occupationAtempt(BLUE) == false);      // s is being occupied by YELLOW
        r5.load(5, BLUE, &s, &s1, &r1, &r3, &r2, &r6);  // r5 is adjacent to s
        CHECK(r1.occupationAtempt(BLUE) == true);
    }
}
TEST_CASE("cards") {
    SUBCASE("constructor") {
        CHECK(c1.getCardType() == KNIGHT);
        CHECK(c2.getCardType() == VICTORY_POINT);
        CHECK(c3.getCardType() == ROAD_BUILDING);
        CHECK(c4.getCardType() == MONOPOLY);
        CHECK(c5.getCardType() == YEAR_OF_PLENTY);
    }
    SUBCASE("display") {
        CHECK_NOTHROW(c1.display());
        CHECK_NOTHROW(c2.display());
        CHECK_NOTHROW(c3.display());
        CHECK_NOTHROW(c4.display());
        CHECK_NOTHROW(c5.display());
    }
}
TEST_CASE("Players") {
    SUBCASE("constructor") {
        CHECK(player1.getId() == EMPTY);
        CHECK(player1.getVictoryPoints() == 0);
        CHECK(player1.getCardCount() == 0);
        CHECK(player1.getTotResources() == 0);
    }
    SUBCASE("AddCard and RemoveCard") {
        player1.addCard(c1);
        CHECK(player1.getCardCount() == 1);
        CHECK(player1.removeCard(0) == KNIGHT);
        CHECK(player1.getCardCount() == 0);
    }
    SUBCASE("incrementVictoryPoints") {
        player1.incrementVictoryPoints();
        CHECK(player1.getVictoryPoints() == 1);
    }
    SUBCASE("incrementResource") {
        player1.incrementResource(WOOD);
        CHECK(player1.getResource(WOOD) == 1);
    }
    SUBCASE("decrementResource") {
        player1.incrementResource(BRICK);
        player1.decrementResource(BRICK);
        CHECK(player1.getResource(BRICK) == 0);
    }
    SUBCASE("getowner and getcolor") {
        player1.setId(YELLOW);
        CHECK(player1.getOwner() == "Yellow");
        CHECK(player1.getColor() == "\033[1;33m");

        player1.setId(BLUE);
        CHECK(player1.getOwner() == "Blue");
        CHECK(player1.getColor() == "\033[1;34m");
    }
}