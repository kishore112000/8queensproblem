#include<stdio.h>
#include<conio.h>
#define LT 218
#define RT 191
#define LB 192
#define RB 217
#define HL 196
#define VL 179
#define CROSS 197
#define RST 180
#define LST 195
#define TT 194
#define BT 193
#define SP 32
#define  BS 8
#define DIM 8
#define WIDTH 7
#define HEIGHT 1
#include <windows.h>

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void removeQueen(int box_row,int box_col);
void placeQueen(int box_row,int box_col);
void drawBox();
#define SAFE 1
#define UNSAFE 0
int queen_position[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int isSafe(int row, int col);
int main()
{
    int col,row,prev_col=-1,sol_ctr=0;
   drawBox();
   row=0;
   while(row>=0)
   {
    while(row<DIM)
    {
      for(col= prev_col+1 ;col<DIM;col++)
       {
           if(isSafe(row,col)==SAFE)//if safe place the queen
            {
                placeQueen(row,col);//user
                queen_position[row]=col;//prog
                row++;
                prev_col = -1;//on place queen=> col will start from 0
                break;//go and start fresh from 0th col
            }
       }
       if(col==DIM)//none of the cols are safe=>Do backtracking
       {
           row--;
           if(row==-1)
            break;
           removeQueen(row,queen_position[row]);//it removes queen from screen=>user view
           prev_col = queen_position[row];//have copy of prev col to do further check
           queen_position[row]=-1;
       }
    }
           if(row==-1)
            break;
        gotoxy(0,0);
        printf("solCtr : %2d",++sol_ctr);
        getch();
        row--;
           removeQueen(row,queen_position[row]);//it removes queen from screen=>user view
           prev_col = queen_position[row];//have copy of prev col to do further check
           queen_position[row]=-1;
 }

   getch();
   return 0;
}
int isSafe(int grow,int gcol)
{
    int row,col;
    //left top
    for(row=grow-1 ,col= gcol-1;row>=0&&col>=0 ; row--,col--)
        if(queen_position[row]==col)//it is unsafe 2,4 QP[2] == 4=>queen is there
            return UNSAFE;
    //top
    for(row=grow-1 ,col= gcol;row>=0 ; row--)
        if(queen_position[row]==col)//it is unsafe 2,4 QP[2] == 4=>queen is there
            return UNSAFE;
    //right top
     for(row=grow-1 ,col= gcol+1;row>=0&&col<DIM ; row--,col++)
        if(queen_position[row]==col)//it is unsafe 2,4 QP[2] == 4=>queen is there
            return UNSAFE;
    return SAFE;
}
void placeQueen(int box_row,int box_col)
{
    int bcol,brow,row,col;
    bcol=10;
    brow=10;
    bcol+=2;//12
    brow+=1;//11
    col = bcol + box_col*(WIDTH+1);
    row = brow + box_row*(HEIGHT+1);
    gotoxy(col,row);
    printf("QUEEN");

}
void removeQueen(int box_row,int box_col)
{
    int bcol,brow,row,col;
    bcol=10;
    brow=10;
    bcol+=2;//12
    brow+=1;//11
    col = bcol + box_col*(WIDTH+1);
    row = brow + box_row*(HEIGHT+1);
    gotoxy(col,row);
    printf("     ");
}

void drawBox()
{
    int bcol,brow,row,col,ctr1,ctr2,ctr3;
    //(given_space-used_space)/2;
    bcol=10;
    brow=10;

        gotoxy(bcol,brow);
        printf("%c",LT);
        for(ctr2=1;ctr2<=DIM;ctr2++)
        {
            for(ctr1=1; ctr1<=WIDTH ; ctr1++)
                printf("%c",HL);
            printf("%c",TT);
        }
        printf("%c%c",BS,RT);//backspace=>go one space back
        //end of first line
    for(ctr3=1 ; ctr3<=DIM  ;ctr3++)
    {
        gotoxy(bcol,++brow);
        printf("%c",VL);
        for(ctr2=1;ctr2<=DIM;ctr2++)
        {
           for(ctr1=1; ctr1<=WIDTH ; ctr1++)
                printf("%c",SP);
           printf("%c",VL);
        }
        gotoxy(bcol,++brow);
        printf("%c",LST);
        for(ctr2=1;ctr2<=DIM;ctr2++)
        {
            for(ctr1=1; ctr1<=WIDTH ; ctr1++)
                printf("%c",HL);
            printf("%c",CROSS);
        }
        printf("%c%c",BS,RST);//backspace=>go one space back
    }
      gotoxy(bcol,brow);
      printf("%c",LB);
        for(ctr2=1;ctr2<=DIM;ctr2++)
        {
            for(ctr1=1; ctr1<=WIDTH ; ctr1++)
                printf("%c",HL);
            printf("%c",BT);
        }
        printf("%c%c",BS,RB);//backspace=>go one space back

        //printf("\n");=> will take you to next row and 0th col
 printf("\n");
}
