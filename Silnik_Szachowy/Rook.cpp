#include "Rook.h"

Rook::Rook(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::rook;
	CantMove = false;
	FigureColor = col;
}

Rook::Rook() {
	Pos = Position();
	Type = FigureType::rook;
	CantMove = false;
	FigureColor = noColor;
}

std::list<Position> Rook::PossibleMoves(Figure*** _Board, int Size) {
	return std::list<Position>();
}