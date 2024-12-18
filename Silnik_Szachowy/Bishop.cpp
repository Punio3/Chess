#include "Bishop.h"

Bishop::Bishop(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::bishop;
	CantMove = false;
	FigureColor = col;
}

Bishop::Bishop() {
	Pos = Position();
	Type = FigureType::bishop;
	CantMove = false;
	FigureColor = noColor;
}

std::list<Position> Bishop::PossibleMoves(Figure*** _Board, int Size) {
	return std::list<Position>();
}