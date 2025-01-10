#include "Figure.h"

Figure::Figure() {
	Pos = Position();
	Type = FigureType::none;
	CantMove = false;
	CanBeAttacked = false;
	isZwiazany = false;
	AttackedMovesWhenIsZwiazany= std::list<Position>();
	FigureColor = noColor;
}

std::list<Position> Figure::GiveListOfDuplicateFields(std::list<Position> first, std::list<Position> second) {
	std::list<Position> DuplicateList = std::list<Position>();

	for (Position _firstPosition : first) {
		for (Position _secondPosition : second) {
			if (_firstPosition.ComparePositions(_secondPosition)) {
				DuplicateList.push_back(Position(_firstPosition.x, _firstPosition.y));
				break;
			}
		}
	}

	return DuplicateList;
}