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
	bool CanBeAttacked;
	bool isCheckedByWhite;
	bool isCheckedByBlack;
	bool isZwiazany; //czy figura chroni krola przed wroga figura
	int ValueInPoints; //ile punktow warta jest figura
	std::list<Position> AttackedMovesWhenIsZwiazany;
	Color FigureColor;
	

	virtual std::list<Position> PossibleMoves(Figure*** _Board,int Size) = 0;
	virtual void MakeMove(Figure*** board, Position second) = 0;
	std::list<Position> GiveListOfDuplicateFields(std::list<Position> first, std::list<Position> second);
	virtual int OcenaHeurystycznaFigury() = 0;

	Figure();
};