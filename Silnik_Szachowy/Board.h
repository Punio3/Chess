#include "Figure.h"
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
    Figure* BlackKing;
    Figure* WhiteKing;
    int Size;         

    Board();
    Board(int size);  

    void DisplayBoard(Player player);  
    void ClearAttackedFields(std::list<Position> ListOfPositions);
    void AddCheckedFields(std::list<Figure*> Figures);
    void ClearCheckedFields(std::list<Figure*> Figures);
    void DoMove(Position first, Position second);  

    ~Board(); 

private:
    void InitializeBoard();  
};