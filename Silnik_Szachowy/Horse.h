#include "Figure.h"

class Horse : public Figure {
public:
	std::list<Position> PossibleMoves() override;

	Horse();
	Horse(Position pos);
};