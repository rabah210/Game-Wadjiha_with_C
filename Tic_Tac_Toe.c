#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct player player;
struct player
{
    char noun[10];
    float numpl;
    char playerchar;
    char assist[10];
};
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
bool checks_if_win(player p1,player p2,char Array[][3])
{
    if ((Array [0][0] == p1.playerchar && Array [0][1] == p1.playerchar && Array [0][2] == p1.playerchar) || (Array [1][0] == p1.playerchar && Array [1][1] == p1.playerchar && Array [1][2] == p1.playerchar) || (Array [2][0] == p1.playerchar && Array [2][1] == p1.playerchar && Array [2][2] == p1.playerchar))
    {
        Color(2);
        printf("  Congratulations %s : you are the winner \a\a",p1.noun);
        return true;
    }
    else if ( (Array [0][0] == p2.playerchar && Array [0][1] == p2.playerchar && Array [0][2] == p2.playerchar) || (Array [1][0] == p2.playerchar && Array [1][1] == p2.playerchar && Array [1][2] == p2.playerchar) || (Array [2][0] == p2.playerchar && Array [2][1] == p2.playerchar && Array [2][2] == p2.playerchar))
    {
        Color(2);
        printf("  Congratulations %s : you are the winner\a\a",p2.noun);
        return true;
    }
    else if ( Array[0][0] == p1.playerchar && Array[1][0] == p1.playerchar && Array[2][0] == p1.playerchar || Array[0][1] == p1.playerchar && Array[1][1] == p1.playerchar && Array[2][1] == p1.playerchar || Array[0][2] == p1.playerchar && Array[1][2] == p1.playerchar && Array[2][2] == p1.playerchar )
    {
        Color(2);
        printf("  Congratulations %s : you are the winner\a\a",p1.noun);
        return true;
    }
    else if ( Array[0][0] == p2.playerchar && Array[1][0] == p2.playerchar && Array[2][0] == p2.playerchar || Array[0][1] == p2.playerchar && Array[1][1] == p2.playerchar && Array[2][1] == p2.playerchar || Array[0][2] == p2.playerchar && Array[1][2] == p2.playerchar && Array[2][2] == p2.playerchar )
    {
        Color(2);
        printf("  Congratulations %s : you are the winner\a\a",p2.noun);
        return true;
    }
    else if ( Array[0][0] == p1.playerchar && Array[1][1] == p1.playerchar && Array[2][2] == p1.playerchar || Array[2][0] == p1.playerchar && Array[1][1] == p1.playerchar && Array[0][2] == p1.playerchar  )
    {
        Color(2);
        printf("  Congratulations %s : you are the winner\a\a",p1.noun);
        return true;
    }
    else if ( Array[0][0] == p2.playerchar && Array[1][1] == p2.playerchar && Array[2][2] == p2.playerchar || Array[2][0] == p2.playerchar && Array[1][1] == p2.playerchar && Array[0][2] == p2.playerchar  )
    {
        Color(2);
        printf("  Congratulations %s : you are the winner\a\a",p2.noun);
        return true;
    }
    else
    {
        puts("\n There is no winner ");
    }
    return false;
}

