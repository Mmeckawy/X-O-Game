#include <stdio.h>
#include <conio.h>

char board [3][3] = { {'1','2','3'},
                      {'4','5','6'},
                      {'7','8','9'}};

void print_board()
{
    system("cls");
    printf(" Player 1: X  -  Player 2: O\n\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j];
            printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
}

int check_win()
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return 1;

    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return 1;

    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return 1;

    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return 1;

    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return 1;

    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return 1;

    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    else if (board[0][0] != '1' && board[0][1]!= '2' && board[0][2] != '3' &&
        board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
        board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9')

        return 0;
    else
        return  - 1;
}

int main()
{
    int player = 1, i, choice;

    char sign;
    do
    {
        print_board();
        player = (player % 2) ? 1 : 2;

        printf("\n  Player %d, enter number:  ", player);
        scanf("%d", &choice);

        sign = (player == 1) ? 'X' : 'O';

        if (choice == 1 && board[0][0] == '1')
            board[0][0] = sign;

        else if (choice == 2 && board[0][1] == '2')
            board[0][1] = sign;

        else if (choice == 3 && board[0][2] == '3')
            board[0][2] = sign;

        else if (choice == 4 && board[1][0] == '4')
            board[1][0] = sign;

        else if (choice == 5 && board[1][1] == '5')
            board[1][1] = sign;

        else if (choice == 6 && board[1][2] == '6')
            board[1][2] = sign;

        else if (choice == 7 && board[2][0] == '7')
            board[2][0] = sign;

        else if (choice == 8 && board[2][1] == '8')
            board[2][1] = sign;

        else if (choice == 9 && board[2][2] == '9')
            board[2][2] = sign;

        else
        {
            printf("Invalid move!");

            player--;
            getch();
        }
        i = check_win();

        player++;
    }while (i ==  - 1);

    print_board();

    if (i == 1)
        printf("Player %d win ", --player);
    else
        printf("Tie between the two players");

    getch();
    return 0;
}
