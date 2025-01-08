#include "Figure.h"

class Rook : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;
	void MakeMove(Figure*** board, Position second) override;
	bool isMoved;

	Rook();
	Rook(Position pos, Color col);
};