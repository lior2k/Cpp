#include <string>
#include "Player.hpp"

namespace coup {
    class Captain : public Player {
        public:
            Captain(Game &game, const std::string &name);
            void steal(Player &p);
            static void block(Player &p);
    };

}
