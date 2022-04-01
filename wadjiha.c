#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
void Color(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
typedef struct user
{
   char Fulname_name[30];
   char e_mail[40];
   char password[30];
   char  ID[50];
   struct  user* next;
}user;

int iktyar(char c ,user * one)
{
    system("CLS");
    Color(0);
    char password[30];
    char e_mail[40];
     switch(c)
    {
case 'A' :
        printf("\n\t\t\tGIVE ME YOUR FULL NAME PLEASE : ");
        scanf(" %s",one->Fulname_name);

        printf("\n\t\t\tGIVE ME YOUR E-MAIL PLEASE : ");
        scanf(" %s",one->e_mail);

        printf("\n\t\t\tGIVE ME YOUR PASSWORD PLEASE : ");
        scanf("%s",&one -> password);

        printf("\n\t\t\tGIVE ME YOUR ID PLEASE : ");
        scanf("%s",&one ->ID);
      return 1;
case 'B':
        Color (8);
        puts("\n\t\t\t\t\t\t ___________________");
        puts("\n\t\t\t\t\t\t||  Personal Page  || ");
        puts("\t\t\t\t\t\t ___________________");
        Color(2);
        printf("\n\t     ______________________________________________________________________________________________________\n");
        loop2(15);
        Color(2);
        puts("\t    _______________________________________________________________________________________________________");
        gotoxy(25,12);
        Color(4);
        printf("choose please again : \n\n");
        gotoxy(25,13);
        Color(45);
         printf("Give me your e-mail please : ");
        scanf("%s",&e_mail);
        gotoxy(25,14);
        printf("Give me your password please : ");
        scanf("%s",&password);
        gotoxy(25,16);
        printf(" HELLO  : %s\n",one -> Fulname_name);
        gotoxy(25,17);
        printf(" e-mail  : %s\n",one -> e_mail);
        gotoxy(25,18);
        printf(" password  : %s\n",one -> password);
        gotoxy(25,19);
        printf(" ID  : %s\n",one -> ID);
    return 1;
default :
    return 0;
    }
}
void gotoxy(int x,int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}


int loop2(int i)
{
    if(i == 0 )    return 0;
    printf("\t    _|\t\t\t\t\t\t\t\t\t\t\t\t\t   |_\n");
    return loop2(i-1);
}
void wadjiha2()
{
    user * one = ( user * ) malloc(sizeof( user));
    strcpy(one->Fulname_name,"Rabah");
    strcpy( one ->e_mail,"rabahaouameur@gmail.com");
    strcpy(one->password,"Oneday21");
    strcpy(one->ID,"2020123587");
    char ch;
    do
    {
        Color (1);
        puts("\n\t\t\t\t\t\t ___________________");
        puts("\n\t\t\t\t\t\t||  FACEBOOK MINI  || ");
        puts("\t\t\t\t\t\t ___________________");
        Color(2);
        printf("\n\t     ______________________________________________________________________________________________________\n");
        loop2(15);
        Color(2);
        puts("\t    _______________________________________________________________________________________________________");
        gotoxy(25,12);
        Color(4);
        printf("choose please again : \n\n");
        gotoxy(25,13);
        Color(8);
        puts("[A] - N E W  C O M P T E  ");
        gotoxy(25,14);
        puts("[B] - I   H A V E   A C O U N T     A L R E A D Y ");
        gotoxy(25,16);
        printf("Your chose : ");
        scanf("%c",&ch);
        Color(15);
    }
    while (iktyar(ch,one) == 0);
}
int loop1(int i,char *arr)
{
    system("COLOR 0F");
    if( i == 0) printf("\n\n\n\n\n\n\t\t\t\t");
    Color(4);
    printf(" %c",*(arr+i));
    Sleep(80);
    system("COLOR F0");
    if (i == 30) return 0;
    return loop1(i+1,arr);
}
void wadjiha1 ()
{
    puts("\n\t\t\t\t\t\t  ___________________");
    puts("\n\t\t\t\t\t\t ||  FACEBOOK MINI  || ");
    puts("\t\t\t\t\t\t  ___________________");
    loop1(0,"HELLO IN MY SOCIAL MEDIA ^-^");
    Color(11);
    puts("\n\t\t\t\t\t       C R E A T E D  B Y R A B A H");
    Color(45);
    puts("\n\n\n\n\n\n\n\n \t\t\t\t\t      W E L C O M E = > L O A D I N G  ...");
    Sleep(2900);
    system("CLS");
    wadjiha2();
}
int main ()
{
    wadjiha1();
    return 0;
}
