#include "Card.hpp"
#include "CatanGame.hpp"
#include "CatanObject.hpp"
#include "Player.hpp"
#include "Road.hpp"
#include "Settlement.hpp"
#include "doctest.h"

using namespace std;


        Settlement s, s1, s2, s3;
        Road r1, r2, r3 , r4, r5, r6;
        pair<int, resource> p1 = {1, WOOD};
        pair<int, resource> p2 = {2, BRICK};
        pair<int, resource> p3 = {3, SHEEP};

TEST_CASE("Settlements") {
    SUBCASE("constructor") {
        Settlement s;
        CHECK(s.getOwner() == EMPTY);
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
        s.load(1, EMPTY, &s1, &s2, &s3, &r1, &r2, &r3, p1, p2, p3);
        r1.load(1, YELLOW, &s, &s1, &r2, &r4, &r5, &r6);
        CHECK(s.occupationAtempt(YELLOW) == true);
    }
}

