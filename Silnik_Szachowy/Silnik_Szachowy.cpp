#include <iostream>
#include "Board.h"

using namespace std;


int main()
{
    Board board = Board(8);
    board.DisplayBoard();
    board.DoMove(Position(0, 1), Position(3, 3));
    board.DisplayBoard();

}


