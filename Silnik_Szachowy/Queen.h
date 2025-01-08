#include "Figure.h"

class Queen : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;
	void MakeMove(Figure*** board, Position second) override;

	Queen();
	Queen(Position pos, Color col);
};