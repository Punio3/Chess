#include <iostream>
#include "Board.h"

using namespace std;

void PodajKordy(Board* board) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    board->DoMove(Position(x1-1, y1-1), Position(x2-1, y2-1));
}

void WyswietlRuchy(Board* board) {
    int x1, y1;
    cin >> x1 >> y1;
    x1 = x1 - 1;
    y1 = y1 - 1;
    for (Position pos : board->_Board[x1][y1]->PossibleMoves(board->_Board, board->Size)) {
        cout << "Y: " << pos.x +1<< "  X: " << pos.y +1 << endl;
    }
}
int main()
{
    Board board = Board(8);
    while (true) {
        board.DisplayBoard();
        PodajKordy(&board);
        WyswietlRuchy(&board);
    }

}


