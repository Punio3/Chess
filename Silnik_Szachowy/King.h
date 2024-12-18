#include "Figure.h"

class King : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;
	bool isChecked;
	bool CanRoszada;

	King();
	King(Position pos, Color col);
};