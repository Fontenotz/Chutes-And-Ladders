#include<iostream.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void wait(double seconds)
{
	clock_t endwait;
	endwait=clock()+seconds*CLK_TCK;
	while(clock()<endwait){}
}

char board[12][12]=
{
	'-','-','-','C','-','-','-','-','-','-','-','F',
	'-','-','-','-','-','-','-','-','-','-','-','-',
	'-','-','c','-','-','-','-','-','-','-','-','-',
	'-','-','-','-','-','-','L','-','-','-','-','-',
	'-','-','-','-','-','-','-','-','-','-','-','-',
	'-','-','-','-','-','-','-','-','-','-','-','-',
	'-','C','-','-','-','-','-','-','-','-','-','-',
	'-','-','-','-','-','-','-','-','-','-','-','-',
	'-','-','-','-','L','-','-','-','-','-','-','-',
	'-','-','-','-','-','-','-','l','-','-','-','-',
	'-','-','-','-','-','-','-','-','-','-','-','c',
	'S','-','-','-','-','-','-','l','-','-','-','-',
};

struct players 
board
{
	int move;
	char color;
	int x;
	int y;
}player1,player2,player3;
void showboard();
void reset();
void movement();
void chutes();
void ladders();
void reseta();
void movementa();
void chutesa();
void laddersa();
void resetb();
void movementb();
void chutesb();
void laddersb();
void sort();


int main()
{

	player1.x=11;
	player1.y=0;
	player2.x=11;
	player2.y=0;
	player3.x=11;
	player3.y=0;

	showboard();

	while(player1.x>0||player2.x>0||player3.x>0)
advances to the end of the game board
	{
	sort();
smaller
	}
	return 0;
}





void showboard()
{
	for(int a=0;a<12;a++)
	{
		for(int b=0;b<12;b++)
		{
			cout<<board[a][b];
		}
		cout<<endl;
	}
}

void movement()
{
	srand(time(0));
	cout<<"Player 1: ROLL"<<endl;
	player1.move=rand()%8+1;
	wait(.85);
	cout<<"Player 1 rolled a "<<player1.move<<"!"<<endl;
	wait(1);
	if(player1.move<=(11-player1.y))
	{
		reset();
			player1.y=player1.y+player1.move;
			chutes();
			ladders();
			board[player1.x][player1.y]='R';
	}
	else
	{
		reset();
		player1.move=player1.move-(11-player1.y);
		player1.x=player1.x-1;
		player1.y=player1.move-1;
		chutes();
		ladders();
		board[player1.x][player1.y]='R';
	}

}

void reset()
{

if(player1.x==11&&player1.y==0)
{
board[player1.x][player1.y]='S';
}
else if(player1.x==11&&player1.y==7||player1.x==9&&player1.y==7)
{
	board[player1.x][player1.y]='l';
}
else if(player1.x==8&&player1.y==4||player1.x==3&&player1.y==6)
{
	board[player1.x][player1.y]='L';
}
else if(player1.x==0&&player1.y==3||player1.x==6&&player1.y==1)
{
	board[player1.x][player1.y]='C';
}
else if(player1.x==6&&player1.y==9||player1.x==10&&player1.y==11)
{
	board[player1.x][player1.y]='c';
}
else
{
	board[player1.x][player1.y]='-';
}
}

void chutes()
{
	if(player1.x==2&&player1.y==2)
	{
		player1.x=6;
		player1.y=1;
	}
	else if(player1.x==6&&player1.y==9)
	{
		player1.x=10;
		player1.y=11;
	}
}

void ladders()
{
if(player1.x==8&&player1.y==4)
	{
	cout<<"YOU HIT A LADDER!"<<endl;
	wait(1);
		player1.x=3;
		player1.y=6;
	}
	else if(player1.x==11&&player1.y==7)
	{
		cout<<"YOU HIT A LADDER!"<<endl;
		wait(1);
		player1.x=9;
		player1.y=7;
	}
}


