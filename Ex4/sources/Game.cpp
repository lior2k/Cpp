#include "Game.hpp"
#include <iostream>
using namespace coup;

Game::Game() {
    numOfPlayers = 0;
    currentTurn = 0;
}

std::vector<std::string> Game::players() {
    return this->alivePlayers;
}

std::string Game::turn() {
    return alivePlayers[currentTurn];
}
            
std::string Game::winner() {
    if (status != 0) {
        throw "Game is still running!";
    }
    return this->myWinner;
}

void Game::addPlayer(const std::string &p) {
    if (numOfPlayers == MAX_PLAYERS) {
        throw std::logic_error("game is full");
    }
    if (status == 2) {
        throw "game already started";
    }
    this->numOfPlayers++;
    this->alivePlayers.push_back(p);
    this->allPlayers.push_back("alive");
}

void Game::ressurect(const unsigned int playerID) {
    this->allPlayers[playerID] = "alive";
    this->alivePlayers.insert(alivePlayers.begin() + playerID, deadPlayers[playerID]);
    this->deadPlayers[playerID] = "";
}

void Game::kill(const unsigned int playerID) {
    if (this->deadPlayers.size() <= playerID) {
        this->deadPlayers.resize(playerID + 1);
    }
    this->deadPlayers[playerID] = this->alivePlayers[playerID];
    this->alivePlayers.erase(alivePlayers.begin() + playerID);

    this->allPlayers[playerID] = "dead";
}

bool Game::isAlive(const unsigned int index) {
    return !(this->allPlayers[index] == "dead");
}

void Game::checkWin() {
    if (alivePlayers.size() == 1) {
        status = 0;
        myWinner = alivePlayers[0];
    }
}

void Game::finishTurn() {
    currentTurn++;
    if (currentTurn == allPlayers.size()) {
        currentTurn = 0;
    }

    while (!isAlive(currentTurn)) {
        currentTurn++;
        if (currentTurn == allPlayers.size()) {
            currentTurn = 0;
        }
    }
}