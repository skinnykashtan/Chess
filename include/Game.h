//
// Created by Hubert on 27.07.2026.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include "Board.h"

class Game {
private:
    Board board_{};
public:
    Game() {
        board().setupStartingPosition();
    }

    Board& board();

    void newGame();
};

#endif //CHESS_GAME_H
