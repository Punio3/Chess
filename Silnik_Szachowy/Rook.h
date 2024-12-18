#include "Figure.h"

class Rook : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;

	Rook();
	Rook(Position pos, Color col);
};