#include "Road.hpp"

void Road::load(int road_id, owner owner, CatanObject* neighborhood[6]) {
    this->setId(road_id);
    this->setOwner(owner);
    this->setNeighborhood(neighborhood);
}

bool Road::occupationAtempt(owner player) {
    if (this->getOwner() != NONE) {
        return false;
    }

    CatanObject** neighborhood = this->getNeighborhood();

    // Check if at least one of the adjacent settlements is owned by the player
    if (neighborhood[0]->getOwner() == player) {
        this->setOwner(player);
        return true;
    }
    if (neighborhood[1]->getOwner() == player) {
        this->setOwner(player);
        return true;
    }

    // if none of the adjacent settlements are owned by the player,
    // check if at least one of the adjacent roads is owned by the player and the settlement between them is empty
    if (neighborhood[0]->getOwner() == NONE) {
        if (neighborhood[2] != nullptr && neighborhood[2]->getOwner() == player) {
            this->setOwner(player);
            return true;
        }
        if (neighborhood[3] != nullptr && neighborhood[3]->getOwner() == player) {
            this->setOwner(player);
            return true;
        }
    }
    if (neighborhood[1]->getOwner() == NONE) {
        if (neighborhood[4] != nullptr && neighborhood[4]->getOwner() == player) {
            this->setOwner(player);
            return true;
        }
        if (neighborhood[5] != nullptr && neighborhood[5]->getOwner() == player) {
            this->setOwner(player);
            return true;
        }
    }

    return false;
}