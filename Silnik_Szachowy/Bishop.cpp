#include "Bishop.h"

Bishop::Bishop(Position pos) {
	Pos = pos;
	Type = FigureType::bishop;
	CantMove = false;
}

Bishop::Bishop() {
	Pos = Position();
	Type = FigureType::bishop;
	CantMove = false;
}

std::list<Position> Bishop::PossibleMoves() {
	return std::list<Position>();
}