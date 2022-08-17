#include "string"
#include "Game.hpp"
const int ASSASSIN_COUP_COST = 3;
const int COUP_COST = 7;
const int MUST_COUP = 10;
#pragma once

namespace coup {

    class Player {
        protected:
            Game *game;
        private:
            std::string myRole;
            std::string myName;
            std::string lastAction;
            Player *actionOn;
        public:
            bool isAlive = 1;
            int myCoins = 0;
            unsigned int playerID;
            Player(Game &game, const std::string &name);
            int coins() const;
            std::string role() const;
            std::string name() const;
            std::string getLastAction() const;
            Player* getActionOn();
            void setRole(const std::string &role);
            void setLastAction(const std::string &action);
            void setActionOn(Player *p);

            void income();
            void foreign_aid();
            void coup(Player &p);
            
    };

}
