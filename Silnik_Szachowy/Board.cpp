#include<iostream>
#include "Board.h"
#include "Pawn.h"
#include "Horse.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "EmptyFigure.h"

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

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
    BlackKing = _Board[0][4];
    WhiteKing = _Board[7][4];

    WhiteFigures.push_back(new Pawn(Position(6, 0), Color::white)); 
    WhiteFigures.push_back(new Pawn(Position(6, 1), Color::white));
    WhiteFigures.push_back(new Pawn(Position(6, 2), Color::white));
    WhiteFigures.push_back(new Pawn(Position(6, 3), Color::white));
    WhiteFigures.push_back(new Pawn(Position(6, 4), Color::white));
    WhiteFigures.push_back(new Pawn(Position(6, 5), Color::white));
    WhiteFigures.push_back(new Pawn(Position(6, 6), Color::white));
    WhiteFigures.push_back(new Pawn(Position(6, 7), Color::white));
    
    WhiteFigures.push_back(new Rook(Position(7, 0), Color::white));
    WhiteFigures.push_back(new Horse(Position(7, 1), Color::white));
    WhiteFigures.push_back(new Bishop(Position(7, 2), Color::white));
    WhiteFigures.push_back(new Queen(Position(7, 3), Color::white));
    WhiteFigures.push_back(new King(Position(7, 4), Color::white));
    WhiteFigures.push_back(new Bishop(Position(7, 5), Color::white));
    WhiteFigures.push_back(new Horse(Position(7, 6), Color::white));
    WhiteFigures.push_back(new Rook(Position(7, 7), Color::white));

    BlackFigures.push_back(new Pawn(Position(1, 0), Color::black));
    BlackFigures.push_back(new Pawn(Position(1, 1), Color::black));
    BlackFigures.push_back(new Pawn(Position(1, 2), Color::black));
    BlackFigures.push_back(new Pawn(Position(1, 3), Color::black));
    BlackFigures.push_back(new Pawn(Position(1, 4), Color::black));
    BlackFigures.push_back(new Pawn(Position(1, 5), Color::black));
    BlackFigures.push_back(new Pawn(Position(1, 6), Color::black));
    BlackFigures.push_back(new Pawn(Position(1, 7), Color::black));

    BlackFigures.push_back(new Rook(Position(0, 0), Color::black));
    BlackFigures.push_back(new Horse(Position(0, 1), Color::black));
    BlackFigures.push_back(new Bishop(Position(0, 2), Color::black));
    BlackFigures.push_back(new Queen(Position(0, 3), Color::black));
    BlackFigures.push_back(new King(Position(0, 4), Color::black));
    BlackFigures.push_back(new Bishop(Position(0, 5), Color::black));
    BlackFigures.push_back(new Horse(Position(0, 6), Color::black));
    BlackFigures.push_back(new Rook(Position(0, 7), Color::black));

    for (int i = 2; i < 6; i++) {
        for (int k = 0; k < 8; k++) {
            _Board[i][k] = new EmptyFigure(Position(i,k),Color::noColor);
        }
    }

    for (Figure* fig : WhiteFigures) {
        _Board[fig->Pos.x][fig->Pos.y] = fig;
    }
    for (Figure* fig : BlackFigures) {
        _Board[fig->Pos.x][fig->Pos.y] = fig;
    }

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
                if (_Board[i][j]->CanBeAttacked)std::cout << RED;
                

                if (_Board[i][j]->Type == king) std::cout << "K";
                else if (_Board[i][j]->Type == queen) std::cout << "Q";
                else if (_Board[i][j]->Type == bishop) std::cout << "B";
                else if (_Board[i][j]->Type == rook) std::cout << "R";
                else if (_Board[i][j]->Type == horse) std::cout << "H";
                else if (_Board[i][j]->Type == pawn) std::cout << "P"; 
                else if (_Board[i][j]->CanBeAttacked && _Board[i][j]->Type == none) std::cout << "X";
                else if (!_Board[i][j]->CanBeAttacked && _Board[i][j]->Type == none) std::cout << " ";
            }

            
            
            std::cout << RESET << " |";
        }
        std::cout<<std::endl << "  ";
        for (int k = 0; k < Size; k++) std::cout << " ---";
        std::cout << std::endl;
    }

}

void Board::DoMove(Position first,Position second) {
    _Board[second.x][second.y] = _Board[first.x][first.y];
    _Board[first.x][first.y] = new EmptyFigure(Position(first.x,first.y),Color::noColor);
    if (_Board[second.x][second.y] != nullptr) {
        _Board[second.x][second.y]->Pos.x = second.x;
        _Board[second.x][second.y]->Pos.y = second.y;
    }
}

void Board::ClearAttackedFields(std::list<Position> ListOfPositions) {
    for (Position pos : ListOfPositions) {
        _Board[pos.x][pos.y]->CanBeAttacked = false;
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
            _Board[Pos.x][Pos.y]->isCheckedByEnemy = true;
        }
        ClearAttackedFields(Positions);
    }

}

void Board::ClearCheckedFields(std::list<Figure*> Figures) {
    for (Figure* figure : Figures) {
        std::list<Position> Positions = figure->PossibleMoves(_Board, Size);
        figure->isZwiazany = false;
        for (Position Pos : Positions) {
            _Board[Pos.x][Pos.y]->isCheckedByEnemy = false;
        }
        ClearAttackedFields(Positions);
    }

}