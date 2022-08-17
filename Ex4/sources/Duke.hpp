#include <string>
#include "Player.hpp"

namespace coup {
    class Duke : public Player {
        public:
            Duke(Game &game, const std::string &name);
            void tax();
            static void block(Player &p);
    };

}
