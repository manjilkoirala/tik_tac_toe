#include <stdio.h>
#include<dos.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#define tab printf("\t\t\t")
#define TAB 9
#define Enter 13
#define BKSP 8
#define SPACE 32
char box[10]={'0','1','2','3','4','5','6','7','8','9'};
void creating_board();
void marking_board(int, char);
int check_for_win();
int login();
void welcome_page();
void thanks_page();

//Main Program:

void main()
{
	int choice,player=1,i;
	char mark;
	welcome_page();
	delay(100);
	if (login()==1)

	{
		system("cls");

		do{
			creating_board();
			player= (player % 2) ? 1: 2;
			printf("\n");

			tab; printf("Player %d, make your choice : ",player);
			scanf("%d",&choice);

			mark = (player==1) ? 'X' : 'O';

			delay(100);

			system("cls");

			marking_board(choice,mark);

			i=check_for_win();
			player++;

		}while(i == -1)

		creating_board();

		if(i==1)
		{
			printf("\n");
			tab; printf("Player %d, you have won the game",--player);
		 }
		else
		{
			printf("\n");
			tab; printf("<-------Draw------>");
		}

		getch();
		thanks_page();

	}
	else
	{
		printf("\n");
		tab; printf("****Wrong Userid or Password****");
		getch();
	}


}

// Printing board:

void creating_board()
{
	tab; printf("\n\n\n");
	tab; printf("*************Tic Tac Toe*************\n\n");
	tab; printf("Player 1 (X) -- Player 2 (O)\n\n");
	tab; printf("          |     |     \n");
	tab; printf("       %c  |  %c  |  %c  \n",box[1],box[2],box[3]);
	tab; printf("     _____|_____|_____\n");
	tab; printf("          |     |      \n");
	tab; printf("       %c  |  %c  |  %c  \n",box[4],box[5],box[6]);
	tab; printf("     _____|_____|_____\n");
	tab; printf("          |     |      \n");
	tab; printf("       %c  |  %c  |  %c  \n",box[7],box[8],box[9]);
	tab; printf("          |     |      \n");
}

//Marking Board:

void marking_board( int choice, char mark)
{
	if(choice==1 && box[1]=='1')
		box[1]=mark;
	else if(choice==2 && box[2]=='2')
		box[2]=mark;
	else if(choice==3 && box[3]=='3')
		box[3]=mark;
	else if(choice==4 && box[4]=='4')
		box[4]=mark;
	else if (choice==5 && box[5]=='5')
		box[5]=mark;
	else if (choice==6 && box[6]=='6')
		box[6]=mark;
	else if (choice==7 && box[7]=='7')
		box[7]=mark;
	else if (choice==8 && box[8]=='8')
		box[8]=mark;
	else if (choice==9 && box[9]=='9')
		box[9]=mark;
	else
	{
		printf("\n");
		printf("*******************Invalid move*******************");
	}
}


//Winner Checking:

int check_for_win()
{
	if(box[1]==box[2] && box[2]==box[3])
		return 1;
	else if(box[4]==box[5] && box[5]==box[6])
		return 1;                                   // horizontal match
	else if (box[7]==box[8] && box[8]==box[9])
		return 1;
	else if (box[1]==box[4] && box[4]==box[7])
		return 1;
	else if(box[2]==box[5] && box[5]==box[8])           // vertical match
		return 1;
	else if(box[3]==box[6] && box[6]==box[9])
		return 1;
	else if(box[1]==box[5] && box[5]==box[9])
		return 1;
	else if(box[3]==box[5] && box[5]==box[7])           //diagonal match
		return 1;
	else if(box[1]!= '1' && box[2]!= '2' && box[3]!= '3' && box[4]!= '4'&& box[5]!= '5' && box[6]!= '6'&& box[7]!= '7' && box[8]!= '8' && box[9]!='9')  //no match
		return 0;
	else
		return -1;
}


//Login Page:

int login()
{
	char userid[10];
	char pass[10];
	char ch;
	int i=0;
	printf("\n");
	tab; printf("***********Login Page:************ ");
	printf("\n\n");
	tab; printf(" UserId: ");
	scanf("%s",&userid);
	tab; printf(" Password: ");
	strlwr(userid);
	while(1)
	{
		ch=getch();
		if(ch== Enter)
		{
			pass[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				printf("\b \b");
			}
			
		}
		else if(ch==TAB || ch==SPACE)
		{
			continue;
		}
		else
		{
			 pass[i]=ch;
			 i++;
			 printf("*");
		}
	}
	
	if((strcmp(userid,"manjil")==0  && strcmp(pass,"koirala")==0) ||
	   (strcmp(userid,"keshab")==0  && strcmp(pass,"pokhrel")==0) ||
	   (strcmp(userid,"prateema")==0  && strcmp(pass,"prateema")==0) ||
	   (strcmp(userid,"nirajdev")==0  && strcmp(pass,"niraj8585")==0))
		return 1;
	else
		return 0;
}

//Welcome Page:

void welcome_page()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setbkcolor(LIGHTBLUE);
	settextstyle(1,HORIZ_DIR,7);
	outtextxy(180,50,"WELCOME");
	settextstyle(1,0,5);
	outtextxy(290,150,"TO");
	setcolor(RED);
	settextstyle(0,0,5);
	outtextxy(100,250,"TIC TAC TOE");
	setcolor(GREEN);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(100,320,">> Manjil Koirala (331871)");
	setcolor(GREEN);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(100,350,">> Keshab Pokhrel (331869)");
	setcolor(GREEN);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(100,380,">> Niraj Dev (331874)");
	setcolor(GREEN);
	settextstyle(0,HORIZ_DIR,2);
	outtextxy(100,410,">> Prateema Dhakal (331879)");
	getch();
	closegraph();
}

//Thanks Page:

void thanks_page()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setbkcolor(LIGHTBLUE);
	settextstyle(1,HORIZ_DIR,7);
	outtextxy(220,80,"Thanks");
	settextstyle(1,0,5);
	outtextxy(310,160,"for");
	setcolor(RED);
	settextstyle(0,0,5);
	outtextxy(200,230,"playing");
	getch();
	closegraph();
}
