#include "Bishop.h"
#include "EmptyFigure.h"


Bishop::Bishop(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::bishop;
	CantMove = false;
	CanBeAttacked = false;
	isCheckedByEnemy = false;
	isZwiazany = false;
	FigureColor = col;
}

Bishop::Bishop() {
	Pos = Position();
	Type = FigureType::bishop;
	CantMove = false;
	CanBeAttacked = false;
	isCheckedByEnemy = false;
	isZwiazany = false;
	FigureColor = noColor;
}

std::list<Position> Bishop::PossibleMoves(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();

	bool ZwiazanieWystapilo = false;
	if (!isZwiazany) {
		//sprawdzenie mozliwych ruchow w 1 przek¹tnej
		for (int k = 0; k < 2; k++) {
			for (int i = 1; i < Size; i++) {
				if (k == 0) {
					if (Pos.x - i >= 0 && Pos.y + i < Size && _Board[Pos.x - i][Pos.y + i]->Type == none) {
						ListOfMoves.push_back(Position(Pos.x - i, Pos.y + i));
					}
					else if (Pos.x - i >= 0 && Pos.y + i < Size && _Board[Pos.x - i][Pos.y + i]->Type != none && _Board[Pos.x - i][Pos.y + i]->FigureColor != FigureColor) {
						ListOfMoves.push_back(Position(Pos.x - i, Pos.y + i));
						//sprawdzenie czy nie wiaze figury
						if (!ZwiazanieWystapilo) {
							for (int j = i + 1; j < Size; j++) {
								if (Pos.x - j >= 0 && Pos.y + j < Size && _Board[Pos.x - j][Pos.y + j]->Type == king && _Board[Pos.x - j][Pos.y + j]->FigureColor != FigureColor) {
									_Board[Pos.x - i][Pos.y + i]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									break;
								}
							}
						}
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
						//sprawdzenie czy nie wiaze figury
						if (!ZwiazanieWystapilo) {
							for (int j = i + 1; j < Size; j++) {
								if (Pos.x - j >= 0 && Pos.y - j >= 0 && _Board[Pos.x - j][Pos.y - j]->Type == king && _Board[Pos.x - j][Pos.y - j]->FigureColor != FigureColor) {
									_Board[Pos.x - i][Pos.y - i]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									break;
								}
							}
						}
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
						//sprawdzenie czy nie wiaze figury
						if (!ZwiazanieWystapilo) {
							for (int j = i + 1; j < Size; j++) {
								if (Pos.x + j < Size && Pos.y + j < Size && _Board[Pos.x + j][Pos.y + j]->Type == king && _Board[Pos.x + j][Pos.y + j]->FigureColor != FigureColor) {
									_Board[Pos.x + i][Pos.y + i]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									break;
								}
							}
						}
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
						//sprawdzenie czy nie wiaze figury
						if (!ZwiazanieWystapilo) {
							for (int j = i + 1; j < Size; j++) {
								if (Pos.x + j < Size && Pos.y - j >= 0 && _Board[Pos.x + j][Pos.y - j]->Type == king && _Board[Pos.x + j][Pos.y - j]->FigureColor != FigureColor) {
									_Board[Pos.x + i][Pos.y - i]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									break;
								}
							}
						}
						break;
					}
					else if (Pos.x + i < Size && Pos.y - i >= 0 && _Board[Pos.x + i][Pos.y - i]->Type != none && _Board[Pos.x + i][Pos.y - i]->FigureColor == FigureColor) {
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

void Bishop::MakeMove(Figure*** board, Position second) {
	if (!CantMove) {
		board[second.x][second.y] = board[Pos.x][Pos.y];
		board[Pos.x][Pos.y] = new EmptyFigure(Position(Pos.x, Pos.y), Color::noColor);
		if (board[second.x][second.y] != nullptr) {
			board[second.x][second.y]->Pos.x = second.x;
			board[second.x][second.y]->Pos.y = second.y;
		}		
	}

}