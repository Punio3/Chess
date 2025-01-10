class Position {
public:
	int x;
	int y;

	Position();
	Position(int x, int y);

	bool ComparePositions(Position other);
};