#include<stdio.h>

int check(int Board[8][8],int col,int row);
int solve(int Board[8][8],int col);
void print(int Board[8][8]);

int main()
{
	int Board[8][8],i,j;
	int flag;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			Board[i][j]=0;
		}
	}
	flag=solve(Board,0);
	if(flag==0)
	{
		printf("Queens are not possible to be placed");
	}
	if(flag==1)
	{
		print(Board);
	}
}

int solve(int Board[8][8],int col)
{
	if(col==8)
	{
		return 1;
	}
	int i;
	for(i=0;i<8;i++)
	{
		if(check(Board,col,i))
		{
			Board[i][col]=1;
			if(solve(Board,col+1))
			{
				return 1;
			}
			Board[i][col]=0;
		}
	}
	return 0;
}

int check(int Board[8][8],int col,int row)
{
	int i,j;
	for(j=0;j<col;j++)
	{
		if(Board[row][j]!=0)
			return 0;
	}
	for(i=row,j=col;i>=0 && j>=0;i--,j--)
	{
		if(Board[i][j]!=0)
			return 0;
	}
	for(i=row,j=col;i<8 && j>=0;i++,j--)
	{
		if(Board[i][j]!=0)
			return 0;
	}
	return 1;
}

void print(int Board[8][8])
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%d ",Board[i][j]);
		}
		printf("\n");
	}
}
