#include "Figure.h"

class Pawn : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;
	void MakeMove(Figure*** board, Position second) override;
	std::list<Position> CheckedFields(Figure*** _Board, int Size);
	int OcenaHeurystycznaFigury() override;

	bool isFirstMove;

	Pawn();
	Pawn(Position pos, Color col);
};