#include "Duke.hpp"
using namespace coup;

Duke::Duke(Game &game, const std::string &name): Player(game, name){setRole("Duke");};

void Duke::tax() {
    if (this->game->currentTurn != this->playerID) {
        throw "not your turn";
    }
    if (this->myCoins >= MUST_COUP) {
        throw "must coup at 10 or more coins";
    }
    myCoins += 3;
    setLastAction("tax");
    setActionOn(NULL);
    this->game->finishTurn();
}

void Duke::block(Player &p) {
    if (p.getLastAction() != "foreign aid") {
        throw "last action was not foreign aid";
    }
    p.myCoins -= 2;
}
