#include "Bishop.h"
#include "EmptyFigure.h"
#include "King.h"

Bishop::Bishop(Position pos, Color col) {
	Pos = pos;
	Type = FigureType::bishop;
	CanBeAttacked = false;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	ValueInPoints = 3;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = col;
}

Bishop::Bishop() {
	Pos = Position();
	Type = FigureType::bishop;
	CanBeAttacked = false;
	isCheckedByWhite = false;
	isCheckedByBlack = false;
	isZwiazany = false;
	ValueInPoints = 3;
	AttackedMovesWhenIsZwiazany = std::list<Position>();
	FigureColor = noColor;
}

std::list<Position> Bishop::PossibleMoves(Figure*** _Board, int Size) {
	std::list<Position> ListOfMoves = std::list<Position>();

	bool ZwiazanieWystapilo = false;

	//sprawdzenie mozliwych ruchow w 1 przek¹tnej
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i < Size; i++) {
			if (k == 0) {
				if (Pos.x - i >= 0 && Pos.y + i < Size && _Board[Pos.x - i][Pos.y + i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y + i));
				}
				else if (Pos.x - i >= 0 && Pos.y + i < Size && _Board[Pos.x - i][Pos.y + i]->Type == king && _Board[Pos.x - i][Pos.y + i]->FigureColor != FigureColor) {
					King* king = dynamic_cast<King*>(_Board[Pos.x - i][Pos.y + i]);
					king->isChecked = true;
					//dodanie pol po ktorych atakuje figura przeciwnego krola
					for (int j = 0; j < i; j++) {
						king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x - j, Pos.y + j));
					}
					break;
				}
				else if (Pos.x - i >= 0 && Pos.y + i < Size && _Board[Pos.x - i][Pos.y + i]->Type != none && _Board[Pos.x - i][Pos.y + i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y + i));
					//sprawdzenie czy nie wiaze figury
					if (!ZwiazanieWystapilo) {
						for (int j = i + 1; j < Size; j++) {
							if (Pos.x - j >= 0 && Pos.y + j < Size) {
								if (_Board[Pos.x - j][Pos.y + j]->Type == king && _Board[Pos.x - j][Pos.y + j]->FigureColor != FigureColor) {
									_Board[Pos.x - i][Pos.y + i]->isZwiazany = true;
									ZwiazanieWystapilo = true;

									//dodanie do zwiazanej figury po jakich polach atakuje wroga figura
									for (int z = 0; z < j; z++) {
										_Board[Pos.x - i][Pos.y + i]->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x - z, Pos.y + z));
									}
									break;
								}
								else if (_Board[Pos.x - j][Pos.y + j]->Type != none) break;
							}
						}
					}
					break;
				}
				else if (Pos.x - i >= 0 && Pos.y + i < Size && _Board[Pos.x - i][Pos.y + i]->Type != none && _Board[Pos.x - i][Pos.y + i]->FigureColor == FigureColor) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y + i));
					break;
				}
			}
			else {
				if (Pos.x - i >= 0 && Pos.y - i >= 0 && _Board[Pos.x - i][Pos.y - i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y - i));
				}
				else if (Pos.x - i >= 0 && Pos.y - i >= 0 && _Board[Pos.x - i][Pos.y - i]->Type == king && _Board[Pos.x - i][Pos.y - i]->FigureColor != FigureColor) {
					King* king = dynamic_cast<King*>(_Board[Pos.x - i][Pos.y - i]);
					king->isChecked = true;
					//dodanie pol po ktorych atakuje figura przeciwnego krola
					for (int j = 0; j < i; j++) {
						king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x - j, Pos.y - j));
					}
					break;
				}
				else if (Pos.x - i >= 0 && Pos.y - i >= 0 && _Board[Pos.x - i][Pos.y - i]->Type != none && _Board[Pos.x - i][Pos.y - i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y - i));
					//sprawdzenie czy nie wiaze figury
					if (!ZwiazanieWystapilo) {
						for (int j = i + 1; j < Size; j++) {
							if (Pos.x - j >= 0 && Pos.y - j >= 0) {
								if (_Board[Pos.x - j][Pos.y - j]->Type == king && _Board[Pos.x - j][Pos.y - j]->FigureColor != FigureColor) {
									_Board[Pos.x - i][Pos.y - i]->isZwiazany = true;
									ZwiazanieWystapilo = true;

									//dodanie do zwiazanej figury po jakich polach atakuje wroga figura
									for (int z = 0; z < j; z++) {
										_Board[Pos.x - i][Pos.y - i]->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x - z, Pos.y - z));
									}
									break;
								}
								else if (_Board[Pos.x - j][Pos.y - j]->Type != none) break;
							}
						}
					}
					break;
				}
				else if (Pos.x - i >= 0 && Pos.y - i >= 0 && _Board[Pos.x - i][Pos.y - i]->Type != none && _Board[Pos.x - i][Pos.y - i]->FigureColor == FigureColor) {
					ListOfMoves.push_back(Position(Pos.x - i, Pos.y - i));
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
				else if (Pos.x + i < Size && Pos.y + i < Size && _Board[Pos.x + i][Pos.y + i]->Type == king && _Board[Pos.x + i][Pos.y + i]->FigureColor != FigureColor) {
					King* king = dynamic_cast<King*>(_Board[Pos.x + i][Pos.y + i]);
					king->isChecked = true;
					//dodanie pol po ktorych atakuje figura przeciwnego krola
					for (int j = 0; j < i; j++) {
						king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x + j, Pos.y + j));
					}
					break;
				}
				else if (Pos.x + i < Size && Pos.y + i < Size && _Board[Pos.x + i][Pos.y + i]->Type != none && _Board[Pos.x + i][Pos.y + i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y + i));
					//sprawdzenie czy nie wiaze figury
					if (!ZwiazanieWystapilo) {
						for (int j = i + 1; j < Size; j++) {
							if (Pos.x + j < Size && Pos.y + j < Size) {
								if (_Board[Pos.x + j][Pos.y + j]->Type == king && _Board[Pos.x + j][Pos.y + j]->FigureColor != FigureColor) {
									_Board[Pos.x + i][Pos.y + i]->isZwiazany = true;
									ZwiazanieWystapilo = true;

									//dodanie do zwiazanej figury po jakich polach atakuje wroga figura
									for (int z = 0; z < j; z++) {
										_Board[Pos.x + i][Pos.y + i]->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x + z, Pos.y + z));
									}
									break;
								}
								else if (_Board[Pos.x + j][Pos.y + j]->Type != none) break;
							}
						}
					}
					break;
				}
				else if (Pos.x + i < Size && Pos.y + i < Size && _Board[Pos.x + i][Pos.y + i]->Type != none && _Board[Pos.x + i][Pos.y + i]->FigureColor == FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y + i));
					break;
				}
			}
			else {
				if (Pos.x + i < Size && Pos.y - i >= 0 && _Board[Pos.x + i][Pos.y - i]->Type == none) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y - i));
				}
				else if (Pos.x + i < Size && Pos.y - i >= 0 && _Board[Pos.x + i][Pos.y - i]->Type == king && _Board[Pos.x + i][Pos.y - i]->FigureColor != FigureColor) {
					King* king = dynamic_cast<King*>(_Board[Pos.x + i][Pos.y - i]);
					king->isChecked = true;
					//dodanie pol po ktorych atakuje figura przeciwnego krola
					for (int j = 0; j < i; j++) {
						king->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x + j, Pos.y - j));
					}
					break;
				}
				else if (Pos.x + i < Size && Pos.y - i >= 0 && _Board[Pos.x + i][Pos.y - i]->Type != none && _Board[Pos.x + i][Pos.y - i]->FigureColor != FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y - i));
					//sprawdzenie czy nie wiaze figury
					if (!ZwiazanieWystapilo) {
						for (int j = i + 1; j < Size; j++) {
							if (Pos.x + j < Size && Pos.y - j >= 0) {
								if (_Board[Pos.x + j][Pos.y - j]->Type == king && _Board[Pos.x + j][Pos.y - j]->FigureColor != FigureColor) {
									_Board[Pos.x + i][Pos.y - i]->isZwiazany = true;
									ZwiazanieWystapilo = true;

									//dodanie do zwiazanej figury po jakich polach atakuje wroga figura
									for (int z = 0; z < j; z++) {
										_Board[Pos.x + i][Pos.y - i]->AttackedMovesWhenIsZwiazany.push_back(Position(Pos.x + z, Pos.y - z));
									}
									break;
								}
								else if (_Board[Pos.x + j][Pos.y - j]->Type != none) break;
							}
						}
					}
					break;
				}
				else if (Pos.x + i < Size && Pos.y - i >= 0 && _Board[Pos.x + i][Pos.y - i]->Type != none && _Board[Pos.x + i][Pos.y - i]->FigureColor == FigureColor) {
					ListOfMoves.push_back(Position(Pos.x + i, Pos.y - i));
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

void Bishop::MakeMove(Figure*** board, Position second) {

	delete(board[second.x][second.y]);
	board[second.x][second.y] = board[Pos.x][Pos.y];
	board[Pos.x][Pos.y] = new EmptyFigure(Position(Pos.x, Pos.y), Color::noColor);
	if (board[second.x][second.y] != nullptr) {
		board[second.x][second.y]->Pos.x = second.x;
		board[second.x][second.y]->Pos.y = second.y;
	}		
	

}

int Bishop::OcenaHeurystycznaFigury() {



	return 0;
}