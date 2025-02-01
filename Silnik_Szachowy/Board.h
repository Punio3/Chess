#include "Figure.h"
#include "King.h"
#pragma once

enum Player {
    Playerwhite,
    Playerblack,
    brak
};

class Board {
public:
    std::list<Figure*> WhiteFigures;  
    std::list<Figure*> BlackFigures;
    Figure*** _Board;
    King* BlackKing;
    King* WhiteKing;
    Figure* FigureWithShowedMoves;
    int Size;         

    Board();
    Board(int size);  
    Board(bool x); // for copy board 

    void DisplayBoard(Player player);  
    void ClearAttackedFields(std::list<Position> ListOfPositions, Color color);
    void AddAttackedFields(std::list<Position> ListOfPositions,Color color);
    void AddCheckedFields(std::list<Figure*> Figures);
    void ClearCheckedFields(std::list<Figure*> Figures);
    void CheckIfPawnCanTransform(Position second);
    std::list<Position> PossibleMovesForFigure(Figure* x, Player whoMoves);
    Board* copyBoard();

    ~Board(); 

private:
    void InitializeBoard();  
};