#include "Game.h"

Board& Game::board() {
    return board_;
}

void Game::newGame() {
    board_.setupStartingPosition();
}
