#include "Rook.h"
#include "EmptyFigure.h"


Rook::Rook(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::rook;
	CantMove = false;
	CanBeAttacked = false;
	isCheckedByEnemy = false;
	isMoved = false;
	isZwiazany = false;
	FigureColor = col;
}

Rook::Rook() {
	Pos = Position();
	Type = FigureType::rook;
	CantMove = false;
	CanBeAttacked = false;
	isCheckedByEnemy = false;
	isMoved = false;
	isZwiazany = false;
	FigureColor = noColor;
}

std::list<Position> Rook::PossibleMoves(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();
	bool ZwiazanieWystapilo = false;

	if (!isZwiazany) {
		//sprawdzenie mozliwych ruchow w pionie
		for (int k = 0; k < 2; k++) {
			for (int i = 1; i < Size; i++) {
				if (k == 0) {
					if (Pos.x - i >= 0 && _Board[Pos.x - i][Pos.y]->Type == none) {
						ListOfMoves.push_back(Position(Pos.x - i, Pos.y));
					}
					else if (Pos.x - i >= 0 && _Board[Pos.x - i][Pos.y]->Type != none && _Board[Pos.x - i][Pos.y]->FigureColor != FigureColor) {
						ListOfMoves.push_back(Position(Pos.x - i, Pos.y));
						//sprawdzenie czy nie wiaze figury
						if (!ZwiazanieWystapilo) {
							for (int j = i + 1; j < Size; j++) {
								if (Pos.x - j >= 0 && _Board[Pos.x - i][Pos.y]->Type == king && _Board[Pos.x - i][Pos.y]->FigureColor != FigureColor) {
									_Board[Pos.x - i][Pos.y]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									break;
								}
							}
						}
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
						//sprawdzenie czy nie wiaze figury
						if (!ZwiazanieWystapilo) {
							for (int j = i + 1; j < Size; j++) {
								if (Pos.x + j < Size && _Board[Pos.x + j][Pos.y]->Type == king && _Board[Pos.x + j][Pos.y]->FigureColor != FigureColor) {
									_Board[Pos.x + i][Pos.y]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									break;
								}
							}
						}
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
						//sprawdzenie czy nie wiaze figury
						if (!ZwiazanieWystapilo) {
							for (int j = i + 1; j < Size; j++) {
								if (Pos.y - j >= 0 && _Board[Pos.x][Pos.y - j]->Type == king && _Board[Pos.x][Pos.y - j]->FigureColor != FigureColor) {
									_Board[Pos.x][Pos.y - i]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									break;
								}
							}
						}
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
						//sprawdzenie czy nie wiaze figury
						if (!ZwiazanieWystapilo) {
							for (int j = i + 1; j < Size; j++) {
								if (Pos.y + j < Size && _Board[Pos.x][Pos.y + j]->Type != king && _Board[Pos.x][Pos.y + j]->FigureColor != FigureColor) {
									_Board[Pos.x][Pos.y + i]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									break;
								}
							}
						}
						break;
					}
					else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type != none && _Board[Pos.x][Pos.y + i]->FigureColor == FigureColor) {
						break;
					}
				}
			}
		}
	}

	for (Position pos : ListOfMoves) {
		_Board[pos.x][pos.y]->CanBeAttacked = true;
	}

	return ListOfMoves;
}

void Rook::MakeMove(Figure*** board, Position second) {
	if (!CantMove) {
		board[second.x][second.y] = board[Pos.x][Pos.y];
		board[Pos.x][Pos.y] = new EmptyFigure(Position(Pos.x, Pos.y), Color::noColor);
		if (board[second.x][second.y] != nullptr) {
			board[second.x][second.y]->Pos.x = second.x;
			board[second.x][second.y]->Pos.y = second.y;
		}
		if (!isMoved) isMoved = true;
	}

}