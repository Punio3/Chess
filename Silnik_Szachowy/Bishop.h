#include "Figure.h"

class Bishop : public Figure {
public:
	std::list<Position> PossibleMoves() override;

	Bishop();
	Bishop(Position pos);
};