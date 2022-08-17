#include <string>
#include <vector>
const int MAX_PLAYERS = 6;
#pragma once

namespace coup {

    class Game {
        private:
            std::vector<std::string> allPlayers;
            std::vector<std::string> alivePlayers;
            std::vector<std::string> deadPlayers;
            std::string myWinner;
        public:
            int status = 1; // 1 didnt start, 2 game started, 0 game ended
            unsigned int numOfPlayers;
            unsigned int currentTurn;
            Game();
            std::vector<std::string> players();
            std::string turn();
            std::string winner();

            void addPlayer(const std::string &p);
            void ressurect(const unsigned int playerID);
            void kill(const unsigned int playerID);
            bool isAlive(const unsigned int index);
            void checkWin();
            void finishTurn();
    };

}