bool delclaration_game_face(player p1, player p2 )
{
    int index1,index2,index3;
    char Array[3][3] = { {'1','2','3' }, {'4','5','6'}, {'7','8','9'} };
    for( index1=0 ; index1<9 ; index1++ ){
        for( index2=0 ; index2<3 ; index2++ ){
            for(index3=0; index3<3; index3++)
            {
                if( Array[index2][index3] == p1.assist[index1] )  Array[index2][index3] = p1.playerchar;
                if( Array[index2][index3] == p2.assist[index1] )  Array[index2][index3] = p2.playerchar;
            }
        }
    }

    printf("\n_ _ _\n");
    for(index1=0; index1<3; index1++)
    {
        printf("|");
        for(index2=0; index2<3; index2++)
        {
            printf(" %c ",Array[index1][index2]);
        }
        printf("\n _ _ _\n");
    }
    return checks_if_win( p1, p2, Array ) ;
}
void declaration_char_in_witch_number(player p1, player p2)
{
    int count=0;
    do
    {

        printf("\n %s :",p1.noun);
        printf(" Give me a %c in witch number : ",p1.playerchar);
        p1.assist[count]= getche();
        if( delclaration_game_face( p1,  p2 ) == true ) break;
        printf("\n %s :",p2.noun);
        printf(" Give me a %c in witch number : ",p2.playerchar);
        p2.assist[count] = getche();
        count++;

    }
    while( delclaration_game_face( p1,  p2 ) == false  );
}
void Taba3_cond_player_one(player p1,player p2)
{
    if( p1.playerchar == 'X' )
    {
        printf("\n  so let's go  %s : X ,  %s : O ",p1.noun,p2.noun);
        p2.playerchar = 'O';
    }
    else if ( p1.playerchar == 'O')
    {
        printf("\n  So let's go  %s : O ,  %s : X",p1.noun,p2.noun);
        p2.playerchar = 'X';
    }
    declaration_char_in_witch_number( p1,  p2);
}
bool condition_player_one(player p1,player p2)
{
    system("cls");
    system("COLOR F0");
    Color(2);
    printf("\n  %s :",p1.noun);
    Color(0);
    printf("You will be to choose first your char (x or o) => ");
    p1.playerchar = getche();
    if ( p1.playerchar == 'x' )  p1.playerchar = 'X';
    if ( p1.playerchar == 'o' )  p1.playerchar = 'O';
    if( ( p1.playerchar == 'X' ) || (p1.playerchar == 'O' ))
    {
        Taba3_cond_player_one( p1, p2 );
        return true;
    }
    else
    {
        Color(4);
        printf("\n  Erreur...please don't write another char\n\n");
        return false ;
    }
}
void Taba3_cond_player_two( player p1, player p2 )
{
    if( p2.playerchar == 'X' )
    {
        printf("\n  so let's go  %s : O , %s : X",p1.noun,p2.noun );
        p1.playerchar = 'O';
    }
    else if ( p2.playerchar == 'O' )
    {
        printf("\n  So let's go  %s : X , %s : O",p1.noun,p2.noun);
        p1.playerchar = 'X';
    }
    declaration_char_in_witch_number( p1, p2 );
}
bool condition_player_two( player p1, player p2 )
{
    system("cls");
    system("COLOR F0");
    Color(2);
    printf("\n  %s :",p2.noun);
    Color(0);
    printf("You will be to choose first your char (x or o) => ");
    p2.playerchar = getche();

    if ( p2.playerchar == 'x' ) p2.playerchar = 'X';
    if ( p2.playerchar == 'o' ) p2.playerchar = 'O';
    if( (p2.playerchar == 'X' ) || ( p2.playerchar == 'O' ) )
    {
        Taba3_cond_player_two( p1, p2 );
        return true;
    }
    else
    {
        Color(4);
        printf("\n  Erreur...please don't write another char\n\n ");
        return false;
    }
}
int mynumber(player p1,player p2)
{
    int i;
    for( i=0; i<p1.numpl || i<p2.numpl ; i++)
    {
        if ( i > abs ( p1.numpl - p2.numpl ) )  i+=70;
        else  i=i-30;
    }
    return i;
}
int condition( player p1, player p2 )
{
    // my number is function return a number
    if( abs( p2.numpl - mynumber( p1, p2 ) ) > abs( p1.numpl - mynumber( p1, p2 ) ) )
    {
        while( condition_player_one( p1, p2 ) == false )
        {
            system("cls");
            system("COLOR F0");
            Color(4);
            puts(" Re-Enter again pleaser :  ");
            Color(15);
            condition_player_one( p1, p2 );
        }
        return 1;
    }
    else if ( abs( p2.numpl - mynumber( p1, p2 ) ) < abs( p1.numpl - mynumber( p1, p2 ) ) )
    {
        while ( condition_player_two( p1, p2 ) == false )
        {
            system("cls");
            system("COLOR F0");
            Color(4);
            puts(" Re-Enter again please :  ");
            Color(15);
            condition_player_two( p1, p2 );
        }
        return 1;
    }
    else if ( p1.numpl == p2.numpl  )
    {
        Color(4);
        puts("\n  DON'T GIVE ME THE SAME NUMBER    \n\n  Re-enter again : ");
        return 0;
    }
}

void scan_num( player p1, player p2 )
{
    puts("\n ** Let's play a small game who will choose his symbol first");
    puts(" ** Okey A simple rule : you will give each of a number.The winner is who chooses the number closest to my mind (:...Good luck ");
    do
    {
        Color(2);
        printf("\n  %s :",p1.noun);
        Color(15);
        printf(" Give me your number please => ");
        scanf(" %f",&p1.numpl);
        Color(2);
        printf("\n  %s :",p2.noun);
        Color(15);
        printf(" Give me your number please => ");
        scanf(" %f",&p2.numpl);
    }
    while ( condition( p1, p2 ) == 0   );
}
int main ()
{
    char again;
    int assist;
    do  {
        system ("cls");
        system("COLOR 0F");
        printf("\t WELCOME TO MY GAME *-*  \n");
        player p1,p2;
        printf("\n  PLAYER 1 : Give me  yourname please : ");
        scanf(" %s",&p1.noun);
        printf("\n  PLAYER 2 : Give me  yourname please : ");
        scanf("%s",&p2.noun);
        //I use ASCII code for to change the first char in your name
        assist = p1.noun[0];
        if( assist>90  ) p1.noun[0] = assist - 32;
        assist=p2.noun[0];
        if(  assist>90 ) p2.noun[0] = assist - 32 ;
        scan_num(p1,p2);
        Color(4);
        printf("\n  if you want to exit click 0 (ZERO) or if you want to continue click any key : ");
        again = getch();
    }
    while(again  == '0' );
}
