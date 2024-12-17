#include "Figure.h"

class Board {
public:
    std::list<Figure*> WhiteFigures;  
    std::list<Figure*> BlackFigures;
    Figure*** _Board;  
    int Size;         

    Board(int size);  

    void DisplayBoard();  
    void DoMove(Position first, Position second);  

    ~Board(); 

private:
    void InitializeBoard();  
};