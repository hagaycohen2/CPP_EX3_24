/**
 * Authors: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#include "Road.hpp"

using std::cout;
using std::endl;

void Road::load(int road_id, owner owner, CatanObject* s1, CatanObject* s2, CatanObject* r1, CatanObject* r2, CatanObject* r3, CatanObject* r4) {
    this->setId(road_id);
    this->setOwner(owner);
    CatanObject* neighborhood[] = {s1, s2, r1, r2, r3, r4};
    this->setNeighborhood(neighborhood);
}

bool Road::occupationAtempt(owner player) {
    if (this->getOwner() != EMPTY) {
        cout << "The road is already occupied" << endl;
        return false;
    }

    CatanObject** neighborhood = this->getNeighborhood();

    // Check if at least one of the adjacent settlements is owned by the player
    if (neighborhood[0]->getOwner() == player) {
        this->setOwner(player);
        cout << "Road " << this->getId() << " was occupied succesfuly" << endl;
        return true;
    }
    if (neighborhood[1]->getOwner() == player) {
        this->setOwner(player);
        cout << "Road " << this->getId() << " was occupied succesfuly" << endl;
        return true;
    }

    // if none of the adjacent settlements are owned by the player,
    // check if at least one of the adjacent roads is owned by the player and the settlement between them is empty
    if (neighborhood[0]->getOwner() == EMPTY) {
        if (neighborhood[2] != nullptr && neighborhood[2]->getOwner() == player) {
            this->setOwner(player);
            cout << "Road " << this->getId() << " was occupied succesfuly" << endl;
            return true;
        }
        if (neighborhood[3] != nullptr && neighborhood[3]->getOwner() == player) {
            this->setOwner(player);
            cout << "Road " << this->getId() << " was occupied succesfuly" << endl;
            return true;
        }
    }
    if (neighborhood[1]->getOwner() == EMPTY) {
        if (neighborhood[4] != nullptr && neighborhood[4]->getOwner() == player) {
            this->setOwner(player);
            cout << "Road " << this->getId() << " was occupied succesfuly" << endl;
            return true;
        }
        if (neighborhood[5] != nullptr && neighborhood[5]->getOwner() == player) {
            this->setOwner(player);
            cout << "Road " << this->getId() << " was occupied succesfuly" << endl;
            return true;
        }
    }

    cout << "The road is not connected to any of the player's assets" << endl;
    return false;
}