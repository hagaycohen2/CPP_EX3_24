#include "Settlement.hpp"

void Settlement::load(int id, owner objowner, CatanObject* neighborhood[6], pair<int, resource> resources[3]) {
    this->setId(id);
    this->setOwner(objowner);
    this->setNeighborhood(neighborhood);
    for (int i = 0; i < 3; i++) {
        this->resources[i] = resources[i];
    }
    this->isCity = false;
}

bool Settlement::occupationAtempt(owner player) {
    if (this->getOwner() != NONE) {
        return false;
    }
    
    CatanObject** neighborhood = this->getNeighborhood();

    // Check if the adjacent settlements are empty
    for (int i = 0; i < 3; i++) {
        if (neighborhood[i] != nullptr && neighborhood[i]->getOwner() != NONE) {
            return false;
        }
    }

    // Check if at least one of the adjacent roads is owned by the player
    for (int i = 3; i < 6; i++) {
        if (neighborhood[i] != nullptr && neighborhood[i]->getOwner() == player) {
            this->setOwner(player);
            return true;
        }
    }
    return false;
}
