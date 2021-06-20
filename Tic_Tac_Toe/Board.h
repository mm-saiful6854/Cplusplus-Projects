#include <bits/stdc++.h>
#include "Node.h"
#ifndef BOARD_H
#define BOARD_H

using namespace std;


class Board
{
    public:
        Board();
        int operator [](int position);
        void valueAssign(int pos, int value);
        void display_board_content();

    private:
        Node* head;
        Node* tail;
};

#endif // BOARD_H
