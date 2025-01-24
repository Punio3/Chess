#include "Horse.h"
#include "EmptyFigure.h"
#include "King.h"

Horse::Horse(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::horse;
	CanBeAttacked = false;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = col;
}

Horse::Horse() {
	Pos = Position();
	Type = FigureType::horse;
	CanBeAttacked = false;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = noColor;
}

std::list<Position> Horse::PossibleMoves(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();
	if (!isZwiazany) {
		//2 pola do gory
		if (Pos.x - 2 >= 0 && Pos.y - 1 >= 0 && ((_Board[Pos.x - 2][Pos.y - 1]->Type == none || _Board[Pos.x - 2][Pos.y - 1]->FigureColor != FigureColor) 
			|| (_Board[Pos.x - 2][Pos.y - 1]->Type != none || _Board[Pos.x - 2][Pos.y - 1]->FigureColor == FigureColor))) {
			ListOfMoves.push_back(Position(Pos.x - 2, Pos.y - 1));
			if (_Board[Pos.x - 2][Pos.y - 1]->Type == king && _Board[Pos.x - 2][Pos.y - 1]->FigureColor != FigureColor) {
				King* king = dynamic_cast<King*>(_Board[Pos.x - 2][Pos.y - 1]);
				king->isChecked = true;

				king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
			}
		}
		if (Pos.x - 2 >= 0 && Pos.y + 1 < Size && ((_Board[Pos.x - 2][Pos.y + 1]->Type == none || _Board[Pos.x - 2][Pos.y + 1]->FigureColor != FigureColor) 
			|| (_Board[Pos.x - 2][Pos.y + 1]->Type != none || _Board[Pos.x - 2][Pos.y + 1]->FigureColor == FigureColor))) {
			ListOfMoves.push_back(Position(Pos.x - 2, Pos.y + 1));
			if (_Board[Pos.x - 2][Pos.y + 1]->Type == king && _Board[Pos.x - 2][Pos.y + 1]->FigureColor != FigureColor) {
				King* king = dynamic_cast<King*>(_Board[Pos.x - 2][Pos.y + 1]);
				king->isChecked = true;

				king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
			}
		}
		//2 pola do dolu
		if (Pos.x + 2 < Size && Pos.y - 1 >= 0 && ((_Board[Pos.x + 2][Pos.y - 1]->Type == none || _Board[Pos.x + 2][Pos.y - 1]->FigureColor != FigureColor) 
			|| (_Board[Pos.x + 2][Pos.y - 1]->Type != none || _Board[Pos.x + 2][Pos.y - 1]->FigureColor == FigureColor))) {
			ListOfMoves.push_back(Position(Pos.x + 2, Pos.y - 1));
			if (_Board[Pos.x + 2][Pos.y - 1]->Type == king && _Board[Pos.x + 2][Pos.y - 1]->FigureColor != FigureColor) {
				King* king = dynamic_cast<King*>(_Board[Pos.x + 2][Pos.y - 1]);
				king->isChecked = true;

				king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
			}
		}
		if (Pos.x + 2 < Size && Pos.y + 1 < Size && ((_Board[Pos.x + 2][Pos.y + 1]->Type == none || _Board[Pos.x + 2][Pos.y + 1]->FigureColor != FigureColor) 
			|| (_Board[Pos.x + 2][Pos.y + 1]->Type != none || _Board[Pos.x + 2][Pos.y + 1]->FigureColor == FigureColor))) {
			ListOfMoves.push_back(Position(Pos.x + 2, Pos.y + 1));
			if (_Board[Pos.x + 2][Pos.y + 1]->Type == king && _Board[Pos.x + 2][Pos.y + 1]->FigureColor != FigureColor) {
				King* king = dynamic_cast<King*>(_Board[Pos.x + 2][Pos.y + 1]);
				king->isChecked = true;

				king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
			}
		}
		//2 pola na prawo
		if (Pos.x + 1 < Size && Pos.y + 2 < Size && ((_Board[Pos.x + 1][Pos.y + 2]->Type == none || _Board[Pos.x + 1][Pos.y + 2]->FigureColor != FigureColor)
			|| (_Board[Pos.x + 1][Pos.y + 2]->Type != none || _Board[Pos.x + 1][Pos.y + 2]->FigureColor == FigureColor))) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y + 2));
			if (_Board[Pos.x + 1][Pos.y + 2]->Type == king && _Board[Pos.x + 1][Pos.y + 2]->FigureColor != FigureColor) {
				King* king = dynamic_cast<King*>(_Board[Pos.x + 1][Pos.y + 2]);
				king->isChecked = true;

				king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
			}
		}
		if (Pos.x - 1 >= 0 && Pos.y + 2 < Size && ((_Board[Pos.x - 1][Pos.y + 2]->Type == none || _Board[Pos.x - 1][Pos.y + 2]->FigureColor != FigureColor) 
			|| (_Board[Pos.x - 1][Pos.y + 2]->Type != none || _Board[Pos.x - 1][Pos.y + 2]->FigureColor == FigureColor))) {
			ListOfMoves.push_back(Position(Pos.x - 1, Pos.y + 2));
			if (_Board[Pos.x - 1][Pos.y + 2]->Type == king && _Board[Pos.x - 1][Pos.y + 2]->FigureColor != FigureColor) {
				King* king = dynamic_cast<King*>(_Board[Pos.x - 1][Pos.y + 2]);
				king->isChecked = true;

				king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
			}
		}
		//2 pola na lewo
		if (Pos.x + 1 < Size && Pos.y - 2 >= 0 && ((_Board[Pos.x + 1][Pos.y - 2]->Type == none || _Board[Pos.x + 1][Pos.y - 2]->FigureColor != FigureColor) 
			|| (_Board[Pos.x + 1][Pos.y - 2]->Type != none || _Board[Pos.x + 1][Pos.y - 2]->FigureColor == FigureColor))) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y - 2));
			if (_Board[Pos.x + 1][Pos.y - 2]->Type == king && _Board[Pos.x + 1][Pos.y - 2]->FigureColor != FigureColor) {
				King* king = dynamic_cast<King*>(_Board[Pos.x + 1][Pos.y - 2]);
				king->isChecked = true;

				king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
			}
		}
		if (Pos.x - 1 >= 0 && Pos.y - 2 >= 0 && ((_Board[Pos.x - 1][Pos.y - 2]->Type == none || _Board[Pos.x - 1][Pos.y - 2]->FigureColor != FigureColor) 
			|| (_Board[Pos.x - 1][Pos.y - 2]->Type != none || _Board[Pos.x - 1][Pos.y - 2]->FigureColor == FigureColor))) {
			ListOfMoves.push_back(Position(Pos.x - 1, Pos.y - 2));
			if (_Board[Pos.x - 1][Pos.y - 2]->Type == king && _Board[Pos.x - 1][Pos.y - 2]->FigureColor != FigureColor) {
				King* king = dynamic_cast<King*>(_Board[Pos.x - 1][Pos.y - 2]);
				king->isChecked = true;

				king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
			}
		}
	}

	return ListOfMoves;
}

void Horse::MakeMove(Figure*** board, Position second) {

	delete(board[second.x][second.y]);
	board[second.x][second.y] = board[Pos.x][Pos.y];
	board[Pos.x][Pos.y] = new EmptyFigure(Position(Pos.x, Pos.y), Color::noColor);
	if (board[second.x][second.y] != nullptr) {
		board[second.x][second.y]->Pos.x = second.x;
		board[second.x][second.y]->Pos.y = second.y;
	}
	

}