#include "King.h"

King::King(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::king;
	CantMove = false;
	isChecked = false;
	CanRoszada = true;
	FigureColor = col;
}

King::King() {
	Pos = Position();
	Type = FigureType::king;
	CantMove = false;
	isChecked = false;
	CanRoszada = true;
	FigureColor = noColor;
}

std::list<Position> King::PossibleMoves(Figure*** _Board, int Size) {
	return std::list<Position>();
}