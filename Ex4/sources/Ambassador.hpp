#include <string>
#include "Player.hpp"

namespace coup {
    class Ambassador : public Player {
        public:
            Ambassador(Game &game, const std::string &name);
            void transfer(Player &from, Player &to);
            static void block(Player &cpt);
    };
}
