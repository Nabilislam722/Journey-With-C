#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define player 'X'
#define computer 'O'

char Board[3][3];

void resetBoard();
void printBoard();
int checkFreespace();
void playerMove();
void computerMove();
void makeRandoMove();
int makeBestMove();
char checkWinner();
void printWinner(char Winner);

int main(void)
{
    srand(time(0));
  char Winner = ' ';
  resetBoard();
  
  while (Winner == ' ' && checkFreespace() != 0)
  {
    printBoard();

       playerMove();
       Winner = checkWinner();
    if (checkFreespace() == 0 || Winner != ' ')
    {
        break;
    }
       computerMove();
       Winner = checkWinner();
    if (checkFreespace() == 0 || Winner != ' ')
    {
        break;
    }
    
  }

  printBoard();
  printWinner(Winner);


  return 0;
}



void resetBoard()
{
   for (int i = 0; i < 3; i++)
   {
     for (int j = 0; j < 3; j++)
     {
        Board[i][j] = ' ';
     }
     
   }
   
}

void printBoard()
{
    printf(" %c | %c | %c ", Board[0][0], Board[0][1], Board[0][2]);
      printf("\n---|---|---\n");
     printf(" %c | %c | %c ", Board[1][0], Board[1][1], Board[1][2]);
      printf("\n---|---|---\n");
       printf(" %c | %c | %c ",  Board[2][0], Board[2][1], Board[2][2]);
      printf("\n");
}

int checkFreespace()
{

    int freespace = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] != ' ')
            {
                freespace--;
            }
            
        }
        
    }

    return freespace;
}

void playerMove()
{
  int x;
  int y;

  do
  {
    printf("Enter Columns:");
  scanf("%i", &x);
  x--;
  printf("Enter Row:");
  scanf("%i", &y);
  y--;
  
  if (Board[y][x] == ' ')
  {
    Board[y][x] = player;
    break;
  }
  
  else
  {
    printf("Invaild Command\n");
  }
  } while (Board[x][y] != ' ');
  
}


void computerMove()
{
   int decideMove = rand() % 100;

    if(decideMove < 70)
    {
        if (makeBestMove()) return; 

    int x, y;

    if (checkFreespace() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (Board[y][x] != ' ');

        Board[y][x] = computer;
    }
    }
    else
    {
    
      return makeRandoMove();
    }
}

int makeBestMove()
{
  for (int i = 0; i < 3; i++)
    {
        // Check rows
        if (Board[i][0] == Board[i][1] && Board[i][0] == computer && Board[i][2] == ' ')
        {
            Board[i][2] = computer;
            return 1;
        }
        if (Board[i][0] == Board[i][2] && Board[i][0] == computer && Board[i][1] == ' ')
        {
            Board[i][1] = computer;
            return 1;
        }
        if (Board[i][1] == Board[i][2] && Board[i][1] == computer && Board[i][0] == ' ')
        {
            Board[i][0] = computer;
            return 1;
        }

        // Check columns
        if (Board[0][i] == Board[1][i] && Board[0][i] == computer && Board[2][i] == ' ')
        {
            Board[2][i] = computer;
            return 1;
        }
        if (Board[0][i] == Board[2][i] && Board[0][i] == computer && Board[1][i] == ' ')
        {
            Board[1][i] = computer;
            return 1;
        }
        if (Board[1][i] == Board[2][i] && Board[1][i] == computer && Board[0][i] == ' ')
        {
            Board[0][i] = computer;
            return 1;
        }
    }

    // Check diagonals
    if (Board[0][0] == Board[1][1] && Board[0][0] == computer && Board[2][2] == ' ')
    {
        Board[2][2] = computer;
        return 1;
    }
    if (Board[0][0] == Board[2][2] && Board[0][0] == computer && Board[1][1] == ' ')
    {
        Board[1][1] = computer;
        return 1;
    }
    if (Board[1][1] == Board[2][2] && Board[1][1] == computer && Board[0][0] == ' ')
    {
        Board[0][0] = computer;
        return 1;
    }
    if (Board[0][2] == Board[1][1] && Board[0][2] == computer && Board[2][0] == ' ')
    {
        Board[2][0] = computer;
        return 1;
    }
    if (Board[0][2] == Board[2][0] && Board[0][2] == computer && Board[1][1] == ' ')
    {
        Board[1][1] = computer;
        return 1;
    }
    if (Board[1][1] == Board[2][0] && Board[1][1] == computer && Board[0][2] == ' ')
    {
        Board[0][2] = computer;
        return 1;
    }

    return 0;
}
void makeRandoMove()
{
    int x, y;

    if (checkFreespace() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (Board[y][x] != ' ');

        Board[y][x] = computer;
    }
    else
    {
    printWinner(' ');
    }  

}
char checkWinner()
{
    //Row
    for (int i = 0; i < 3; i++)
    {
        if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] && Board[i][0] != ' ')
        {
            return Board[i][0];
        }
        
    }
    //columns
    for (int i = 0; i < 3; i++)
    {
        if (Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i])
        {
            return Board[0][i];
        }
        
    }
    //digonal

    if (Board[0][0]== Board[1][1] && Board[0][0] == Board[2][2])
    {
        return Board[0][0];
    }
     if (Board[0][2]== Board[1][1] && Board[0][2] == Board[2][0])
    {
        return Board[0][2];
    }
    
    return ' ';
}



void printWinner(char Winner)
{ 

  if (Winner == player)
  {
    printf("You Won!\n");
  }
  else if (Winner == computer)
  {
    printf("Computer Won!\n");
  }
  else
  {
    printf("DRAW\n");
  }
  
  

}