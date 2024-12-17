#include "Figure.h"

class Rook : public Figure {
public:
	std::list<Position> PossibleMoves() override;

	Rook();
	Rook(Position pos);
};