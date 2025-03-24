#include "Figure.h"

class King : public Figure {
public:
	std::list<Position> PossibleMoves(Figure*** _Board, int Size) override;
	void MakeMove(Figure*** board, Position second) override;
	int OcenaHeurystycznaFigury() override;

	bool isChecked;
	bool isMovedOrDoneRoszada;
	bool CanRoszada;

	King();
	King(Position pos, Color col);
};