void movementa()
{
	srand(time(0));
	cout<<"Player 2: ROLL"<<endl;
	player2.move=rand()%8+1;
	wait(.85);
	cout<<"Player 2 rolled a "<<player2.move<<"!"<<endl;
	wait(1);
	if(player2.move<=(11-player2.y))
	{
		reseta();
			player2.y=player2.y+player2.move;
			chutes();
			ladders();
			board[player2.x][player2.y]='R';
	}
	else
	{
		reseta();
		player2.move=player2.move-(11-player2.y);
		player2.x=player2.x-1;
		player2.y=player2.move-1;
		chutes();
		ladders();
		board[player2.x][player2.y]='R';
	}

}

void reseta()
{

if(player2.x==11&&player2.y==0)
{
board[player2.x][player2.y]='S';
}
else if(player2.x==11&&player1.y==7||player2.x==9&&player2.y==7)
{
	board[player2.x][player2.y]='l';
}
else if(player2.x==8&&player2.y==4||player2.x==3&&player2.y==6)
{
	board[player2.x][player2.y]='L';
}
else if(player2.x==0&&player2.y==3||player2.x==6&&player2.y==1)
{
	board[player2.x][player2.y]='C';
}
else if(player2.x==6&&player2.y==9||player2.x==10&&player2.y==11)
{
	board[player2.x][player2.y]='c';
}
else
{
	board[player2.x][player2.y]='-';
}
}

void chutesa()

{
	if(player2.x==0&&player2.y==3)
	{
		player2.x=6;
		player2.y=1;
	}
	else if(player2.x==6&&player2.y==9)
	{
		player2.x=10;
		player2.y=11;
	}
}

void laddersa()
{
if(player2.x==8&&player2.y==4)
	{
	cout<<"YOU HIT A LADDER!"<<endl;
	wait(1);
		player2.x=3;
		player2.y=6;
	}
	else if(player2.x==11&&player2.y==7)
	{
		cout<<"YOU HIT A LADDER!"<<endl;
		wait(1);
		player2.x=9;
		player2.y=7;
	}
}


void movementb()
	srand(time(0));
	cout<<"Player 3: ROLL"<<endl;
	player3.move=rand()%8+1;
	wait(.85);
	cout<<"Player 3 rolled a "<<player3.move<<"!"<<endl;
	wait(1);
	if(player3.move<=(11-player3.y))
	{
		resetb();
			player3.y=player3.y+player3.move;
			chutes();
			ladders();
			board[player3.x][player3.y]='R';
	}
	else
	{
		resetb();
		player3.move=player3.move-(11-player3.y);
		player3.x=player3.x-1;
		player3.y=player3.move-1;
		chutes();
		ladders();
		board[player3.x][player3.y]='R';
	}

}

void resetb()
{

if(player3.x==11&&player3.y==0)
		{
		board[player3.x][player3.y]='S';
		}
		else if(player3.x==11&&player3.y==7||player3.x==9&&player3.y==7)
		{
			board[player3.x][player3.y]='l';
		}
		else if(player3.x==8&&player3.y==4||player3.x==3&&player3.y==6)
		{
			board[player3.x][player3.y]='L';
		}
		else if(player3.x==0&&player3.y==3||player3.x==6&&player3.y==1)
		{
			board[player3.x][player3.y]='C';
		}
		else if(player3.x==6&&player3.y==9||player3.x==10&&player3.y==11)
		{
			board[player3.x][player3.y]='c';
		}
		else
		{
			board[player3.x][player3.y]='-';
		}
}

void chutesb() 
accordingly
{
	if(player3.x==0&&player3.y==3)
	{
		player3.x=6;
		player3.y=1;
	}
	else if(player3.x==6&&player3.y==9)
	{
		player3.x=10;
		player3.y=11;
	}
}

void laddersb()
{
if(player3.x==8&&player3.y==4)
	{
	cout<<"YOU HIT A LADDER!"<<endl;
	wait(1);
		player3.x=3;
		player3.y=6;
	}
	else if(player3.x==11&&player3.y==7)
	{
		cout<<"YOU HIT A LADDER!"<<endl;
		wait(1);
		player3.x=9;
		player3.y=7;
	}
}


void sort()
{
	movement();
	system("CLS");
	cout<<"Player 1's turn."<<endl;
	showboard();
	wait(2.0);
	movementa();
	system("CLS");
	cout<<"Player 2's turn."<<endl;
	showboard();
	wait(2.0);
	movementb();
	system("CLS");
	cout<<"Player 3's turn."<<endl;
	showboard();
	wait(2.0);
}
