#include "Figure.h"

class Pawn : public Figure {
public:
	std::list<Position> PossibleMoves() override;
	bool isFirstMove;

	Pawn();
	Pawn(Position pos);
};