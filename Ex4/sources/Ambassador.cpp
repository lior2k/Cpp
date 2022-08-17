#include "Ambassador.hpp"
using namespace coup;

Ambassador::Ambassador(Game &game, const std::string &name): Player(game, name){setRole("Ambassador");};

void Ambassador::transfer(Player &from, Player &to) {
    if (this->game->currentTurn != this->playerID) {
        throw "not your turn";
    }
    if (this->myCoins >= MUST_COUP) {
        throw "must coup at 10 or more coins";
    }
    if (from.myCoins == 0) {
        throw "cant transfer from player with 0 coins";
    }
    from.myCoins--;
    to.myCoins++;
    this->game->finishTurn();
}

void Ambassador::block(Player &cpt) {
    if (cpt.getLastAction() != "steal") {
        throw "last action was not steal";
    }
    Player *p = cpt.getActionOn();
    if (p != NULL) {
        cpt.myCoins -= 2;
        p->myCoins += 2;
    }
}