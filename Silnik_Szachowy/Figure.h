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

enum Color {
	white,
	black,
	noColor
};

class Figure {
public:
	Position Pos;
	FigureType Type;
	bool CantMove;
	bool CanBeAttacked;
	bool isCheckedByEnemy;
	bool isZwiazany; //czy figura chroni krola przed wroga figura
	Color FigureColor;
	

	virtual std::list<Position> PossibleMoves(Figure*** _Board,int Size) = 0;
	virtual void MakeMove(Figure*** board, Position second) = 0;

	Figure();
};