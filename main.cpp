/**
 * Authors: Hagay Cohen
 * Email: hagaycohen2@gmail.com
 */

#include "CatanGame.hpp"

int main() {
    cout << "Welcome to Catan!" << endl;
    cout << "This will be a demo of one round of the game" << endl;
    cout << "If you want to play the full game, please run `make run`\n" << endl;
    CatanGame game;
    game.demo();
    cout << "demo finished" << endl;
    cout << "for full game run `make run`" << endl;
    cout << "Goodbye!" << endl;
    return 0;
}
