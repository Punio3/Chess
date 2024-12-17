#include "Queen.h"

Queen::Queen(Position pos) {
	Pos = pos;
	Type = FigureType::queen;
	CantMove = false;
}

Queen::Queen() {
	Pos = Position();
	Type = FigureType::queen;
	CantMove = false;
}

std::list<Position> Queen::PossibleMoves() {
	return std::list<Position>();
}