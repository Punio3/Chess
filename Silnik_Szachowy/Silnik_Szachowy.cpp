#include <iostream>
#include "GameState.h"
//zwiazanie figury( trzeba dodac mozliwe ruchy gdy jest zwiazany dla krolowej,wiezy,gonca), szachowany krol, 
// ruszanie sie po mozliwych ruchach, pat, mat, punkty figur, logika gry(kto gra,kto ma ruch,czy sie skonczyla gra)
// minmax(alpha,beta), ocena stanu
using namespace std;

void WybierzAkcje(GameState* gmstate) {
    cout << "Podaj akcje:\n1)Ruch\n2)Wyswietl Ruchy\n";
    int akcja;
    cin >> akcja;

    switch (akcja) {
    case 1:
        gmstate->MakeMove();
        break;
    case 2:
        gmstate->ShowMoves();
        break;
    default:
        break;
    }
}

int main()
{
    GameState* _GameState = new GameState();
    _GameState->_Board->DisplayBoard(_GameState->WhoMoves);
    while (true) {
        WybierzAkcje(_GameState);
    }
}


