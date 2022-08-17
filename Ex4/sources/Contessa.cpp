#include "Contessa.hpp"
using namespace coup;

Contessa::Contessa(Game &game, const std::string &name): Player(game, name){setRole("Contessa");};

void Contessa::block(Player &p) {
    if (p.getLastAction() != "assassinate") {
        throw "last action was not assassinate";
    }
    game->ressurect(p.getActionOn()->playerID);
    p.getActionOn()->isAlive = true;
}