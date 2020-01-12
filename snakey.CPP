#include<stdio.h>
#include<conio.h>
#include<dos.h> //For the delay set in the difficulty
#include<stdlib.h>  //Randomising the fruit location
int main()
{
int i,j,k,l,m,b[20000],n,s,f,d,aa,ab,x,c[80][23]; //b stores a value with every move, hence it needs to be a really big value
char ch;
textcolor(14); // Yellow color
textbackground(12); // Red color
clrscr();
i=5;j=5;m=1;
for(i=4;i<76;i++) //Making every element in the matrix 0
{
	for(j=3;j<23;j++)
	{
		c[i][j]=0;
	} 
}
		clrscr();
		gotoxy(25,10);

printf("Welcome to the Game Of Snake.");
getch();
clrscr();
gotoxy(35,14);
start:
clrscr();
gotoxy(25,12);
printf("Choose level of difficulty:");
gotoxy(28,14);
printf("1.Easy");
gotoxy(28,15);
printf("2.Medium");
gotoxy(28,16);
printf("3.Hard");
gotoxy(28,17);
printf("4.Professional");
ch=getch();
if(ch=='1')
{s=400;}
else if(ch=='2')
{s=300;}
else if(ch=='3')
{s=100;}
else if(ch=='4')
{s=75;}
else{goto start;}
clrscr();
for(i=4;i<76;i++)   //Making the border
{
	gotoxy(i,3);printf("-");
	gotoxy(i,23);
	printf("-");
}
for(j=3;j<=23;j++)
{
	gotoxy(3,j);
	printf("|");
	gotoxy(76,j);
	printf("|");
}
gotoxy(5,1);
printf("Score=0");
gotoxy(50,24);
x=0;i=10;j=10;m=1;
for(n=0;n<5;n++) //so that the snake appears before the fruit.
{
i=i+1;
gotoxy(i,j);
c[i][j]=1;  //wherever the snake treads, that location gets value 1
b[m]=(i*100)+j;
printf("*");
m=m+1;
}
n=5;
f=0; // flag variable
goto food;
game:
left:
f=1;
while(!kbhit()) //for keyboard input
{
	i=i+1;
	if(i>75||j>22||j<4||i<4)
	{goto gameover;}
if(c[i][j]==1)
goto gameover;
if(i==aa&&j==ab) //Condition at which the snake eats fruit and increases length
goto increase;
gotoxy(i,j);
c[i][j]=1;
b[m]=(i*100)+j; //storing values as the snakes passes through b
printf("*");
d=b[m-n];
k=d/100;
l=d%100;
gotoxy(k,l); // coordiantes of tail tip
printf(" ");
c[k][l]=0;
delay(s); // set by difficulty
m=m+1;
}
ch=getch();
if(ch=='a')
goto left;
goto choice;
right:
f=2;
while(!kbhit())
{i=i-1;if(i>75||j<4||i<4||j>22)
goto gameover;
if (c[i][j]==1)
goto gameover;
if(i==aa&&j==ab)
goto increase;
gotoxy(i,j);
c[i][j]=1;
b[m]=(i*100)+j;printf("*");
d=b[m-n];
k=d/100;
l=d%100;
gotoxy(k,l);printf(" ");c[k][l]=0;delay(s);m=m+1;}
ch=getch();
if(ch=='d')
{goto right;}
goto choice;
up:
f=3;
while(!kbhit())
{
	j=j-1;
	if(i<4||i>75||j>22||j<4)
	{goto gameover;}
if(c[i][j]==1)
	goto gameover;
if(i==aa&&j==ab)
	goto increase;
gotoxy(i,j);
c[i][j]=1;
b[m]=(i*100)+j;
printf("*");
d=b[m-n];
k=d/100;
l=d%100;
gotoxy(k,l);
printf(" ");
c[k][l]=0;
delay(s);
m=m+1;}
ch=getch();
if(ch=='s'){goto up;}
goto choice;
down:
f=4;
while(!kbhit())
{j=j+1;if(i<4||i>75||j>22||j<4){goto gameover;}
if(c[i][j]==1){goto gameover;}
if(i==aa&&j==ab){goto increase;}
gotoxy(i,j);c[i][j]=1;
b[m]=(i*100)+j;
printf("*");
d=b[m-n];
k=d/100;
l=d%100;
gotoxy(k,l);
printf(" ");
c[k][l]=0;
delay(s);
m=m+1;
}
ch=getch();
choice:
if(ch=='w'){goto up;}
else if(ch=='s'){goto down;}
else if(ch=='a'){goto right;}
else if(ch=='d'){goto left;}
else if(ch=='q'){goto exit;}
else {if(f==1){goto left;}
else if(f==2){goto right;}
else if(f==3){goto up;}
else{goto down;}}
food:
randomize();
aa=(rand()%100);
if(aa<=3){goto food;}
if(aa>=76){goto food;}
randomize();
ab=(rand()%30);
if(ab<=3){goto food;}
else if(ab>=23){goto food;}
gotoxy(aa,ab);printf("*");
if(f==0){goto game;}
if(f==1){goto left;}
if(f==2){goto right;}
if(f==3){goto up;}
else{goto down;}
increase:
if(f==1){b[m]=(i*100)+j;gotoxy(i,j);printf("*");m=m+1;n=n+1;gotoxy(5,1);x=x+1;printf("score=%d",x);goto food;}
if(f==2){b[m]=(i*100)+j;gotoxy(i,j);printf("*");m=m+1;n=n+1;x=x+1;gotoxy(5,1);printf("score=%d",x);goto food;}
if(f==3){b[m]=(i*100)+j;gotoxy(i,j);printf("*");m=m+1;n=n+1;x=x+1;gotoxy(5,1);printf("score=%d",x);goto food;}
else{b[m]=(i*100)+j;gotoxy(i,j);printf("*");m=m+1;n=n+1;x=x+1;gotoxy(5,1);printf("score=%d",x);goto food;}
gameover:
clrscr();
gotoxy(35,10);
printf("Game Over");
gotoxy(30,11);
printf("Your Score = %d",x);
gotoxy(30,12);
printf("Press any key to continue.");
getch();
goto exit;
exit:
clrscr();
gotoxy(27,11);
printf("Do you want to quit (y/n) ?");
ch=getch();
if(ch=='n')
{goto start;}
else if(ch=='y')
{
	clrscr();
	gotoxy(27,11);
	printf("Thanks for playing.");
	getch();
	goto quit;
}
else{goto exit;}
quit:
getch();
return 0;
}