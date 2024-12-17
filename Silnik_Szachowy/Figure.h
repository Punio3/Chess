#include "Position.h"
#include <list>

#pragma once
enum FigureType {
	pawn,
	bishop,
	king,
	queen,
	rook,
	horse,
	none
};

class Figure {
public:
	Position Pos;
	FigureType Type;
	bool CantMove;
	

	virtual std::list<Position> PossibleMoves() = 0;
	void MakeMove(Position pos);

	Figure();
};