#include "Game.h"

class BoardView {
private:
    Game& game_;
public:
    explicit BoardView(Game& game) : game_(game) {}

    void draw() {
        Board& board = game_.board();

        for (int row=0; row<8; ++row) {
            for (int col=0; col<8; ++col) {
                uint8_t square = row*8 + col;
                const auto& figure = board.at({square});

                if (figure == nullptr) {
                    std::cout << ". ";
                } else {
                    std::cout << *figure << ' ';
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        std::cout << "a b c d e f g h\n";
    }
};
