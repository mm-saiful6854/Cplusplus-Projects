#include "Tic_Tac_Toe.h"
#include<bits/stdc++.h>


using namespace std;



// default constructor
Tic_Tac_Toe::Tic_Tac_Toe()
{
    tttboard = Board();
    flag =0;

    welcome();
    menu();
}

// This function for welcome Screen
void Tic_Tac_Toe::welcome()
{
    gotoxy(50,10);
    printf("Welcome to this Tic Tac Toe Game\n");
    gotoxy(50,13);
    printf("     .....press any key to continue\n");
    getch();
}



// this function is for creating Two player instances of GamePlayer class. Required variables: Name, Id, Symbol.
void Tic_Tac_Toe::playerEntry(string ss)
{
    system("cls");
    gotoxy(10,5);
    int id;
    string name;

    if(ss == "self")
    {
        gotoxy(40,10);
        printf("--------ENTER YOUR INFO--------\n");
        gotoxy(40,11);
        printf("Player ID    : ");
        cin>>id;
        gotoxy(40,12);
        printf("Player Name  : ");
        cin>>name;
        if(subChoice==1)
        {
            player[1].setName(name);
            player[1].setId(id);
            player[1].setSymbol("X");


        }
        else
        {
            player[1].setName(name);
            player[1].setId(id);
            player[1].setSymbol("O");
        }

    }

    else if(ss == "friend")
    {
        gotoxy(40,10);
        printf("--------ENTER FRIEND INFO--------\n");
        gotoxy(40,11);
        printf("Player ID    : ");
        cin>>id;
        gotoxy(40,12);
        printf("Player Name  : ");
        cin>>name;
        if(subChoice == 2)
        {
            player[2].setName(name);
            player[2].setId(id);
            player[2].setSymbol("X");
        }

        else
        {
            player[2].setName(name);
            player[2].setId(id);
            player[2].setSymbol("O");

        }
    }

    else
    {
        id = 00;
        name = "Computer";
        if(subChoice==1)
            Gameplayer comp = Gameplayer(id,name,"O");
        else
            Gameplayer comp = Gameplayer(id,name,"X");

    }


}



// Create initial menu screen after welcome screen
void Tic_Tac_Toe::menu()
{

    system("cls");
    gotoxy(40,10);
    printf("--------MENU--------\n");
    gotoxy(40,11);
    printf("1 : Play with Computer\n");
    gotoxy(40,12);
    printf("2 : Play with Friend\n");
    gotoxy(40,13);
    printf("3 : Exit\n");
    gotoxy(40,14);
    printf("Enter your choice:>");
    //gotoxy(40,15);
    scanf("%d",&choice);

    if(choice == 3)
        exit(1);

    submenu();

}


// It prompts after menu screen. This submenu appears for collecting more information of player
void Tic_Tac_Toe::submenu()
{
    system("cls");
    gotoxy(40,10);
    printf("--------SUB-MENU--------\n");
    gotoxy(40,11);
    printf("1 : Play with X\n");
    gotoxy(40,12);
    printf("2 : Play with O\n");
    gotoxy(40,13);
    printf("3 : Back to Main-Menu\n");
    gotoxy(40,14);
    printf("Choose your favorite option:>");
    scanf("%d",&subChoice);

    if(subChoice == 3){
        choice = 0;
        subChoice = 0;
        menu();
        return ;
    }


    if(choice == 1)
    {
        playerEntry("self");
        playerEntry("comp");

    }
    else if(choice == 2)
    {
        playerEntry("self");
        playerEntry("friend");
    }


}

// this is special function of windows.h header file. It sets the cursor to a given coordinate(x,y).
void Tic_Tac_Toe::gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

// It draw board on console
void Tic_Tac_Toe::draw_board()
{
    int j;

    for(j=9; j<=16; j++)
    {
        gotoxy(35,j);
        printf("|       |");
    }
    gotoxy(28,11);
    printf("-----------------------");
    gotoxy(28,14);
    printf("-----------------------");

    for(j=1; j<=9; j++)
    {
        if(tttboard[j] == 3)
            put_X_O('X',j);
        else if(tttboard[j] == 5)
            put_X_O('O',j);
    }
}

