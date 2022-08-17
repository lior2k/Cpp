#include "Player.hpp"
using namespace coup;

Player::Player(Game &game, const std::string &name) {
    this->playerID = game.numOfPlayers;
    this->myName = name;
    this->game = &game;
    this->game->addPlayer(name);
    this->lastAction = "";
    this->actionOn = NULL;
}

void Player::income() {
    if (this->game->currentTurn != this->playerID) {
        throw "not your turn";
    }
    if (this->game->numOfPlayers <= 1) {
        throw "not enough players";
    }
    if (this->myCoins >= MUST_COUP) {
        throw "must coup at 10 or more coins";
    }
    if (this->game->status == 1) {
        this->game->status = 2;
    }
    myCoins++;
    lastAction = "income";
    actionOn = NULL;
    this->game->finishTurn();
}

void Player::foreign_aid() {
    if (this->game->currentTurn != this->playerID) {
        throw "not your turn";
    }
    if (this->game->numOfPlayers <= 1) {
        throw "not enough players";
    }
    if (this->myCoins >= MUST_COUP) {
        throw "must coup at 10 or more coins";
    }
    if (this->game->status == 1) {
        this->game->status = 2;
    }
    myCoins += 2;
    lastAction = "foreign aid";
    actionOn = NULL;
    this->game->finishTurn();
}

void Player::coup(Player &p) {
    if (this->game->currentTurn != this->playerID) {
        throw "not your turn";
    }
    if (this->myCoins < COUP_COST) {
        throw "Not enough coins to perform coup";
    }
    if (!p.isAlive) {
        throw "player already died";
    }
    p.isAlive = false;
    this->myCoins -= COUP_COST;
    this->game->kill(p.playerID);
    setLastAction("coup");
    setActionOn(&p);
    this->game->finishTurn();
    this->game->checkWin();
}

int Player::coins() const {
    return this->myCoins;
}

std::string Player::role() const {
    return this->myRole;
}

std::string Player::name() const {
    return this->myName;
}

std::string Player::getLastAction() const {
    return this->lastAction;
}

Player* Player::getActionOn() {
    return this->actionOn;
}

void Player::setRole(const std::string &role) {
    this->myRole = role;
}

void Player::setLastAction(const std::string &action) {
    this->lastAction = action;
}

void Player::setActionOn(Player *p) {
    this->actionOn = p;
}