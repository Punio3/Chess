#include "Figure.h"

Figure::Figure() {
	Pos = Position();
	Type = FigureType::none;
	CantMove = false;
	CanBeAttacked = false;
	isZwiazany = false;
	FigureColor = noColor;
}