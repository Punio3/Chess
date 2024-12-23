#include "Figure.h"

class EmptyFigure : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;

	EmptyFigure();
	EmptyFigure(Position pos, Color col);
};