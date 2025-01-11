#include "King.h"
#include "EmptyFigure.h"
#include "Rook.h"

King::King(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::king;
	CantMove = false;
	isChecked = false;
	isMovedOrDoneRoszada = false;
	CanBeAttacked = false;
	CanRoszada = true;
	isCheckedByEnemy = false;
	isZwiazany = false;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = col;
}

King::King() {
	Pos = Position();
	Type = FigureType::king;
	CantMove = false;
	isChecked = false;
	isMovedOrDoneRoszada = false;
	CanBeAttacked = false;
	CanRoszada = true;
	isCheckedByEnemy = false;
	isZwiazany = false;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = noColor;
}

std::list<Position> King::PossibleMoves(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();

	if (CanRoszada && !isChecked) {
		for (int k = 0; k < 2; k++) {
			for (int i = 1; i < Size; i++) {
				if (k == 0) {
					if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type == rook && _Board[Pos.x][Pos.y - i]->FigureColor == FigureColor) {
						Rook* rook = dynamic_cast<Rook*>(_Board[Pos.x][Pos.y - i]);
						if (!rook->isMoved) {
							ListOfMoves.push_back(Position(Pos.x, Pos.y - 2));
							break;
						}
						break;
					}
					else if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type != none && _Board[Pos.x][Pos.y - i]->FigureColor == FigureColor) {
						break;
					}
					else if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type == none && _Board[Pos.x][Pos.y - i]->isCheckedByEnemy) {
						break;
					}
				}
				else {
					if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type == rook && _Board[Pos.x][Pos.y + i]->FigureColor == FigureColor) {
						Rook* rook = dynamic_cast<Rook*>(_Board[Pos.x][Pos.y + i]);
						if (!rook->isMoved) {
							ListOfMoves.push_back(Position(Pos.x, Pos.y + 2));
							break;
						}
						break;
					}
					else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type != none && _Board[Pos.x][Pos.y + i]->FigureColor == FigureColor) {
						break;
					}
					else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type == none && _Board[Pos.x][Pos.y + i]->isCheckedByEnemy) {
						break;
					}
				}
			}
		}
	}

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (Pos.x + i >= 0 && Pos.x + i < Size && Pos.y + j >= 0 && Pos.y + j < Size && !(Pos.x+i == Pos.x && Pos.y+j == Pos.y)) {
				if (!_Board[Pos.x + i][Pos.y + j]->isCheckedByEnemy && _Board[Pos.x + i][Pos.y + j]->Type==none) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y + j));
				}
				if (_Board[Pos.x + i][Pos.y + j]->Type != none && _Board[Pos.x + i][Pos.y + j]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y + j));
				}
			}
		}
	}




	return ListOfMoves;
}

void King::MakeMove(Figure*** board, Position second) {
		board[second.x][second.y] = board[Pos.x][Pos.y];
		board[Pos.x][Pos.y] = new EmptyFigure(Position(Pos.x, Pos.y), Color::noColor);
		if (board[second.x][second.y] != nullptr) {
			board[second.x][second.y]->Pos.x = second.x;
			board[second.x][second.y]->Pos.y = second.y;
		}

}