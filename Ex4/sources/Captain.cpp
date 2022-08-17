#include "Captain.hpp"
using namespace coup;

Captain::Captain(Game &game, const std::string &name): Player(game, name){setRole("Captain");};

void Captain::steal(Player &p) {
    if (this->game->currentTurn != this->playerID) {
        throw "not your turn";
    }
    if (this->myCoins >= MUST_COUP) {
        throw "must coup at 10 or more coins";
    }
    if (p.myCoins == 0) {
        return;
    }
    if (p.myCoins == 1) {
        p.myCoins--;
        this->myCoins++;
    } else {
        p.myCoins -= 2;
        this->myCoins += 2;
    }
    setLastAction("steal");
    setActionOn(&p);
    this->game->finishTurn();
}

void Captain::block(Player &p) {
    if (p.getLastAction() != "steal") {
        throw "last action was not steal";
    }
    Player *pfrom = p.getActionOn();
    if (pfrom != NULL) {
        p.myCoins -= 2;
        pfrom->myCoins += 2;
    } 
}
