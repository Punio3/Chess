#include "Figure.h"

class Pawn : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;
	bool isFirstMove;

	Pawn();
	Pawn(Position pos, Color col);
};