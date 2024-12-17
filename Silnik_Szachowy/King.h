#include "Figure.h"

class King : public Figure {
public:
	std::list<Position> PossibleMoves() override;
	bool isChecked;
	bool CanRoszada;

	King();
	King(Position pos);
};