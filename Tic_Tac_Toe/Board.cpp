#include <bits/stdc++.h>

#include "Node.h"
#include "Board.h"

using namespace std;

Board::Board()
{
    head = NULL;
    for(int i=0; i<9; i++)
    {
        Node* new_node = new Node();
        new_node->data = 2;
        new_node->next = NULL;

        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = tail->next;
        }
    }
}



// Operator overloading is done here, for making easy accessing.
int Board::operator [](int position)
{
    int cnt = 1;
    Node* tail = head;
    for(; tail!=NULL; tail=(tail->next))
    {
        if(cnt == position)
        {
            return tail->data;
        }
        cnt++;
    }

    return 0;
}


// value assgin on position. That updates the linked list content
void Board::valueAssign(int pos, int value)
{
    int cnt = 1;
    Node* tail = head;
    for(; tail!=NULL; tail=(tail->next))
    {
        if(cnt == pos)
        {
            tail->data = value;
        }
        cnt++;
    }

}

// for displaying the linked list content
void Board::display_board_content()
{
    Node* tail = head;
    for(; tail!=NULL; tail=(tail->next))
    {
        cout<<tail->data<<" ";
    }
    cout<<endl;
}

















