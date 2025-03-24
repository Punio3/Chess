#include "King.h"
#include "EmptyFigure.h"
#include "Rook.h"

King::King(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::king;
	isChecked = false;
	isMovedOrDoneRoszada = false;
	CanBeAttacked = false;
	CanRoszada = true;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	ValueInPoints = 1000;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = col;
}

King::King() {
	Pos = Position();
	Type = FigureType::king;
	isChecked = false;
	isMovedOrDoneRoszada = false;
	CanBeAttacked = false;
	CanRoszada = true;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	ValueInPoints = 1000;
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
						if (!rook->isMoved && !isMovedOrDoneRoszada) {
							ListOfMoves.push_back(Position(Pos.x, Pos.y - 2));
							break;
						}
						break;
					}
					else if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type != none && _Board[Pos.x][Pos.y - i]->FigureColor == FigureColor) {
						break;
					}
					else if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type == none ) {
						if (FigureColor == white) {
							if (_Board[Pos.x][Pos.y - i]->isCheckedByBlack) break;
						}
						else if (FigureColor == black) {
							if (_Board[Pos.x][Pos.y - i]->isCheckedByWhite) break;
						}
					}
				}
				else {
					if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type == rook && _Board[Pos.x][Pos.y + i]->FigureColor == FigureColor) {
						Rook* rook = dynamic_cast<Rook*>(_Board[Pos.x][Pos.y + i]);
						if (!rook->isMoved && !isMovedOrDoneRoszada) {
							ListOfMoves.push_back(Position(Pos.x, Pos.y + 2));
							break;
						}
						break;
					}
					else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type != none && _Board[Pos.x][Pos.y + i]->FigureColor == FigureColor) {
						break;
					}
					else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type == none ) {
						if (FigureColor == white) {
							if (_Board[Pos.x][Pos.y + i]->isCheckedByBlack) break;
						}
						else if (FigureColor == black) {
							if (_Board[Pos.x][Pos.y + i]->isCheckedByWhite) break;
						}
					}
				}
			}
		}
	}

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (Pos.x + i >= 0 && Pos.x + i < Size && Pos.y + j >= 0 && Pos.y + j < Size && !(Pos.x+i == Pos.x && Pos.y+j == Pos.y)) {
				if ( _Board[Pos.x + i][Pos.y + j]->Type==none) {
					if (FigureColor == white) {
						if (!_Board[Pos.x + i][Pos.y + j]->isCheckedByBlack) ListOfMoves.push_back(Position(Pos.x + i, Pos.y + j));
					}
					else if (FigureColor == black) {
						if (!_Board[Pos.x + i][Pos.y + j]->isCheckedByWhite) ListOfMoves.push_back(Position(Pos.x + i, Pos.y + j));
					}
				}
				if (_Board[Pos.x + i][Pos.y + j]->Type != none) {
					if (_Board[Pos.x + i][Pos.y + j]->FigureColor == FigureColor) {
						ListOfMoves.push_back(Position(Pos.x + i, Pos.y + j));
					}
					else if (_Board[Pos.x + i][Pos.y + j]->FigureColor != FigureColor) {
						if (FigureColor == white) {
							if (!_Board[Pos.x + i][Pos.y + j]->isCheckedByBlack) ListOfMoves.push_back(Position(Pos.x + i, Pos.y + j));
						}
						else if (FigureColor == black) {
							if (!_Board[Pos.x + i][Pos.y + j]->isCheckedByWhite) ListOfMoves.push_back(Position(Pos.x + i, Pos.y + j));
						}
					}

				}
			}
		}
	}




	return ListOfMoves;
}

void King::MakeMove(Figure*** board, Position second) {
		if (!isMovedOrDoneRoszada) {

			if (FigureColor == black) {
				if (second.y - Pos.y == -2) {
					delete(board[0][3]);
					board[0][3] = board[0][0];
					board[0][0] = new EmptyFigure(Position(0, 0), Color::noColor);
					board[0][3]->Pos.x = 0;
					board[0][3]->Pos.y = 3;
				}
				else if (second.y - Pos.y == 2) {
					delete(board[0][5]);
					board[0][5] = board[0][7];
					board[0][7] = new EmptyFigure(Position(0, 7), Color::noColor);
					board[0][5]->Pos.x = 0;
					board[0][5]->Pos.y = 5;
				}
			}
			else {
				if (second.y - Pos.y == -2) {
					delete(board[7][3]);
					board[7][3] = board[7][0];
					board[7][0] = new EmptyFigure(Position(7, 0), Color::noColor);
					board[7][3]->Pos.x = 7;
					board[7][3]->Pos.y = 3;
				}
				else if (second.y - Pos.y == 2) {
					delete(board[7][5]);
					board[7][5] = board[7][7];
					board[7][7] = new EmptyFigure(Position(7, 7), Color::noColor);
					board[7][5]->Pos.x = 7;
					board[7][5]->Pos.y = 5;
				}

			}
			isMovedOrDoneRoszada = true;
		}
		//zwykly ruch krola ( jest wykonywany po sprawdzeniu roszady gdyz wtedy zmieniamy obecny Pos.y i warunki roszady nigdy sie nie spelnialy)
		delete(board[second.x][second.y]);
		board[second.x][second.y] = board[Pos.x][Pos.y];
		board[Pos.x][Pos.y] = new EmptyFigure(Position(Pos.x, Pos.y), Color::noColor);
		if (board[second.x][second.y] != nullptr) {
			board[second.x][second.y]->Pos.x = second.x;
			board[second.x][second.y]->Pos.y = second.y;
		}
}


int King::OcenaHeurystycznaFigury() {



	return 0;
}