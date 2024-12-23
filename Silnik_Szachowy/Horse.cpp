#include "Horse.h"

Horse::Horse(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::horse;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = col;
}

Horse::Horse() {
	Pos = Position();
	Type = FigureType::horse;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = noColor;
}

std::list<Position> Horse::PossibleMoves(Figure*** _Board, int Size) {
	return std::list<Position>();
}