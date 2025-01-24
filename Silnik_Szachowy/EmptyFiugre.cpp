#include "EmptyFigure.h"

EmptyFigure::EmptyFigure(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::none;
	CanBeAttacked = false;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	FigureColor = col;
}

EmptyFigure::EmptyFigure() {
	Pos = Position();
	Type = FigureType::none;
	CanBeAttacked = false;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	FigureColor = noColor;
}

std::list<Position> EmptyFigure::PossibleMoves(Figure*** _Board, int Size) {
	return std::list<Position>();
}

void EmptyFigure::MakeMove(Figure*** board, Position second) {

	delete(board[second.x][second.y]);
	board[second.x][second.y] = board[Pos.x][Pos.y];
	board[Pos.x][Pos.y] = new EmptyFigure(Position(Pos.x, Pos.y), Color::noColor);
	if (board[second.x][second.y] != nullptr) {
		board[second.x][second.y]->Pos.x = second.x;
		board[second.x][second.y]->Pos.y = second.y;
	}
	
}