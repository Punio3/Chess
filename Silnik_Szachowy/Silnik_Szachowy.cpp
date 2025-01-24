#include <iostream>
#include "GameState.h"
// Mozliwa optymalizacja( dodanie osobnych zmiennych pol atakowanych przez biale i czarne -> wtedy nie trzeba czyscic pol po kazdej turze
// Dodanie wskaznika na figury zwiazana i jej mozliwe ruchy
// 

// szachowany krol ( trzeba sprawdzic figury gdzie atakuja krola, bo cos sie nie szachuje(Chyba juz git trzeba bylo zmienic kolejnosc wpossiblemoves, nie wiem gdzie sprawdzac ruchy na szachu krola), 
// ruszanie sie po mozliwych ruchach(zrobione raczej), pat, mat, punkty figur, logika gry(kto gra,kto ma ruch,czy sie skonczyla gra)
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


