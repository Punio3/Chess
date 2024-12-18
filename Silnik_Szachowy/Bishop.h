#include "Figure.h"

class Bishop : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;

	Bishop();
	Bishop(Position pos,Color col);
};