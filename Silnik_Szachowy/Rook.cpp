#include "Rook.h"

Rook::Rook(Position pos) {
	Pos = pos;
	Type = FigureType::rook;
	CantMove = false;
}

Rook::Rook() {
	Pos = Position();
	Type = FigureType::rook;
	CantMove = false;
}

std::list<Position> Rook::PossibleMoves() {
	return std::list<Position>();
}