// It helps to put 'X' or 'O' symbol on board created by draw_board() function.
void Tic_Tac_Toe::put_X_O(char ch,int pos)
{
    int m;
    int x = 31, y = 10;

    m = pos;

    if(m > 3)
    {
        while(m > 3)
        {
            y += 3;
            m -= 3;
        }
    }
    if(pos % 3 == 0)
        x += 16;
    else
    {
        pos %= 3;
        pos--;
        while(pos)
        {
            x+=8;
            pos--;
        }
    }
    gotoxy(x,y);
    printf("%c",ch);
}


// It gives initial information of two players on top of the game screen
void Tic_Tac_Toe::gameInfo()
{
    cout<<"--------First Player Info-----------"<<endl;
    player[1].show_playerInfo(1);
    cout<<"------------------------------------"<<endl;
    if(choice==2)
    {
        gotoxy(44,0);
        cout<<"--------Second Player Info-----------"<<endl;
        player[2].show_playerInfo(44);
        gotoxy(44,5);
        cout<<"------------------------------------"<<endl;
    }
    else
    {
        gotoxy(44,0);
        cout<<"--------Second Player Info-----------"<<endl;
        gotoxy(44,1);
        cout<<"Computer-Brain"<<endl;
        gotoxy(44,5);
        cout<<"------------------------------------"<<endl;
    }

}

// This function can be called a starting-point of this game
void Tic_Tac_Toe::start()
{
    system("cls");
    gameInfo();
    turn = 1; // Initialization of "turn" variable. this variable will increase gradually upto 9. If the value of "turn" variable is greater than 9, then game will be draw.
    switch(subChoice)
    {
    case 1:
        fplayer = 1;
        splayer = 0;
        playerTurn();
        break;
    case 2:
        fplayer = 0;
        splayer = 1;
        secondPlayer();
        break;
    case 3:
        menu();
        break;
    }

}


int Tic_Tac_Toe::playerChoice()
{
    int pos = 0;
    int col = 28;
    int row = 9;
    //char key = getch();
    int value = 0;

    gotoxy(col,row);

    while(value != 13)
    {
        //printf("in");
        switch(getch())
        {
        case 75:  /// left key <-
            pos--;
            if(pos<0){
                pos = 0;

            }

            if(pos<=2)
                row =9;
            else if(pos>2 && pos <=5)
                row =12;
            else if(pos<=8)
                row = 15;

            if(pos==2 || pos ==5 || pos ==8)
                col = 44;
            else if(col!=28)
                col -=8;


            gotoxy(col,row);
            break;
        case 77:  /// right key ->
            pos++;
            if(pos>8)
                pos = 8;

            if(pos<=2)
                row =9;
            else if(pos>2 && pos <=5)
                row =12;
            else if(pos<=8)
                row = 15;

            if(pos%3==0)
                col = 28;
            else if(col<44)
                col +=8;


            gotoxy(col,row);
            break;
        }

        char key = getch();

        value =  key;
        //cout<<value<<endl;
    }


    return pos+1;

}




void Tic_Tac_Toe::playerTurn()
{
    system("cls");
    gameInfo();

    int pos;
    check_draw();
    draw_board();

    gotoxy(3,9);
    cout<<player[1].getName();
    printf(" Turn : \n");
    printf("(press enter to select)");
    gotoxy(28,9);
    getch();
    pos = playerChoice();
    pHistory[1].push(pos);


    if(tttboard[pos] != 2)
    {
        playerTurn();
    }
    if(pos == posswin(fplayer))
    {

        go(pos);
        draw_board();
        gotoxy(30,20);
        cout<<player[1].getName();
        printf(" Wins");
        getch();

        exit(0);
    }

    go(pos);
    draw_board();
    secondPlayer();

}

