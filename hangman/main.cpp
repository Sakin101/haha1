#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<string>
using namespace std;
COORD coord = { 0,0 };
char places[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin();
int board();
int rule();
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hangman(int ctr)
{



    for (int i = 0; i < 6; i++)
    {
        gotoxy(60 + i, 4);
        cout << "_";

    }
    if (ctr >= 1)
    {
        gotoxy(63, 5);
        cout << "|";
    }
    if (ctr >= 2)
    {
        gotoxy(63, 6);
        cout << "0";
    }
    if (ctr >= 3)
    {
        gotoxy(63, 7);
        cout << "|";
    }
    if (ctr >= 4)
    {
        for (int i = 0; i < 2; i++)
        {
            gotoxy(60 + i, 7);
            cout << "_";
        }
        for (int i = 1; i < 3; i++)
        {
            gotoxy(64 + i, 7);
            cout << "_";
        }
    }
    if (ctr >= 5)
    {
        gotoxy(63, 7);
        cout << "|";

    }
}


void question1(int& ctr)
{
    char answer;

    int p;
    int k = 0;
    char check[7];
    string answer1 = "everest";
    cout << "Tallest mountain the world" << endl;

    int j;
    j = 0;
    for (int i = 0; i < 7; i++)
    {
        gotoxy(35 + j, 4);
        cout << "_";
        j = j + 2;
    }
    do
    {
        p = ctr;
        hangman(p);
gotoxy(35 + k, 6);

cin >> answer;




if (answer != answer1[0] && answer != answer1[1] && answer != answer1[2] && answer != answer1[3] && answer != answer1[4] && answer != answer1[5] && answer != answer1[6])
{
    ctr++;
}


j = 0;
for (int i = 0; i < 7; i++)
{

    if (answer == answer1[i])
    {


        check[i] = answer;
        gotoxy(35 + j, 4);
        printf("%c", answer);

    }
    j = j + 2;
}
k++;
    } while ((check[0] != answer1[0] || check[1] != answer1[1] || check[2] != answer1[2] || check[3] != answer1[3] || check[4] != answer1[4] || check[5] != answer1[5] || check[6] != answer1[6]) && ctr != 5);
}

void question2(int& ctr)
{
    system("CLS");
    char input;

    int p;
    int k = 0;
    char check2[5];
    char answer2[6] = "nepal";
    cout << "In which country is the world tallest mountain located?" << endl;

    int j;
    j = 0;
    for (int i = 0; i < 5; i++)
    {
        gotoxy(35 + j, 4);
        cout << "_";
        j = j + 2;
    }
    do
    {
        p = ctr;
        hangman(p);
        gotoxy(35 + k, 6);

        cin >> input;




        if (input != answer2[0] && input != answer2[1] && input != answer2[2] && input != answer2[3] && input != answer2[4])
        {
            ctr++;
        }


        j = 0;
        for (int i = 0; i < 5; i++)
        {

            if (input == answer2[i])
            {


                check2[i] = input;
                gotoxy(35 + j, 4);
                printf("%c", answer2[i]);

            }
            j = j + 2;
        }
        k++;
    } while ((check2[0] != answer2[0] || check2[1] != answer2[1] || check2[2] != answer2[2] || check2[3] != answer2[3] || check2[4] != answer2[4]) && ctr != 5);

}
int tictactoe()
{
    int player = 1, i, player_choice;

    char option;

    do

    {
        /*calling the board function which*/
        board();

        //checking turn of the player.
        player = (player % 2 == 1) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &player_choice);

        option = (player == 1) ? 'X' : 'O';

        if (player_choice == 1 && places[1] == '1')
            places[1] = option;

        else if (player_choice == 2 && places[2] == '2')
            places[2] = option;

        else if (player_choice == 3 && places[3] == '3')
            places[3] = option;

        else if (player_choice == 4 && places[4] == '4')
            places[4] = option;

        else if (player_choice == 5 && places[5] == '5')
            places[5] = option;

        else if (player_choice == 6 && places[6] == '6')
            places[6] = option;

        else if (player_choice == 7 && places[7] == '7')
            places[7] = option;

        else if (player_choice == 8 && places[8] == '8')
            places[8] = option;


        else if (player_choice == 9 && places[9] == '9')
            places[9] = option;

        else
        {
            printf("Invalid move ");

            player--;

        }
        i = checkwin();

        player++;
    } while (i == -1);

    board();

    if (i == 1)
        printf("==>\aPlayer %d win \n", --player);
    else
        printf("==>\aGame draw\n");



    return 0;
}

/*Returns win for particular plater and draw. */
/*Returns 1 for win,0 for draw and -1 for the game being not completed*/

int checkwin()
{
    if (places[1] == places[2] && places[2] == places[3])
        return 1;

    else if (places[4] == places[5] && places[5] == places[6])
        return 1;

    else if (places[7] == places[8] && places[8] == places[9])
        return 1;

    else if (places[1] == places[4] && places[4] == places[7])
        return 1;

    else if (places[2] == places[5] && places[5] == places[8])
        return 1;

    else if (places[3] == places[6] && places[6] == places[9])
        return 1;

    else if (places[1] == places[5] && places[5] == places[9])
        return 1;

    else if (places[3] == places[5] && places[5] == places[7])
        return 1;
    //checking if all the spots have been filled.
    else if (places[1] != '1' && places[2] != '2' && places[3] != '3' &&
        places[4] != '4' && places[5] != '5' && places[6] != '6' && places[7]
        != '7' && places[8] != '8' && places[9] != '9')

        return 0;
    else
        return  -1;
}



//Printing the board.
int board()
{

    printf("\n\n\tTic Tac Toe\n\n");
    rule();

    printf("\n     Let the game begin.\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", places[1], places[2], places[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", places[4], places[5], places[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", places[7], places[8], places[9]);

    printf("     |     |     \n\n");
}

int rule()
{
    printf("\tThe rules of the game is as follows: \n\n");
    printf("--> PLayers get chances alternatively.\n");
    printf("--> If you get 3 of your mark continually either vertical, horizontal or diagonal, You win.\n");
    printf("--> If all places are filled and none of the players have 3 of there marks as required, The game is draw.\n");
    printf("--> Once you have placed your mark, You can't undo. So think before you play.\n");



}

int main()
{
    int choice;
    printf("Enter the game you want to play\nPress 1 for hangman\nPress 2 for tictactoe\n");
    scanf("%d", &choice);
    if (choice==1)
    {



    int ctr = 0;
    question1(ctr);
    if (ctr != 5)
    {
        question2(ctr);
    }

    if (ctr == 5)

    {
        system("CLS");
        printf("Game over");
    }
    }
    else
    {
        tictactoe();
    }



    return 0;
}
