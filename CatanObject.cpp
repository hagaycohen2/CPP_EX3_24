#include "CatanObject.hpp"

 void CatanObject:: setNeighborhood(CatanObject* neighborhood[6]) {
        for (int i = 0; i < 6; i++) {
            this->neighborhood[i] = neighborhood[i];
        }
    }

string CatanObject:: getColor() {
    switch (this->objowner) {
        case YELLOW:
            return "\033[1;33m";
        case BLUE:
            return "\033[1;34m";
        case RED:
            return "\033[1;31m";
        default:
            return "\033[0m";
    }
}