/**
 * Authors: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#pragma once

#include <iostream>
#include <string>
using std::string;

enum owner { YELLOW,
             BLUE,
             RED,
             EMPTY };
enum resource { STONE,
                WOOD,
                BRICK,
                SHEEP,
                WHEAT,
                NONE };

 string getResourceName(int res);
/**
 * CatanObject is the base class for all objects in the game.
 * The objects Settlement and Road will inherit from this class.
 * The class contains an owner attribute that will be used to determine the owner of the object.
 * And a neiborhood attribute of all catan objects that are adjacent to the object.
 */
class CatanObject {
   private:
    int id;
    owner objowner;
    CatanObject* neighborhood[6];

   protected:
    void setOwner(owner new_owner) {
        this->objowner = new_owner;
    }
    void setId(int new_id) {
        this->id = new_id;
    }
    void setNeighborhood(CatanObject* neighborhood[6]);

    CatanObject** getNeighborhood() {
        return this->neighborhood;
    }

   public:
    owner getOwner() {
        return this->objowner;
    }
    int getId() {
        return this->id;
    }
    string getColor();

    virtual bool occupationAtempt(owner player) = 0;
    // virtual string toString() = 0;
};
