#include "Horse.h"

Horse::Horse(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::horse;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = col;
}

Horse::Horse() {
	Pos = Position();
	Type = FigureType::horse;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = noColor;
}

std::list<Position> Horse::PossibleMoves(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();

	//2 pola do gory
	if (Pos.x - 2 >= 0 && Pos.y - 1 >= 0 && (_Board[Pos.x - 2][Pos.y - 1]->Type == none || _Board[Pos.x - 2][Pos.y - 1]->FigureColor != FigureColor)) {
		ListOfMoves.push_back(Position(Pos.x - 2, Pos.y - 1));
		_Board[Pos.x - 2][Pos.y - 1]->CanBeAttacked = true;
	}
	if (Pos.x - 2 >= 0 && Pos.y + 1 < Size && (_Board[Pos.x - 2][Pos.y + 1]->Type == none || _Board[Pos.x - 2][Pos.y + 1]->FigureColor != FigureColor)) {
		ListOfMoves.push_back(Position(Pos.x - 2, Pos.y + 1));
		_Board[Pos.x - 2][Pos.y + 1]->CanBeAttacked = true;
	}
	//2 pola do dolu
	if (Pos.x + 2 < Size && Pos.y - 1 >= 0 && (_Board[Pos.x + 2][Pos.y - 1]->Type == none || _Board[Pos.x + 2][Pos.y - 1]->FigureColor != FigureColor)) {
		ListOfMoves.push_back(Position(Pos.x + 2, Pos.y - 1));
		_Board[Pos.x + 2][Pos.y - 1]->CanBeAttacked = true;
	}
	if (Pos.x + 2 < Size && Pos.y + 1 < Size && (_Board[Pos.x + 2][Pos.y + 1]->Type == none || _Board[Pos.x + 2][Pos.y + 1]->FigureColor != FigureColor)) {
		ListOfMoves.push_back(Position(Pos.x + 2, Pos.y + 1));
		_Board[Pos.x + 2][Pos.y + 1]->CanBeAttacked = true;
	}
	//2 pola na prawo
	if (Pos.x + 1 < Size && Pos.y + 2 < Size && (_Board[Pos.x + 1][Pos.y + 2]->Type == none || _Board[Pos.x + 1][Pos.y + 2]->FigureColor != FigureColor)) {
		ListOfMoves.push_back(Position(Pos.x + 1, Pos.y + 2));
		_Board[Pos.x + 1][Pos.y + 2]->CanBeAttacked = true;
	}
	if (Pos.x - 1 >= 0 && Pos.y + 2 < Size && (_Board[Pos.x - 1][Pos.y + 2]->Type == none || _Board[Pos.x - 1][Pos.y + 2]->FigureColor != FigureColor)) {
		ListOfMoves.push_back(Position(Pos.x - 1, Pos.y + 2));
		_Board[Pos.x - 1][Pos.y + 2]->CanBeAttacked = true;
	}
	//2 pola na lewo
	if (Pos.x + 1 < Size && Pos.y - 2 >= 0 && (_Board[Pos.x + 1][Pos.y - 2]->Type == none || _Board[Pos.x + 1][Pos.y - 2]->FigureColor != FigureColor)) {
		ListOfMoves.push_back(Position(Pos.x + 1, Pos.y - 2));
		_Board[Pos.x + 1][Pos.y - 2]->CanBeAttacked = true;
	}
	if (Pos.x - 1 >= 0 && Pos.y - 2 >= 0 && (_Board[Pos.x - 1][Pos.y - 2]->Type == none || _Board[Pos.x - 1][Pos.y - 2]->FigureColor != FigureColor)) {
		ListOfMoves.push_back(Position(Pos.x - 1, Pos.y - 2));
		_Board[Pos.x - 1][Pos.y - 2]->CanBeAttacked = true;
	}



	for (Position pos : ListOfMoves) {
		_Board[pos.x][pos.y]->CanBeAttacked = true;
	}

	return ListOfMoves;
}