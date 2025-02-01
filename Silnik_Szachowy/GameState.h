#include "Board.h"

enum Status {
	pat,
	mat,
	during
};


class GameState {
public:
	Player WhoMoves;
	Board* _Board;
	Status status;

	GameState();
	GameState(Player whomoves,Board board);
	GameState(Status status, Player whomoves, Board* board);
	~GameState();

	void ChangeWhoMoves();
	void MakeMove();
	void ShowMoves();
	void CheckPatAndMat();
	void CreateNewBoard();
	GameState* copyGameState();
};