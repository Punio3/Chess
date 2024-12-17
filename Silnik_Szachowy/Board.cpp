#include<iostream>
#include "Board.h"
#include "Pawn.h"
#include "Horse.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

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
    WhiteFigures.push_back(new Pawn(Position(1, 0))); 
    WhiteFigures.push_back(new Pawn(Position(1, 1))); 
    WhiteFigures.push_back(new Pawn(Position(1, 2))); 
    WhiteFigures.push_back(new Pawn(Position(1, 3)));  
    WhiteFigures.push_back(new Pawn(Position(1, 4)));  
    WhiteFigures.push_back(new Pawn(Position(1, 5))); 
    WhiteFigures.push_back(new Pawn(Position(1, 6)));  
    WhiteFigures.push_back(new Pawn(Position(1, 7)));  
    
    WhiteFigures.push_back(new Rook(Position(0, 0)));
    WhiteFigures.push_back(new Horse(Position(0, 1)));
    WhiteFigures.push_back(new Bishop(Position(0, 2)));
    WhiteFigures.push_back(new Queen(Position(0, 3)));
    WhiteFigures.push_back(new King(Position(0, 4)));
    WhiteFigures.push_back(new Bishop(Position(0, 5)));
    WhiteFigures.push_back(new Horse(Position(0, 6)));
    WhiteFigures.push_back(new Rook(Position(0, 7)));

    BlackFigures.push_back(new Pawn(Position(6, 0)));
    BlackFigures.push_back(new Pawn(Position(6, 1)));
    BlackFigures.push_back(new Pawn(Position(6, 2)));
    BlackFigures.push_back(new Pawn(Position(6, 3)));
    BlackFigures.push_back(new Pawn(Position(6, 4)));
    BlackFigures.push_back(new Pawn(Position(6, 5)));
    BlackFigures.push_back(new Pawn(Position(6, 6)));
    BlackFigures.push_back(new Pawn(Position(6, 7)));

    BlackFigures.push_back(new Rook(Position(7, 0)));
    BlackFigures.push_back(new Horse(Position(7, 1)));
    BlackFigures.push_back(new Bishop(Position(7, 2)));
    BlackFigures.push_back(new Queen(Position(7, 3)));
    BlackFigures.push_back(new King(Position(7, 4)));
    BlackFigures.push_back(new Bishop(Position(7, 5)));
    BlackFigures.push_back(new Horse(Position(7, 6)));
    BlackFigures.push_back(new Rook(Position(7, 7)));


    for (Figure* fig : WhiteFigures) {
        _Board[fig->Pos.x][fig->Pos.y] = fig;
    }
    for (Figure* fig : BlackFigures) {
        _Board[fig->Pos.x][fig->Pos.y] = fig;
    }

}

Board::~Board() {
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            delete _Board[i][j];  
        }
        delete[] _Board[i]; 
    }
    delete[] _Board; 
}


void Board::DisplayBoard() {
    for (int k = 0; k < Size+1; k++) std::cout << "----";
    std::cout << std::endl;

    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (j == 0) {
                std::cout << "|";
            }
            if (_Board[i][j] != nullptr) {
                if (_Board[i][j]->Type == king) std::cout << " K |";
                else if (_Board[i][j]->Type == queen)std::cout << " Q |";
                else if (_Board[i][j]->Type == bishop)std::cout << " B |";
                else if (_Board[i][j]->Type == rook)std::cout << " R |";
                else if (_Board[i][j]->Type == horse)std::cout << " H |";
                else if (_Board[i][j]->Type == pawn)std::cout << " P |";                
            }  else std::cout << "   |";
        }
        std::cout << std::endl;
    }
    for (int k = 0; k < Size+1; k++) std::cout << "----";
    std::cout << std::endl;
}

void Board::DoMove(Position first,Position second) {
    _Board[second.x][second.y] = _Board[first.x][first.y];
    _Board[first.x][first.y] = nullptr;
    _Board[second.x][second.y]->Pos.x = second.x;
    _Board[second.x][second.y]->Pos.y = second.y;
}