#include <iostream>
#include<list>
#include "GameState.h"

GameState::GameState() {
	_Board = new Board(8);
	WhoMoves = Playerwhite;
}

GameState::GameState(Player whomoves, Board board) {
	_Board = &board;
	WhoMoves = whomoves;
}

void GameState::ChangeWhoMoves() {
	if (WhoMoves == Playerblack) WhoMoves = Playerwhite;
	else WhoMoves = Playerblack;
}

void GameState::MakeMove() {
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    _Board->ClearCheckedFieldsForOneFigure(_Board->_Board[x1 - 1][y1 - 1]);//to mozliwe niepotrzbene
    if (_Board->FigureWithShowedMoves != nullptr) {
        _Board->ClearAttackedFields(_Board->FigureWithShowedMoves->PossibleMoves(_Board->_Board, _Board->Size));
    }

    if (WhoMoves == white) {
        _Board->ClearCheckedFields(_Board->BlackFigures);
        _Board->_Board[x1 - 1][y1 - 1]->MakeMove(_Board->_Board, Position(x2 - 1, y2 - 1));
        _Board->AddCheckedFields(_Board->WhiteFigures);
    }
    else {
        _Board->ClearCheckedFields(_Board->WhiteFigures);
        _Board->_Board[x1 - 1][y1 - 1]->MakeMove(_Board->_Board, Position(x2 - 1, y2 - 1));
        _Board->AddCheckedFields(_Board->BlackFigures);
    }
    ChangeWhoMoves();

    _Board->DisplayBoard(WhoMoves);
}

void GameState::ShowMoves() {
    int x1, y1;
    std::cin >> x1 >> y1;
    x1 = x1 - 1;
    y1 = y1 - 1;
    std::list<Position> tmp = _Board->_Board[x1][y1]->PossibleMoves(_Board->_Board, _Board->Size);
    if (_Board->FigureWithShowedMoves != nullptr) {
        _Board->ClearAttackedFields(_Board->FigureWithShowedMoves->PossibleMoves(_Board->_Board, _Board->Size));
        _Board->FigureWithShowedMoves = _Board->_Board[x1][y1];
        _Board->AddAttackedFields(_Board->FigureWithShowedMoves->PossibleMoves(_Board->_Board, _Board->Size));
    }
    else {
        _Board->FigureWithShowedMoves = _Board->_Board[x1][y1];
        _Board->AddAttackedFields(_Board->FigureWithShowedMoves->PossibleMoves(_Board->_Board, _Board->Size));
    }

    for (Position pos : tmp) {
        std::cout << "Y: " << pos.x + 1 << "  X: " << pos.y + 1 <<std::endl;
    }

    _Board->DisplayBoard(WhoMoves);
}