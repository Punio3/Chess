#include<iostream>
#include "Board.h"
#include "Pawn.h"
#include "Horse.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "EmptyFigure.h"

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define YELLOW "\033[33m"

Board::Board() {
    Size = 8;
    _Board = new Figure * *[Size];
    for (int i = 0; i < Size; i++) {
        _Board[i] = new Figure * [Size];
        for (int j = 0; j < Size; j++) {
            _Board[i][j] = nullptr;
        }
    }
    InitializeBoard();
}

Board::Board(int size) : Size(size) {
    _Board = new Figure * *[Size];
    for (int i = 0; i < Size; i++) {
        _Board[i] = new Figure * [Size];
        for (int j = 0; j < Size; j++) {
            _Board[i][j] = nullptr;  
        }
    }

    InitializeBoard();  
}

void Board::InitializeBoard() {
    FigureWithShowedMoves = nullptr;

    for (int i = 0; i < 8; ++i) {
        _Board[6][i] = new Pawn(Position(6, i), Color::white);
        WhiteFigures.push_back(_Board[6][i]);
    }

    _Board[7][0] = new Rook(Position(7, 0), Color::white);
    _Board[7][1] = new Horse(Position(7, 1), Color::white);
    _Board[7][2] = new Bishop(Position(7, 2), Color::white);
    _Board[7][3] = new Queen(Position(7, 3), Color::white);
    _Board[7][4] = new King(Position(7, 4), Color::white);
    _Board[7][5] = new Bishop(Position(7, 5), Color::white);
    _Board[7][6] = new Horse(Position(7, 6), Color::white);
    _Board[7][7] = new Rook(Position(7, 7), Color::white);


    for (int i = 0; i < 8; ++i) {
        WhiteFigures.push_back(_Board[7][i]);
    }

    for (int i = 0; i < 8; ++i) {
        _Board[1][i] = new Pawn(Position(1, i), Color::black);
        BlackFigures.push_back(_Board[1][i]);
    }


    _Board[0][0] = new Rook(Position(0, 0), Color::black);
    _Board[0][1] = new Horse(Position(0, 1), Color::black);
    _Board[0][2] = new Bishop(Position(0, 2), Color::black);
    _Board[0][3] = new Queen(Position(0, 3), Color::black);
    _Board[0][4] = new King(Position(0, 4), Color::black);
    _Board[0][5] = new Bishop(Position(0, 5), Color::black);
    _Board[0][6] = new Horse(Position(0, 6), Color::black);
    _Board[0][7] = new Rook(Position(0, 7), Color::black);


    for (int i = 0; i < 8; ++i) {
        BlackFigures.push_back(_Board[0][i]);
    }

    for (int i = 2; i < 6; i++) {
        for (int k = 0; k < 8; k++) {
            _Board[i][k] = new EmptyFigure(Position(i, k), Color::noColor);
        }
    }
    BlackKing = dynamic_cast<King*>(_Board[0][4]);
    WhiteKing = dynamic_cast<King*>(_Board[7][4]);
}

Board::~Board() {
    for (Figure* figure : WhiteFigures) {
        delete figure;
    }
    WhiteFigures.clear();

    for (Figure* figure : BlackFigures) {
        delete figure;
    }
    BlackFigures.clear();

    if (_Board != nullptr) {
        for (int i = 0; i < Size; ++i) {
            delete[] _Board[i]; 
        }
        delete[] _Board;
    }
}


void Board::DisplayBoard(Player player) {
    if (player == Playerwhite) {
        std::cout << "Ruch bialego\n";
    }
    else {
        std::cout << BLUE << "Ruch czarnego\n"<<RESET;
    }
    std::cout << " ";
    for (int k = 0; k < Size; k++) std::cout << "   "<<k+1;
    std::cout << std::endl;

    std::cout << "  ";
    for (int k = 0; k < Size; k++) std::cout << " ---";
    std::cout << std::endl;

    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (j == 0) {
                std::cout << i+1<<" |";
            }
            if (_Board[i][j] != nullptr) {
                std::cout << " ";
                if (_Board[i][j]->FigureColor == black) std::cout << BLUE;
               //if (_Board[i][j]->isCheckedByBlack || _Board[i][j]->isCheckedByWhite)std::cout << YELLOW;
                if (_Board[i][j]->isZwiazany)std::cout << YELLOW;
                if (_Board[i][j]->CanBeAttacked)std::cout << RED;

                if (_Board[i][j]->Type == king) std::cout << "K";
                else if (_Board[i][j]->Type == queen) std::cout << "Q";
                else if (_Board[i][j]->Type == bishop) std::cout << "B";
                else if (_Board[i][j]->Type == rook) std::cout << "R";
                else if (_Board[i][j]->Type == horse) std::cout << "H";
                else if (_Board[i][j]->Type == pawn) std::cout << "P"; 
                else if (_Board[i][j]->CanBeAttacked && _Board[i][j]->Type == none) std::cout << "X";
              //  else if ((_Board[i][j]->isCheckedByBlack || _Board[i][j]->isCheckedByWhite) && _Board[i][j]->Type == none) std::cout << "#";
                else if (!_Board[i][j]->CanBeAttacked && _Board[i][j]->Type == none) std::cout << " ";
            }

            
            
            std::cout << RESET << " |";
        }
        std::cout<<std::endl << "  ";
        for (int k = 0; k < Size; k++) std::cout << " ---";
        std::cout << std::endl;
    }

}


