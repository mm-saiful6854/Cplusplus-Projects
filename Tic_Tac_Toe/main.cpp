#include <bits/stdc++.h>
#include<conio.h> // To getch() function this header file is required
#include <windows.h> // To get window functionalities, it is required


// header files
#include "Node.h"
#include "Board.h"
#include "Gameplayer.h"
#include "Tic_Tac_Toe.h"

using namespace std;

int main()
{
    // Object creation of Tic_Tac_Toe class
    Tic_Tac_Toe ttt = Tic_Tac_Toe();
    ttt.start(); // Tic_Tac_Toe game starts based on ttt instance.
    return 0;
}
