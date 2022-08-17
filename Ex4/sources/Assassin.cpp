#include "Assassin.hpp"
using namespace coup;

Assassin::Assassin(Game &game, const std::string &name): Player(game, name){setRole("Assassin");};

void Assassin::coup(Player &p) {
    if (this->game->currentTurn != this->playerID) {
        throw "not your turn";
    }
    if (this->myCoins < ASSASSIN_COUP_COST) {
        throw ("Not enough money to perform assasination");
    }
    if (!p.isAlive) {
        throw "player already died";
    }
    if (this->myCoins >= ASSASSIN_COUP_COST and this->myCoins < COUP_COST) {
        this->myCoins -= ASSASSIN_COUP_COST;
        setLastAction("assassinate");
    }
    if (this->myCoins >= COUP_COST) {
        this->myCoins -= COUP_COST;
        setLastAction("coup");
    }
    p.isAlive = false;
    this->game->kill(p.playerID);
    setActionOn(&p);
    this->game->finishTurn();
    this->game->checkWin();
}