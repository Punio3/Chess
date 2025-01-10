#include <iostream>
#include "GameState.h"
// Mozliwa optymalizacja( dodanie osobnych zmiennych pol atakowanych przez biale i czarne -> wtedy nie trzeba czyscic pol po kazdej turze
// Dodanie wskaznika na figury zwiazana i jej mozliwe ruchy
// 

// czasami cos zle wiaze figury
// to prawie zrobione -> zwiazanie figury( trzeba dodac mozliwe ruchy gdy jest zwiazany dla krolowej,wiezy,gonca), 
// trzeba dodac usuwanie atakowanych pol jak figura jest zbita
// szachowany krol, 
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


