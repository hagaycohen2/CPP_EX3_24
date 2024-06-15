#include "CatanGame.hpp"

int main() {
    cout << "Welcome to Catan!" << endl;
    cout << "This will be a demo of one round of the game" << endl;
    cout << "If you want to play the full game, please run `make run`" << endl;
    CatanGame game;
    game.demo();

    return 0;
}
