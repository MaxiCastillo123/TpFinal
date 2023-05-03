#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "gotoxy.h"
#include <windows.h>
#include "Estetica.h"

void bannerRecuadro()
{
    int a=rand()%10+1;
    int b=rand()%9+1;

    for (int i = 24; i>-1; i--)
    {
        color(14);
        gotoxy(1,i);
        printf("%c",219);

    }
    for (int i =2; i<51; i++)
    {

        gotoxy(i,0);
        printf("%c",223);

    }
    for (int i =0; i<25; i++)
    {

        gotoxy(51,i);
        printf("%c",219);

    }
    for (int i =50; i>1; i--)
    {

        gotoxy(i,24);
        printf("%c",220);

    }
    color(7);


}
void bannerBienvenida()
{
    for (int h =1; h<2; h++)
    {
        gotoxy(13,1);
        color(6);
       bannerMateria();
        Sleep(8);

        gotoxy(15,3);
        color(6);
     bannerTrabajoPractico();
        Sleep(8);

        gotoxy(15,5);
        color(5);
       bannerIntegrantes();
        Sleep(8);

        gotoxy(19,7);
        color(2);
      bannerAndrea();
        Sleep(8);

        gotoxy(15,9);
        color(2);
        bannerMaximiliano();
        Sleep(8);

        gotoxy(19,11);
        color(2);
       bannerVictoria();
        Sleep(8);

        gotoxy(14,13);
        color(2);
       bannerEmiliano();
        Sleep(8);

        gotoxy(19,15);
        color(2);
       bannerEmanuel();
        Sleep(8);

        color(15);
        gotoxy(11,17);
        printf("Presione una tecla para cargar.");

    }
    getch();
}
void bannerMateria()
{
    printf("B");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("v");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("d");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("L");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("b");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("2");
    Sleep(25);
}
void bannerTrabajoPractico()
{

    printf("T");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("b");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("j");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("P");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("c");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("c");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("F");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("l");
    Sleep(25);
}
void bannerIntegrantes()
{
    printf("I");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("g");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("d");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("q");
    Sleep(25);
    printf("u");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("p");
    Sleep(25);
    printf("o");
    Sleep(25);
}
void bannerAndrea()
{
    printf("B");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("c");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf(",");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("A");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("d");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("a");
    Sleep(25);
}
void bannerMaximiliano()
{
    printf("C");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(",");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("M");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("x");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("m");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("o");
    Sleep(25);
}

void bannerEmiliano()
{
    printf("S");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(",");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("E");
    Sleep(25);
    printf("m");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("A");
    Sleep(25);
    printf("g");
    Sleep(25);
    printf("u");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("n");
    Sleep(25);

}

void bannerVictoria()
{
    printf("C");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("b");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(",");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("V");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("c");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("a");
    Sleep(25);
}

void bannerEmanuel()
{
    printf("P");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf(",");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("E");
    Sleep(25);
    printf("m");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("u");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("l");
    Sleep(25);

}
