#include <iostream>
#include<list>
#include "GameState.h"

GameState::GameState() {
	_Board = new Board(8);
	WhoMoves = Playerwhite;
    status = during;
    WhitePoints = 0;
    BlackPoints = 0;
}

GameState::GameState(Player whomoves, Board board) {
	_Board = &board;
	WhoMoves = whomoves;
    status = during;
    WhitePoints = 0;
    BlackPoints = 0;
}

GameState::GameState(int whitepoints ,int blackpoints ,Status Status, Player whomoves, Board* board) {
    _Board = board;
    WhoMoves = whomoves;
    status = Status;
    WhitePoints = whitepoints;
    BlackPoints = blackpoints;
}

GameState::~GameState() {
    delete(_Board);
}
void GameState::ChangeWhoMoves() {
	if (WhoMoves == Playerblack) WhoMoves = Playerwhite;
	else WhoMoves = Playerblack;
}

void GameState::MakeMove() {
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    if (_Board->FigureWithShowedMoves != nullptr) {
        _Board->ClearAttackedFields(_Board->PossibleMovesForFigure(_Board->FigureWithShowedMoves, WhoMoves), _Board->FigureWithShowedMoves->FigureColor);
        _Board->FigureWithShowedMoves == nullptr;
    }

    if (WhoMoves == white) {
        _Board->ClearCheckedFields(_Board->BlackFigures);
        //usuniecie figury z listy
        if (_Board->_Board[x2 - 1][y2 - 1]->Type != none) {
            _Board->BlackFigures.remove(_Board->_Board[x2 - 1][y2 - 1]);
            WhitePoints += _Board->_Board[x2 - 1][y2 - 1]->ValueInPoints;
        }
        if (_Board->WhiteKing->isChecked) {
            _Board->WhiteKing->isChecked = false;
            _Board->WhiteKing->AttackedMovesWhenIsZwiazany.clear();
        }
        _Board->_Board[x1 - 1][y1 - 1]->MakeMove(_Board->_Board, Position(x2 - 1, y2 - 1));
        _Board->CheckIfPawnCanTransform(Position(x2 - 1, y2 - 1));
        _Board->AddCheckedFields(_Board->WhiteFigures);
    }
    else {
        _Board->ClearCheckedFields(_Board->WhiteFigures);
        //usuniecie figury z listy
        if (_Board->_Board[x2 - 1][y2 - 1]->Type != none) {
            _Board->WhiteFigures.remove(_Board->_Board[x2 - 1][y2 - 1]);
           BlackPoints += _Board->_Board[x2 - 1][y2 - 1]->ValueInPoints;
        }
        if (_Board->BlackKing->isChecked) {
            _Board->BlackKing->isChecked = false;
            _Board->BlackKing->AttackedMovesWhenIsZwiazany.clear();
        }
        _Board->_Board[x1 - 1][y1 - 1]->MakeMove(_Board->_Board, Position(x2 - 1, y2 - 1));
        _Board->CheckIfPawnCanTransform(Position(x2 - 1, y2 - 1));
        _Board->AddCheckedFields(_Board->BlackFigures);
    }

    ChangeWhoMoves();
    CheckPatAndMat();
    _Board->DisplayBoard(WhoMoves, WhitePoints, BlackPoints);
}

void GameState::ShowMoves() {
    int x1, y1;

    std::cin >> x1 >> y1;
    x1 = x1 - 1;
    y1 = y1 - 1;

    //std::list<Position> tmp = _Board->_Board[x1][y1]->PossibleMoves(_Board->_Board, _Board->Size);

    if (_Board->FigureWithShowedMoves != nullptr) {
        _Board->ClearAttackedFields(_Board->PossibleMovesForFigure(_Board->FigureWithShowedMoves,WhoMoves), _Board->FigureWithShowedMoves->FigureColor);
        _Board->FigureWithShowedMoves = _Board->_Board[x1][y1];
        _Board->AddAttackedFields(_Board->PossibleMovesForFigure(_Board->FigureWithShowedMoves, WhoMoves), _Board->FigureWithShowedMoves->FigureColor);
    }
    else {
        _Board->FigureWithShowedMoves = _Board->_Board[x1][y1];
        _Board->AddAttackedFields(_Board->PossibleMovesForFigure(_Board->FigureWithShowedMoves, WhoMoves), _Board->FigureWithShowedMoves->FigureColor);
    }
/*
    for (Position pos : tmp) {
        std::cout << "Y: " << pos.x + 1 << "  X: " << pos.y + 1 <<std::endl;
    }
    */

    _Board->DisplayBoard(WhoMoves, WhitePoints, BlackPoints);
}

void GameState::CheckPatAndMat() {
    if (WhoMoves == Playerwhite) {
        for (Figure* fig : _Board->WhiteFigures) {
            std::list<Position> ListOfMoves = _Board->PossibleMovesForFigure(fig, WhoMoves);
            //figura sprawdzajac swoje ruchy dodaje tez sojusznicze figury gdyz pozniej zaznaczane sa one jako chronione, aby krol ich nie mogl zniszczyc
            //dlatego tutaj sprawdzam czy w liscie ruchow nie ma sojuszniczych figur, a jak sa to je igonruje
            if (ListOfMoves.size() != 0) {
                for (Position Pos : ListOfMoves) {
                    if (_Board->_Board[Pos.x][Pos.y]->FigureColor != fig->FigureColor) return;
                }
            }
        }

        if (_Board->WhiteKing->isChecked) {
            std::cout << "Czarne wygraly przez mata" << std::endl;
            status = mat;
        }
        else {
            std::cout << "Remis przez pata" << std::endl;
            status = pat;
        }
    }
    else {
        for (Figure* fig : _Board->BlackFigures) {
            std::list<Position> ListOfMoves = _Board->PossibleMovesForFigure(fig, WhoMoves);
            //figura sprawdzajac swoje ruchy dodaje tez sojusznicze figury gdyz pozniej zaznaczane sa one jako chronione, aby krol ich nie mogl zniszczyc
            //dlatego tutaj sprawdzam czy w liscie ruchow nie ma sojuszniczych figur, a jak sa to je igonruje
            if (ListOfMoves.size() != 0) {
                for (Position Pos : ListOfMoves) {
                    if (_Board->_Board[Pos.x][Pos.y]->FigureColor != fig->FigureColor) return;
                }
            }            
        }

        if (_Board->BlackKing->isChecked) {
            std::cout << "Biale wygraly przez mata"<<std::endl;
            status = mat;
        }
        else {
            std::cout << "Remis przez pata" << std::endl;
            status = pat;
        }
    }
}

void GameState::CreateNewBoard() {
    delete _Board;
    _Board= new Board(8);
    WhoMoves = Playerwhite;
    status = during;
}

GameState* GameState::copyGameState() {
    GameState* newGameState = new GameState(WhitePoints ,BlackPoints ,status, WhoMoves, _Board->copyBoard());
    return newGameState;
}

int GameState::OcenaHeurstycznaStanu() {
    int Suma = 0;
    if (WhoMoves == Playerwhite) {
        if (status == mat) {
            if (_Board->BlackKing->isChecked == true) {
                Suma += 10000;
                return Suma;
            }
            else {
                Suma = 0;
                return Suma;
            }
        }
        else {

        }
    }
    else {
        if (status == mat) {
            if (_Board->WhiteKing->isChecked == true) {
                Suma += 10000;
                return Suma;
            }
            else {
                Suma = 0;
                return Suma;
            }
        }
        else {

        }
    }

}