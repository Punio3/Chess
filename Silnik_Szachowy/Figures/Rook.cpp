#include "Rook.h"
#include "EmptyFigure.h"
#include "King.h"


Rook::Rook(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::rook;
	CanBeAttacked = false;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isMoved = false;
	isZwiazany = false;
	ValueInPoints = 5;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = col;
}

Rook::Rook() {
	Pos = Position();
	Type = FigureType::rook;
	CanBeAttacked = false;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isMoved = false;
	isZwiazany = false;
	ValueInPoints = 5;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = noColor;
}

std::list<Position> Rook::PossibleMoves(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();
	bool ZwiazanieWystapilo = false;

	//sprawdzenie mozliwych ruchow w pionie
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i < Size; i++) {
			if (k == 0) {
				if (Pos.x - i >= 0 && _Board[Pos.x - i][Pos.y]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y));
				}
				else if (Pos.x - i >= 0 && _Board[Pos.x - i][Pos.y]->Type == king && _Board[Pos.x - i][Pos.y]->FigureColor != FigureColor) {
					King* king = dynamic_cast<King*>(_Board[Pos.x - i][Pos.y]);
					king->isChecked = true;
					//dodanie pol po ktorych atakuje figura przeciwnego krola
					for (int j = 0; j < i; j++) {
						king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x - j, Pos.y));
					}
					break;
				}
				else if (Pos.x - i >= 0 && _Board[Pos.x - i][Pos.y]->Type != none && _Board[Pos.x - i][Pos.y]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y));
					//sprawdzenie czy nie wiaze figury
					if (!ZwiazanieWystapilo) {
						for (int j = i + 1; j < Size; j++) {
							if (Pos.x - j >= 0) {
								if (_Board[Pos.x - j][Pos.y]->Type == king && _Board[Pos.x - j][Pos.y]->FigureColor != FigureColor) {
									_Board[Pos.x - i][Pos.y]->isZwiazany = true;
									ZwiazanieWystapilo = true;

									//dodanie pol po ktorych atakuje figura dla atakowanej figury
									for (int z = 0; z < j; z++) {
										_Board[Pos.x - i][Pos.y]->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x - z, Pos.y));
									}
									break;
								}
								else if (_Board[Pos.x - j][Pos.y]->Type != none) break;
							}
						}
					}
					break;
				}
				else if (Pos.x - i >= 0 && _Board[Pos.x - i][Pos.y]->Type != none && _Board[Pos.x - i][Pos.y]->FigureColor == FigureColor) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y));
					break;
				}
			}
			else {
				if (Pos.x + i < Size && _Board[Pos.x + i][Pos.y]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y));
				}
				else if (Pos.x + i < Size && _Board[Pos.x + i][Pos.y]->Type == king && _Board[Pos.x + i][Pos.y]->FigureColor != FigureColor) {
					King* king = dynamic_cast<King*>(_Board[Pos.x + i][Pos.y]);
					king->isChecked = true;
					//dodanie pol po ktorych atakuje figura przeciwnego krola
					for (int j = 0; j < i; j++) {
						king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x + j, Pos.y));
					}
					break;
				}
				else if (Pos.x + i < Size && _Board[Pos.x + i][Pos.y]->Type != none && _Board[Pos.x + i][Pos.y]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y));
					//sprawdzenie czy nie wiaze figury
					if (!ZwiazanieWystapilo) {
						for (int j = i + 1; j < Size; j++) {
							if (Pos.x + j < Size) {
								if (_Board[Pos.x + j][Pos.y]->Type == king && _Board[Pos.x + j][Pos.y]->FigureColor != FigureColor) {
									_Board[Pos.x + i][Pos.y]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									//dodanie pol po ktorych atakuje figura dla atakowanej figury
									for (int z = 0; z < j; z++) {
										_Board[Pos.x + i][Pos.y]->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x + z, Pos.y));
									}
									break;
								}
								else if (_Board[Pos.x + j][Pos.y]->Type != none) break;
							}
						}
					}
					break;
				}
				else if (Pos.x + i < Size && _Board[Pos.x + i][Pos.y]->Type != none && _Board[Pos.x + i][Pos.y]->FigureColor == FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y));
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
				else if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type == king && _Board[Pos.x][Pos.y - i]->FigureColor != FigureColor) {
					King* king = dynamic_cast<King*>(_Board[Pos.x][Pos.y - i]);
					king->isChecked = true;
					//dodanie pol po ktorych atakuje figura przeciwnego krola
					for (int j = 0; j < i; j++) {
						king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y - j));
					}
					break;
				}
				else if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type != none && _Board[Pos.x][Pos.y - i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x, Pos.y - i));
					//sprawdzenie czy nie wiaze figury
					if (!ZwiazanieWystapilo) {
						for (int j = i + 1; j < Size; j++) {
							if (Pos.y - j >= 0) {
								if (_Board[Pos.x][Pos.y - j]->Type == king && _Board[Pos.x][Pos.y - j]->FigureColor != FigureColor) {
									_Board[Pos.x][Pos.y - i]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									//dodanie pol po ktorych atakuje figura dla atakowanej figury
									for (int z = 0; z < j; z++) {
										_Board[Pos.x][Pos.y - i]->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y - z));
									}
									break;
								}
								else if (_Board[Pos.x][Pos.y - j]->Type != none) break;
							}
						}
					}
					break;
				}
				else if (Pos.y - i >= 0 && _Board[Pos.x][Pos.y - i]->Type != none && _Board[Pos.x][Pos.y - i]->FigureColor == FigureColor) {
					ListOfMoves.push_back(Position(Pos.x, Pos.y - i));
					break;
				}
			}
			else {
				if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x, Pos.y + i));
				}
				else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type == king && _Board[Pos.x][Pos.y + i]->FigureColor != FigureColor) {
					King* king = dynamic_cast<King*>(_Board[Pos.x][Pos.y + i]);
					king->isChecked = true;
					//dodanie pol po ktorych atakuje figura przeciwnego krola
					for (int j = 0; j < i; j++) {
						king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y + j));
					}
					break;
				}
				else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type != none && _Board[Pos.x][Pos.y + i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x, Pos.y + i));
					//sprawdzenie czy nie wiaze figury
					if (!ZwiazanieWystapilo) {
						for (int j = i + 1; j < Size; j++) {
							if (Pos.y + j < Size) {
								if (_Board[Pos.x][Pos.y + j]->Type == king && _Board[Pos.x][Pos.y + j]->FigureColor != FigureColor) {
									_Board[Pos.x][Pos.y + i]->isZwiazany = true;
									ZwiazanieWystapilo = true;
									//dodanie pol po ktorych atakuje figura dla atakowanej figury
									for (int z = 0; z < j; z++) {
										_Board[Pos.x][Pos.y + i]->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x, Pos.y + z));
									}
									break;
								}
								else if (_Board[Pos.x][Pos.y + j]->Type != none) break;
							}
						}
					}
					break;
				}
				else if (Pos.y + i < Size && _Board[Pos.x][Pos.y + i]->Type != none && _Board[Pos.x][Pos.y + i]->FigureColor == FigureColor) {
					ListOfMoves.push_back(Position(Pos.x, Pos.y + i));
					break;
				}
			}
		}
	}


	if (isZwiazany) {
		ListOfMoves = GiveListOfDuplicateFields(ListOfMoves, AttackedMovesWhenIsZwiazany);
	}

	return ListOfMoves;
}

void Rook::MakeMove(Figure*** board, Position second) {

	delete(board[second.x][second.y]);
	board[second.x][second.y] = board[Pos.x][Pos.y];
	board[Pos.x][Pos.y] = new EmptyFigure(Position(Pos.x, Pos.y), Color::noColor);
	if (board[second.x][second.y] != nullptr) {
		board[second.x][second.y]->Pos.x = second.x;
		board[second.x][second.y]->Pos.y = second.y;
	}
	if (!isMoved) isMoved = true;
	

}



int Rook::OcenaHeurystycznaFigury() {



	return 0;
}