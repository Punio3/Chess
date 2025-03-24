#include "Position.h"

Position::Position() {
	x = 0;
	y = 0;
}

Position::Position(int posX, int posY) {
	x = posX;
	y = posY;
}

bool Position::ComparePositions(Position other) {
	if (x == other.x) {
		if (y == other.y) {
			return true;
		}
	}

	return false;
}