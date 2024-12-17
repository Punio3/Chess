#include "Figure.h"

class Queen : public Figure {
public:
	std::list<Position> PossibleMoves() override;

	Queen();
	Queen(Position pos);
};