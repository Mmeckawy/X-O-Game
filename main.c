#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board [3][3] = 
{ {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};

char sign = 'X';
int choice,r,c;
int draw = 0;

void print_board()
{
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

bool vertical_win()
{
  if(board[0][0] == board[1][0] && board[1][0] == board[2][0])
  return true;

  else if(board[0][1] == board[1][1] && board[1][1] == board[2][1])
  return true;

  else if(board[0][2] == board[1][2] && board[1][2] == board[2][2])
  return true;

  else return false;
}

bool horizontal_win()
{
  if(board[0][0] == board[0][1] && board[0][1] == board[0][2])
  return true;

  else if(board[1][0] == board[1][1] && board[1][1]== board[1][2])
  return true;

  else if(board[2][0] == board[2][1] && board[2][1] == board[2][2])
  return true;

  else return false;
}

bool diagonal_win()
{
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
  return true;

  else if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
  return true;

  else return false;
}

void play_move()
{
  if(sign == 'X')
  {
  printf(" Player 1 enter choice:\n");
  }
  else if(sign == 'O')
  {
  printf(" Player 2 enter choice: \n");
  }

  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    r = 0, c = 0;
    break;

  case 2:
    r = 0, c = 1;
    break;

  case 3:
    r = 0, c = 2;
    break;

case 4:
    r = 1, c = 0;
    break;

  case 5:
    r = 1, c = 1;
    break;    

  case 6:
    r = 1, c = 2;
    break;

case 7:
    r = 2, c = 0;
    break;

  case 8:
    r = 2, c = 1;
    break;

  case 9:
    r = 2, c = 2;
    break;

  default:
   printf(" Invalid move \n");
    break;
  }

  if(sign == 'X' && board[r][c] != 'X' && board[r][c] != 'O')
  {
    board[r][c] = 'X';
    sign = 'O';
  }

  else if(sign == 'O' && board[r][c] != 'X' && board[r][c] != 'O')
  {
    board[r][c] = 'O';
    sign = 'X';
  }
  else 
  {
    printf("Box already filled\n");
    play_move();
  }
  print_board();
}

bool win_game()
{
  if(vertical_win() == true || horizontal_win() == true || diagonal_win() == true)
  return true;
  else return false;
}


int main() {

  while(win_game() == false && draw < 9)
  {
    print_board();
    play_move();
    draw++;
  }

  if(win_game() == true && sign == 'O')
  {
    printf("Player 1 won");
  }
  else  if(win_game() == true && sign == 'X')
  {
    printf("Player 2 won");
  }
  else
  {
    printf("Draw");
  }

  return 0;
}
