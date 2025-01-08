#include "Board.h"



class GameState {
public:
	Player WhoMoves;
	Board* _Board;

	GameState();
	GameState(Player whomoves,Board board);

	void ChangeWhoMoves();
	void MakeMove();
	void ShowMoves();
};