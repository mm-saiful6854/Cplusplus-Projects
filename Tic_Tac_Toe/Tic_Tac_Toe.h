#include<bits/stdc++.h>
#include<conio.h> // To getch() function this header file is required
#include <windows.h> // To get window functionalities, it is required
#include "Board.h"
#include "Gameplayer.h"


#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

using namespace std;


class Tic_Tac_Toe
{
    public:
        Tic_Tac_Toe();
        void welcome();
        void playerEntry(string ss);
        void menu();
        void submenu();
        void gotoxy(int x,int y);
        void draw_board();
        void put_X_O(char ch,int pos);
        void gameInfo();
        void start();
        void playerTurn();
        void secondPlayer();
        int makeDecision2();
        int makeDecision4();
        int posswin(int p);
        void go(int n);
        void check_draw();
        int playerChoice();


    private:
        stack<int>pHistory[3];
        Board tttboard;
        int choice, subChoice;
        int turn;
        COORD coord;
        int fplayer,splayer,flag;
        Gameplayer player[3];
};

#endif // TIC_TAC_TOE_H
