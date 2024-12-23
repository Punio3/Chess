#include "Queen.h"

Queen::Queen(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::queen;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = col;
}

Queen::Queen() {
	Pos = Position();
	Type = FigureType::queen;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = noColor;
}

std::list<Position> Queen::PossibleMoves(Figure*** _Board, int Size) {
	return std::list<Position>();
}