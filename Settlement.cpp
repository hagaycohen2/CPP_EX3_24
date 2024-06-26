/**
 * Authors: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#include "Settlement.hpp"

void Settlement::load(int id, owner objowner, CatanObject* s1, CatanObject* s2, CatanObject* s3, CatanObject* r1, CatanObject* r2, CatanObject* r3,
                      pair<int, resource> p1, pair<int, resource> p2, pair<int, resource> p3) {
    this->setId(id);
    this->setOwner(objowner);
    CatanObject* neighborhood[] = {s1, s2, s3, r1, r2, r3};
    this->setNeighborhood(neighborhood);
    this->resources[0] = p1;
    this->resources[1] = p2;
    this->resources[2] = p3;
    this->isCity = false;
}

bool Settlement::occupationAtempt(owner player) {
    if (this->getOwner() != EMPTY) {
        cout << "The settlement is already occupied" << endl;
        return false;
    }

    CatanObject** neighborhood = this->getNeighborhood();

    // Check if the adjacent settlements are empty
    for (int i = 0; i < 3; i++) {
        if (neighborhood[i] != nullptr && neighborhood[i]->getOwner() != EMPTY) {
            cout << "There is an adjacent settlement that is already occupied" << endl;
            return false;
        }
    }

    // Check if at least one of the adjacent roads is owned by the player
    for (int i = 3; i < 6; i++) {
        if (neighborhood[i] != nullptr && neighborhood[i]->getOwner() == player) {
            this->setOwner(player);
            cout << "Settlement " << this->getId() << " was occupied succesfuly" << endl;
            return true;
        }
    }
    cout << "The settlement is not connected to any of the player's assets" << endl;
    return false;
}

bool Settlement::preOccupationAtempt(owner player) {
    if (this->getOwner() != EMPTY) {
        cout << "The settlement is already occupied" << endl;
        return false;
    }

    CatanObject** neighborhood = this->getNeighborhood();

    // Check if the adjacent settlements are empty
    for (int i = 0; i < 3; i++) {
        if (neighborhood[i] != nullptr && neighborhood[i]->getOwner() != EMPTY) {
            cout << "There is an adjacent settlement that is already occupied" << endl;
            return false;
        }
    }
    this->setOwner(player);
    cout << "Settlement " << this->getId() << " was occupied succesfuly" << endl;
    return true;
}
