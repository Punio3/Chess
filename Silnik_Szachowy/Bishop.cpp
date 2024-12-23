#include "Bishop.h"

Bishop::Bishop(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::bishop;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = col;
}

Bishop::Bishop() {
	Pos = Position();
	Type = FigureType::bishop;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = noColor;
}

std::list<Position> Bishop::PossibleMoves(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();

	//sprawdzenie mozliwych ruchow w 1 przek¹tnej
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i < Size; i++) {
			if (k == 0) {
				if (Pos.x - i >= 0 && Pos.y + i < Size && _Board[Pos.x - i][Pos.y + i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y + i));
				}
				else if (Pos.x - i >= 0 && Pos.y + i < Size && _Board[Pos.x - i][Pos.y + i]->Type != none && _Board[Pos.x - i][Pos.y + i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y + i));
					break;
				}
				else if (Pos.x - i >= 0 && Pos.y + i < Size && _Board[Pos.x - i][Pos.y + i]->Type != none && _Board[Pos.x - i][Pos.y + i]->FigureColor == FigureColor) {
					break;
				}
			}
			else {
				if (Pos.x - i >= 0 && Pos.y - i >= 0 && _Board[Pos.x - i][Pos.y - i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y - i));
				}
				else if (Pos.x - i >= 0 && Pos.y - i >= 0 && _Board[Pos.x - i][Pos.y - i]->Type != none && _Board[Pos.x - i][Pos.y - i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y - i));
					break;
				}
				else if (Pos.x - i >= 0 && Pos.y - i >= 0 && _Board[Pos.x - i][Pos.y - i]->Type != none && _Board[Pos.x - i][Pos.y - i]->FigureColor == FigureColor) {
					break;
				}
			}
		}
	}

	//sprawdzenie mozliwych ruchow w 2 przek¹tnej
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i < Size; i++) {
			if (k == 0) {
				if (Pos.x + i < Size && Pos.y + i < Size && _Board[Pos.x + i][Pos.y + i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y + i));
				}
				else if (Pos.x + i < Size && Pos.y + i < Size && _Board[Pos.x + i][Pos.y + i]->Type != none && _Board[Pos.x + i][Pos.y + i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y + i));
					break;
				}
				else if (Pos.x + i < Size && Pos.y + i < Size && _Board[Pos.x + i][Pos.y + i]->Type != none && _Board[Pos.x + i][Pos.y + i]->FigureColor == FigureColor) {
					break;
				}
			}
			else {
				if (Pos.x + i < Size && Pos.y - i >= 0 && _Board[Pos.x + i][Pos.y - i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y - i));
				}
				else if (Pos.x + i < Size && Pos.y - i >= 0 && _Board[Pos.x + i][Pos.y - i]->Type != none && _Board[Pos.x + i][Pos.y - i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y - i));
					break;
				}
				else if (Pos.x + i < Size && Pos.y - i >= 0 && _Board[Pos.x + i][Pos.y - i]->Type != none && _Board[Pos.x + i][Pos.y - i]->FigureColor == FigureColor) {
					break;
				}
			}
		}
	}

	for (Position pos : ListOfMoves) {
		_Board[pos.x][pos.y]->CanBeAttacked = true;
	}

	return ListOfMoves;
}