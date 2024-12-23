#include <iostream>
#include "Board.h"

using namespace std;

void PodajKordy(Board* board) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    board->DoMove(Position(x1-1, y1-1), Position(x2-1, y2-1));

    board->DisplayBoard();
}

void WyswietlRuchy(Board* board) {
    int x1, y1;
    cin >> x1 >> y1;
    x1 = x1 - 1;
    y1 = y1 - 1;
    list<Position> tmp = board->_Board[x1][y1]->PossibleMoves(board->_Board, board->Size);
    for (Position pos : tmp) {
        cout << "Y: " << pos.x +1<< "  X: " << pos.y +1 << endl;
    }

    board->DisplayBoard();
    board->ClearAttackedFields(tmp);
}

void WybierzAkcje(Board* board) {
    cout << "Podaj akcje:\n1)Ruch\n2)Wyswietl Ruchy\n";
    int akcja;
    cin >> akcja;

    switch (akcja) {
    case 1:
        PodajKordy(board);
        break;
    case 2:
        WyswietlRuchy(board);
        break;
    default:
        break;
    }
}

int main()
{
    Board board = Board(8);
    board.DisplayBoard();
    while (true) {
        WybierzAkcje(&board);
    }


}


