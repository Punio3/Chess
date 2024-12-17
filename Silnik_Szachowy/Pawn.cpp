#include "Pawn.h"

Pawn::Pawn(Position pos) {
	Pos = pos;
	Type = FigureType::pawn;
	CantMove = false;
	isFirstMove = true;
}

Pawn::Pawn() {
	Pos = Position();
	Type = FigureType::pawn;
	CantMove = false;
	isFirstMove = true;
}

std::list<Position> Pawn::PossibleMoves() {
	return std::list<Position>();
}