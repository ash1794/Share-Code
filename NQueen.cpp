#include<iostream>
#include<string.h> //For the memset function
using namespace std;

#define MAX_N 1010
int board[MAX_N][MAX_N];
void print(int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j])
            {
                cout<<"Q ";
            }
            else
            {
                cout<<"X ";
            }
        }
        cout<<"\n";
    }
}

bool rowisclear(int n,int x,int y)
{
    for(int i=0;i<n;i++)
        if(board[x][i])
            return false;
    return true;
}

bool UpperDiagIsClear(int n,int x,int y)
{
    //We start at (x,y) and move up the 
    //diagonal to check if there's a queen
    for(int i=x,j=y;i>=0 and j>=0;i--,j--)
        if(board[i][j])
            return false;
    return true;
}

bool LowerDiagIsClear(int n,int x,int y)
{
    //Again We start at (x,y) and move down this time
    for(int i=x,j=y;i<n and j>=0;i++,j--)
        if(board[i][j])
            return false;
    return true;
}
bool issafe(int n,int x,int y)
{
    //issafe function assumes that the queens have been placed 
    //only from column 0 to y-1

    //We check if a queen is already placed in the current row.
    if(!rowisclear(n,x,y))
        return false;

    //Since queens are placed on the left side we check if the upper
    //diagonal to the left has a queen 
    if(!UpperDiagIsClear(n,x,y))
        return false;
    
    //Also we need to check the lower diagonal in the left if it 
    //has a queen 
    if(!LowerDiagIsClear(n,x,y))
        return false;
    return true;
}

//Solve moves column by column trying to place a queen in 
//every row until it leads to a valid solution.
bool solve(int n,int pos)
{
    if(pos>=n)
        return true;
    for(int i=0;i<n;i++)
    {
        if(issafe(n,i,pos))
        {
            board[i][pos]=1;
            if(solve(n,pos+1))
                return true;
            board[i][pos]=0;
            // If code reaches this point then the 
            // current configuration failed and we need to place 
            // the queen in a different row in the current column. 
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n; // Take Input for getting the board size.
    int board[n][n];
    memset(board,0,sizeof board); //Sets the whole array as 0
    //0 - Signifies an empty position in the board
    //1 - Signifies a queen in that position.
    if(solve(n,0) == false)
    {
        cout<<"No Solution exists\n";
    }
    else
    {
        print(n);
    }
    return 0;
}