// Second player turns
void Tic_Tac_Toe::secondPlayer()
{
    if(choice==1)
    {
        int md2 = makeDecision2();
        int md4 = makeDecision4();
        if(posswin(splayer))
        {
            go(posswin(splayer));
            flag = 1;
        }
        else if(posswin(fplayer))
            go(posswin(fplayer));
        else if(md2)
            go(md2);
        else
            go(md4);

        draw_board();


        if(flag)
        {
            gotoxy(30,20);
            printf("Computer wins");
            getch();
        }
        else
            playerTurn();


    }
    else if(choice==2)
    {
        system("cls");
        gameInfo();

        int pos;
        check_draw();
        draw_board();

        gotoxy(3,9);
        cout<<player[2].getName();
        printf(" Turn : \n");
        printf("(press enter to select)");
        gotoxy(28,9);
        getch();
        pos = playerChoice();
        pHistory[2].push(pos);

//        gotoxy(30,18);
//        cout<<player[2].getName();
//        printf(" Turn :> ");
//        scanf("%d",&pos);

        if(tttboard[pos] != 2)
        {
            playerTurn();
        }


        if(pos == posswin(splayer))
        {

            go(pos);
            draw_board();
            gotoxy(30,20);
            cout<<player[2].getName();
            printf(" Wins");
            getch();
            exit(0);
        }

        go(pos);
        draw_board();
        playerTurn();
    }

}




// It helps (player==computer) to make decision on Cross (+) position

int Tic_Tac_Toe::makeDecision2()
{
    if(tttboard[5] == 2)
        return 5;
    if(tttboard[2] == 2)
        return 2;
    if(tttboard[4] == 2)
        return 4;
    if(tttboard[6] == 2)
        return 6;
    if(tttboard[8] == 2)
        return 8;
    return 0;
}
// It helps (player==computer) to make decision on remaining position
int Tic_Tac_Toe::makeDecision4()
{
    if(tttboard[1] == 2)
        return 1;
    if(tttboard[3] == 2)
        return 3;
    if(tttboard[7] == 2)
        return 7;
    if(tttboard[9] == 2)
        return 9;
    return 0;
}

// calculate all possible way for confirming winning possibility
int Tic_Tac_Toe::posswin(int p)
{
    int i;
    int check_val;

    if(p == 1)
        check_val = 18;
    else
        check_val = 50;

    i = 1;
    while(i<=9)//row check
    {
        if(tttboard[i] * tttboard[i+1] * tttboard[i+2] == check_val)
        {
            if(tttboard[i] == 2)
                return i;
            if(tttboard[i+1] == 2)
                return i+1;
            if(tttboard[i+2] == 2)
                return i+2;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)//column check
    {
        if(tttboard[i] * tttboard[i+3] * tttboard[i+6] == check_val)
        {
            if(tttboard[i] == 2)
                return i;
            if(tttboard[i+3] == 2)
                return i+3;
            if(tttboard[i+6] == 2)
                return i+6;
        }
        i++;
    }

    if(tttboard[1] * tttboard[5] * tttboard[9] == check_val)
    {
        if(tttboard[1] == 2)
            return 1;
        if(tttboard[5] == 2)
            return 5;
        if(tttboard[9] == 2)
            return 9;
    }

    if(tttboard[3] * tttboard[5] * tttboard[7] == check_val)
    {
        if(tttboard[3] == 2)
            return 3;
        if(tttboard[5] == 2)
            return 5;
        if(tttboard[7] == 2)
            return 7;
    }
    return 0;
}

// modify board coordinate value according to given turn
void Tic_Tac_Toe::go(int n)
{
    if(turn % 2)
        tttboard.valueAssign(n,3);
    else
        tttboard.valueAssign(n,5);
    turn++;
}

// Checking, if the game is draw or not.
void Tic_Tac_Toe::check_draw()
{
    if(turn > 9)
    {
        draw_board();
        gotoxy(30,20);
        printf("Game Draw");
        getch();
        exit(0);
    }
}
