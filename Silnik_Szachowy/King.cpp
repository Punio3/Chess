#include "King.h"

King::King(Position pos) {
	Pos = pos;
	Type = FigureType::king;
	CantMove = false;
	isChecked = false;
	CanRoszada = true;
}

King::King() {
	Pos = Position();
	Type = FigureType::king;
	CantMove = false;
	isChecked = false;
	CanRoszada = true;
}

std::list<Position> King::PossibleMoves() {
	return std::list<Position>();
}