#include "EmptyFigure.h"

EmptyFigure::EmptyFigure(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::none;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = col;
}

EmptyFigure::EmptyFigure() {
	Pos = Position();
	Type = FigureType::none;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = noColor;
}

std::list<Position> EmptyFigure::PossibleMoves(Figure*** _Board, int Size) {
	return std::list<Position>();
}