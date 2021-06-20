#include <bits/stdc++.h>
#include<conio.h> // To getch() function this header file is required
#include <windows.h> // To get window functionalities, it is required

#include "Gameplayer.h"

using namespace std;

// Default constructor
Gameplayer::Gameplayer()
{
        name ="";
        playingSymbol ="";
        rating = rand();
}

// another constructor
Gameplayer::Gameplayer(int id, string name, string playSymbol)
    {
        this->name = name;
        this->id = id;
        this->playingSymbol = playSymbol;
        this->rating = rand();
    }

// setter function of Name, Id, Symbol private variables
void Gameplayer::setName(string name)
    {
        this->name = name;
    }

void Gameplayer::setId(int id)
    {
        this->id = id;
    }

void Gameplayer::setSymbol(string symbol)
    {
        this->playingSymbol = symbol;
    }


void Gameplayer::gotoxyG(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

// getter function for Name variable
string Gameplayer::getName()
    {
        return this->name;
    }

// this function display player informations
void Gameplayer::show_playerInfo(int col)
    {
        //printf("\n--------Player info--------");
        gotoxyG(col,1);
        cout<<"Player ID       : "<<id<<endl;
        gotoxyG(col,2);
        cout<<"Player Name     : "<<name<<endl;
        gotoxyG(col,3);
        cout<<"Playing Symbol  : "<<playingSymbol<<endl;
        gotoxyG(col,4);
        cout<<"Player Rating   : "<<rating<<endl;
        gotoxyG(col,5);
    }


