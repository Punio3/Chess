#include "Pawn.h"

Pawn::Pawn(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::pawn;
	CantMove = false;
	CanBeAttacked = false;
	isFirstMove = true;
	FigureColor = col;
}

Pawn::Pawn() {
	Pos = Position();
	Type = FigureType::pawn;
	CantMove = false;
	CanBeAttacked = false;
	isFirstMove = true;
	FigureColor = noColor;
}

std::list<Position> Pawn::PossibleMoves(Figure*** _Board, int Size){
	std::list<Position> ListOfMoves = std::list<Position>();

	if (FigureColor == white) {
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu w pionie
		if (isFirstMove) {
			for (int k = 1; k <= 2; k++) {
				if (Pos.x - k >= 0 && _Board[Pos.x - k][Pos.y]->Type==none) {
					ListOfMoves.push_back(Position(Pos.x-k, Pos.y));
				} else break;
			}
		}
		else {
			if (Pos.x - 1 >= 0 && _Board[Pos.x - 1][Pos.y]->Type == none) {
				ListOfMoves.push_back(Position(Pos.x-1, Pos.y));				
			}		
		}
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu po skosie
		if (Pos.x - 1 >= 0 && Pos.y - 1 >= 0 && _Board[Pos.x - 1][Pos.y - 1]->Type != none && _Board[Pos.x - 1][Pos.y - 1]->FigureColor == black) {
			ListOfMoves.push_back(Position(Pos.x-1, Pos.y-1));
		}
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu po skosie
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
		if (Pos.x + 1 < Size && Pos.y - 1 >= 0 && _Board[Pos.x + 1][Pos.y - 1]->Type != none && _Board[Pos.x+1][Pos.y-1]->FigureColor==white) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y - 1));
		}
		//Sprawdzenie czy jest mo퓄iwo쒏 ruchu po skosie
		if (Pos.x + 1 < Size && Pos.y + 1 < Size && _Board[Pos.x + 1][Pos.y + 1]->Type != none && _Board[Pos.x + 1][Pos.y + 1]->FigureColor == white) {
			ListOfMoves.push_back(Position(Pos.x + 1, Pos.y + 1));
		}
	}

	for (Position pos : ListOfMoves) {
		_Board[pos.x][pos.y]->CanBeAttacked = true;
	}
	return ListOfMoves;
}