#include "Pawn.h"
#include "EmptyFigure.h"
#include "King.h"

Pawn::Pawn(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::pawn;
	CanBeAttacked = false;
	isFirstMove = true;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	ValueInPoints = 1;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = col;
}

Pawn::Pawn() {
	Pos = Position();
	Type = FigureType::pawn;
	CanBeAttacked = false;
	isFirstMove = true;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	ValueInPoints = 1;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = noColor;
}

std::list<Position> Pawn::PossibleMoves(Figure*** _Board, int Size){
	std::list<Position> ListOfMoves = std::list<Position>();


	if (FigureColor == white) {
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu w pionie
		if (isFirstMove) {
			for (int k = 1; k <= 2; k++) {
				if (Pos.x - k >= 0 && _Board[Pos.x - k][Pos.y]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x - k, Pos.y));
				}
				else break;
			}
		}
		else {
			if (Pos.x - 1 >= 0 && _Board[Pos.x - 1][Pos.y]->Type == none) {
				ListOfMoves.push_back(Position(Pos.x - 1, Pos.y));
			}
		}
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu po skosie
		if (Pos.x - 1 >= 0 && Pos.y - 1 >= 0 && _Board[Pos.x - 1][Pos.y - 1]->Type != none && _Board[Pos.x - 1][Pos.y - 1]->FigureColor == black) {
			ListOfMoves.push_back(Position(Pos.x - 1, Pos.y - 1));
		}
		if (Pos.x - 1 >= 0 && Pos.y + 1 < Size && _Board[Pos.x - 1][Pos.y + 1]->Type != none && _Board[Pos.x - 1][Pos.y + 1]->FigureColor == black) {
			ListOfMoves.push_back(Position(Pos.x - 1, Pos.y + 1));
		}

	}
	else if (FigureColor == black) {
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu w pionie
		if (isFirstMove) {
			for (int k = 1; k <= 2; k++) {
				if (Pos.x + k < Size && _Board[Pos.x + k][Pos.y]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x + k, Pos.y));
				}
				else break;
			}
		}
		else {
			if (Pos.x + 1 < Size && _Board[Pos.x + 1][Pos.y]->Type == none) {
				ListOfMoves.push_back(Position(Pos.x + 1, Pos.y));
			}
		}
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu po skosie
		if (Pos.x + 1 < Size && Pos.y - 1 >= 0 && _Board[Pos.x + 1][Pos.y - 1]->Type != none && _Board[Pos.x + 1][Pos.y - 1]->FigureColor == white) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y - 1));
		}
		if (Pos.x + 1 < Size && Pos.y + 1 < Size && _Board[Pos.x + 1][Pos.y + 1]->Type != none && _Board[Pos.x + 1][Pos.y + 1]->FigureColor == white) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y + 1));
		}
	}
	
	if (isZwiazany) {
		ListOfMoves = GiveListOfDuplicateFields(ListOfMoves, AttackedMovesWhenIsZwiazany);
	}

	return ListOfMoves;
}

std::list<Position> Pawn::CheckedFields(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();

	if (FigureColor == white) {
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu po skosie
		if (Pos.x - 1 >= 0 && Pos.y - 1 >= 0 && _Board[Pos.x - 1][Pos.y - 1]->Type == none) {
			ListOfMoves.push_back(Position(Pos.x - 1, Pos.y - 1));
		}
		if (Pos.x - 1 >= 0 && Pos.y - 1 >= 0 && _Board[Pos.x - 1][Pos.y - 1]->Type != none && _Board[Pos.x - 1][Pos.y - 1]->FigureColor==white) {
			ListOfMoves.push_back(Position(Pos.x - 1, Pos.y - 1));
		}
		if (Pos.x - 1 >= 0 && Pos.y - 1 >= 0 && _Board[Pos.x - 1][Pos.y - 1]->Type == king && _Board[Pos.x - 1][Pos.y - 1]->FigureColor==black) {
			King* king = dynamic_cast<King*>(_Board[Pos.x - 1][Pos.y - 1]);
			king->isChecked = true;

			king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
		}
		if (Pos.x - 1 >= 0 && Pos.y + 1 < Size && _Board[Pos.x - 1][Pos.y + 1]->Type == none) {
			ListOfMoves.push_back(Position(Pos.x - 1, Pos.y + 1));
		}
		if (Pos.x - 1 >= 0 && Pos.y + 1 < Size && _Board[Pos.x - 1][Pos.y + 1]->Type != none && _Board[Pos.x - 1][Pos.y + 1]->FigureColor ==white) {
			ListOfMoves.push_back(Position(Pos.x - 1, Pos.y + 1));
		}
		if (Pos.x - 1 >= 0 && Pos.y + 1 < Size && _Board[Pos.x - 1][Pos.y + 1]->Type == king && _Board[Pos.x - 1][Pos.y + 1]->FigureColor == black) {
			King* king = dynamic_cast<King*>(_Board[Pos.x - 1][Pos.y + 1]);
			king->isChecked = true;

			king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
		}
	}
	else if (FigureColor == black) {
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu po skosie
		if (Pos.x + 1 < Size && Pos.y - 1 >= 0 && _Board[Pos.x + 1][Pos.y - 1]->Type == none) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y - 1));
		}
		if (Pos.x + 1 < Size && Pos.y - 1 >= 0 && _Board[Pos.x + 1][Pos.y - 1]->Type != none && _Board[Pos.x + 1][Pos.y - 1]->FigureColor==black) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y - 1));
		}
		if (Pos.x + 1 < Size && Pos.y - 1 >= 0 && _Board[Pos.x + 1][Pos.y - 1]->Type == king && _Board[Pos.x + 1][Pos.y - 1]->FigureColor == white) {
			King* king = dynamic_cast<King*>(_Board[Pos.x + 1][Pos.y - 1]);
			king->isChecked = true;

			king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
		}
		if (Pos.x + 1 < Size && Pos.y + 1 < Size && _Board[Pos.x + 1][Pos.y + 1]->Type == none) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y + 1));
		}
		if (Pos.x + 1 < Size && Pos.y + 1 < Size && _Board[Pos.x + 1][Pos.y + 1]->Type != none && _Board[Pos.x + 1][Pos.y + 1]->FigureColor==black) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y + 1));
		}
		if (Pos.x + 1 < Size && Pos.y + 1 < Size && _Board[Pos.x + 1][Pos.y + 1]->Type == king && _Board[Pos.x + 1][Pos.y + 1]->FigureColor == white) {
			King* king = dynamic_cast<King*>(_Board[Pos.x + 1][Pos.y + 1]);
			king->isChecked = true;

			king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y));
		}
	}
	return ListOfMoves;
}

void Pawn::MakeMove(Figure*** board, Position second) {

	delete(board[second.x][second.y]);
	board[second.x][second.y] = board[Pos.x][Pos.y];
	board[Pos.x][Pos.y] = new EmptyFigure(Position(Pos.x, Pos.y), Color::noColor);
	if (board[second.x][second.y] != nullptr) {
		board[second.x][second.y]->Pos.x = second.x;
		board[second.x][second.y]->Pos.y = second.y;
	}
	if (isFirstMove) isFirstMove = false;

}


int Pawn::OcenaHeurystycznaFigury() {



	return 0;
}