void Board::AddCheckedFields(std::list<Figure*> Figures) {
    for (Figure* figure : Figures) {
        std::list<Position> Positions;
        if (figure->Type != pawn) Positions = figure->PossibleMoves(_Board, Size);
        else {
            Pawn* pawn = dynamic_cast<Pawn*>(figure);
            if (pawn) {
                Positions = pawn->CheckedFields(_Board, Size);
            }
        }

        for (Position Pos : Positions) {
            if(figure->FigureColor==white) _Board[Pos.x][Pos.y]->isCheckedByWhite = true;
            if (figure->FigureColor == black) _Board[Pos.x][Pos.y]->isCheckedByBlack = true;
        }
    }

}

void Board::ClearCheckedFields(std::list<Figure*> Figures) {
    for (Figure* figure : Figures) {

        std::list<Position> Positions;
        if (figure->Type != pawn) Positions = figure->PossibleMoves(_Board, Size);
        else {
            Pawn* pawn = dynamic_cast<Pawn*>(figure);
            if (pawn) {
                Positions = pawn->CheckedFields(_Board, Size);
            }
        }

        for (Position Pos : Positions) {
            if (figure->FigureColor == white) _Board[Pos.x][Pos.y]->isCheckedByWhite = false;
            if (figure->FigureColor == black) _Board[Pos.x][Pos.y]->isCheckedByBlack = false;

            if (_Board[Pos.x][Pos.y]->isZwiazany) {
                _Board[Pos.x][Pos.y]->isZwiazany = false;
                _Board[Pos.x][Pos.y]->AttackedMovesWhenIsZwiazany.clear();
            }
        }
    }
}

void Board::ClearAttackedFields(std::list<Position> ListOfPositions, Color color) {
    for (Position Pos : ListOfPositions) {
        if (_Board[Pos.x][Pos.y]->FigureColor != color) {
            _Board[Pos.x][Pos.y]->CanBeAttacked = false;

            if (_Board[Pos.x][Pos.y]->isZwiazany) {
                _Board[Pos.x][Pos.y]->isZwiazany = false;
                _Board[Pos.x][Pos.y]->AttackedMovesWhenIsZwiazany.clear();
            }
        }
    }
}

void Board::AddAttackedFields(std::list<Position> ListOfPositions, Color color) {
    for (Position Pos : ListOfPositions) {
        if (_Board[Pos.x][Pos.y]->FigureColor != color) {
            _Board[Pos.x][Pos.y]->CanBeAttacked = true;

            if (_Board[Pos.x][Pos.y]->isZwiazany) {
                _Board[Pos.x][Pos.y]->isZwiazany = false;
                _Board[Pos.x][Pos.y]->AttackedMovesWhenIsZwiazany.clear();
            }
        }
    }
}

std::list<Position> Board::PossibleMovesForFigure(Figure* _Figure, Player whoMoves) {
    if (whoMoves == Playerwhite) {
        if (WhiteKing->isChecked && _Figure->Type!=king) {
            return(_Figure->GiveListOfDuplicateFields(_Figure->PossibleMoves(_Board, Size), WhiteKing->AttackedMovesWhenIsZwiazany));
        }
        else {
            return _Figure->PossibleMoves(_Board, Size);
        }
    }
    else {
        if (BlackKing->isChecked && _Figure->Type != king) {
            return(_Figure->GiveListOfDuplicateFields(_Figure->PossibleMoves(_Board, Size), BlackKing->AttackedMovesWhenIsZwiazany));
        }
        else {
            return _Figure->PossibleMoves(_Board, Size);
        }
    }
}

void Board::CheckIfPawnCanTransform(Position second) {
    if (_Board[second.x][second.y]->Type == pawn) {
        if (_Board[second.x][second.y]->FigureColor == white) {
            if (second.x == 0) {
                std::cout << "Podaj nowa figure za pionka\n1)horse\n2)bishop\n3)queen\n4)rook\n";
                WhiteFigures.remove(_Board[second.x][second.y]);
                delete(_Board[second.x][second.y]);
                int choice;
                std::cin >> choice;
                switch (choice) {
                case 1: 
                    _Board[second.x][second.y] = new Horse(Position(second.x, second.y), Color::white);
                    break;
                case 2: 
                    _Board[second.x][second.y] = new Bishop(Position(second.x, second.y), Color::white);
                    break;
                case 3:
                    _Board[second.x][second.y] = new Queen(Position(second.x, second.y), Color::white);
                    break;
                case 4:
                    _Board[second.x][second.y] = new Rook(Position(second.x, second.y), Color::white);
                    break;
                }
                WhiteFigures.push_back(_Board[second.x][second.y]);
            }
        }
        else {
            if (second.x == 7) {
                std::cout << "Podaj nowa figure za pionka\n1)horse\n2)bishop\n3)queen\n4)rook\n";
                BlackFigures.remove(_Board[second.x][second.y]);
                delete(_Board[second.x][second.y]);
                int choice;
                std::cin >> choice;
                switch (choice) {
                case 1: 
                    _Board[second.x][second.y] = new Horse(Position(second.x, second.y), Color::black);
                    break;
                case 2: 
                    _Board[second.x][second.y] = new Bishop(Position(second.x, second.y), Color::black);
                    break;
                case 3: 
                    _Board[second.x][second.y] = new Queen(Position(second.x, second.y), Color::black);
                    break;
                case 4: 
                    _Board[second.x][second.y] = new Rook(Position(second.x, second.y), Color::black);
                    break;
                }
                BlackFigures.push_back(_Board[second.x][second.y]);
            }
        }
    }
}