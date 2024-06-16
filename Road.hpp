/**
 * Authors: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#pragma once

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
    void load(int road_id, owner owner, CatanObject* s1 , CatanObject* s2, CatanObject* r1, CatanObject* r2, CatanObject* r3, CatanObject* r4);
    bool occupationAtempt(owner player);
};