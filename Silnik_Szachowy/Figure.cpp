#include "Figure.h"

Figure::Figure() {
	Pos = Position();
	Type = FigureType::none;
	CantMove = false;
	CanBeAttacked = false;
	FigureColor = noColor;
}