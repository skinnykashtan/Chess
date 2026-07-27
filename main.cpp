#include <iostream>

#include "Game.h"
#include "ui/BoardView.cpp"


int main() {

    Game game{};
    BoardView view{game};

    view.draw();

    return 0;
}
