#include "Queen.h"

Queen::Queen(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::queen;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = col;
}

Queen::Queen() {
	Pos = Position();
	Type = FigureType::queen;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = noColor;
}

std::list<Position> Queen::PossibleMoves(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();

	//sprawdzenie mozliwych ruchow w pionie
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i < Size; i++) {
			if (k == 0) {
				if (Pos.x - i >= 0 && _Board[Pos.x - i][Pos.y]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y));
				}
				else if (Pos.x - i >= 0 && _Board[Pos.x - i][Pos.y]->Type != none && _Board[Pos.x - i][Pos.y]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y));
					break;
				}
				else if (Pos.x - i >= 0 && _Board[Pos.x - i][Pos.y]->Type != none && _Board[Pos.x - i][Pos.y]->FigureColor == FigureColor) {
					break;
				}
			}
			else {
				if (Pos.x + i < Size && _Board[Pos.x + i][Pos.y]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y));
				}
				else if (Pos.x + i < Size && _Board[Pos.x + i][Pos.y]->Type != none && _Board[Pos.x + i][Pos.y]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y));
					break;
				}
				else if (Pos.x + i < Size && _Board[Pos.x + i][Pos.y]->Type != none && _Board[Pos.x + i][Pos.y]->FigureColor == FigureColor) {
					break;
				}
			}
		}
	}

	//sprawdzenie mozliwych ruchow w poziomie
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i < Size; i++) {
			if (k == 0) {
				if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x, Pos.y - i));
				}
				else if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type != none && _Board[Pos.x][Pos.y - i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x, Pos.y - i));
					break;
				}
				else if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type != none && _Board[Pos.x][Pos.y - i]->FigureColor == FigureColor) {
					break;
				}
			}
			else {
				if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x, Pos.y + i));
				}
				else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type != none && _Board[Pos.x][Pos.y + i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x, Pos.y + i));
					break;
				}
				else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type != none && _Board[Pos.x][Pos.y + i]->FigureColor == FigureColor) {
					break;
				}
			}
		}
	}

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