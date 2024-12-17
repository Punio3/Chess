#include "Horse.h"

Horse::Horse(Position pos) {
	Pos = pos;
	Type = FigureType::horse;
	CantMove = false;
}

Horse::Horse() {
	Pos = Position();
	Type = FigureType::horse;
	CantMove = false;
}

std::list<Position> Horse::PossibleMoves() {
	return std::list<Position>();
}