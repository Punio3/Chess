#include "Figure.h"

class Queen : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;

	Queen();
	Queen(Position pos, Color col);
};