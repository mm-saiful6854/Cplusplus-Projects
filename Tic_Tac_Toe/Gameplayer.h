
#include<bits/stdc++.h>

#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

using namespace std;

class Gameplayer
{
    public:
        Gameplayer();
        Gameplayer(int id, string name, string playSymbol);
        void setName(string name);
        void setId(int id);
        void setSymbol(string symbol);
        string getName();
        void show_playerInfo(int col);
        void gotoxyG(int x,int y);


    private:
        int id;
        string name;
        string playingSymbol;
        int rating;
        COORD coord;
};

#endif // GAMEPLAYER_H
