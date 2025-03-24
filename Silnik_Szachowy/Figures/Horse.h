#include "Figure.h"

class Horse : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;
	void MakeMove(Figure*** board, Position second) override;
	int OcenaHeurystycznaFigury() override;

	Horse();
	Horse(Position pos, Color col);
};