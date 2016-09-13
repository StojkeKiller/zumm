#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <main.h>
#include <Metak.h>
#include <Igrac.h>
#include <Artifakt.h>

using namespace std;


enum result {res_reaktor, res_medic, res_normal};
enum oruzje{nijedno,pistolj,laser,bazuka};
const int pocetna_energija = 200;
const int maks_broj_reaktor = 400;
const int maks_broj_medica = 400;
Metak metak_objekat;
Igrac igrac_objekat_x;
Igrac igrac_objekat_o;
Artifakt reaktor_objekat[maks_broj_reaktor * 2];
Artifakt medic_objekat[maks_broj_medica * 2];

int brojac_medic = 1;
int brojac_reaktor = 1;
int krajigre_promenljiva = 0;
int level=1;
char matrix[xmax+2][ymax+2];
struct igrac
{
    char tip;
    int energija;
    int pozicija_metka[2];
    int poeni;
    int pozicija[2];
    int brzina;
    int energija_kretanja;
    int stanje;
    int oruzje;
};

void print_screen(void);

void beep_igrica (int frenkvencija, int vreme)
{
    if (krajigre_promenljiva == 1)
    {
        pthread_exit(NULL);
    }
    else
    {
        Beep(frenkvencija, vreme);
    }
    return;
}
void *Muzika(void *threadid)
 {
    while(1)
    {
            beep_igrica (330,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (392,100);Sleep(350);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (262,300);Sleep(150);
            beep_igrica (196,300);Sleep(150);
            beep_igrica (164,300);Sleep(150);
            beep_igrica (220,300);Sleep(50);
            beep_igrica (246,100);Sleep(150);
            beep_igrica (233,200);
            beep_igrica (220,100);Sleep(150);
            beep_igrica (196,100);Sleep(75);
            beep_igrica (330,100);Sleep(75);
            beep_igrica (392,100);Sleep(75);
            beep_igrica (440,100);Sleep(150);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (392,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(50);
            beep_igrica (247,100);Sleep(250);
            beep_igrica (262,300);Sleep(150);
            beep_igrica (196,300);Sleep(150);
            beep_igrica (164,300);Sleep(150);
            beep_igrica (220,300);Sleep(50);
            beep_igrica (246,100);Sleep(150);
            beep_igrica (233,200);
            beep_igrica (220,100);Sleep(150);
            beep_igrica (196,100);Sleep(75);
            beep_igrica (330,100);Sleep(75);
            beep_igrica (392,100);Sleep(75);
            beep_igrica (440,100);Sleep(150);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (392,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(50);
            beep_igrica (247,100);Sleep(450);
            beep_igrica (392,100);Sleep(50);
            beep_igrica (370,100);Sleep(50);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (311,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (207,100);Sleep(50);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(250);
            beep_igrica (392,100);Sleep(50);
            beep_igrica (370,100);Sleep(50);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (311,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (523,100);Sleep(150);
            beep_igrica (523,100);Sleep(50);
            beep_igrica (523,100);Sleep(550);
            beep_igrica (392,100);Sleep(50);
            beep_igrica (370,100);Sleep(50);
            beep_igrica (349,100);Sleep(50);
            beep_igrica (311,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (207,100);Sleep(50);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (220,100);Sleep(50);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(250);
            beep_igrica (311,300);Sleep(150);
            beep_igrica (296,300);Sleep(150);
            beep_igrica (262,300);Sleep(650);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(150);
            beep_igrica (330,200);Sleep(25);
            beep_igrica (262,200);Sleep(25);
            beep_igrica (220,200);Sleep(25);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(50);
            beep_igrica (330,100);Sleep(350);
            beep_igrica (440,100);Sleep(150);
            beep_igrica (392,100);Sleep(250);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (294,100);Sleep(150);
            beep_igrica (330,200);Sleep(25);
            beep_igrica (262,200);Sleep(25);
            beep_igrica (220,200);Sleep(25);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (330,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (262,100);Sleep(50);
            beep_igrica (330,100);Sleep(150);
            beep_igrica (392,100);Sleep(350);
            beep_igrica (196,100);Sleep(350);
            beep_igrica (196,100);Sleep(62);
            beep_igrica (262,100);Sleep(62);
            beep_igrica (330,100);Sleep(62);
            beep_igrica (392,100);Sleep(62);
            beep_igrica (523,100);Sleep(62);
            beep_igrica (660,100);Sleep(62);
            beep_igrica (784,100);Sleep(282);
            beep_igrica (660,100);Sleep(282);
            beep_igrica (207,100);Sleep(62);
            beep_igrica (262,100);Sleep(62);
            beep_igrica (311,100);Sleep(63);
            beep_igrica (415,100);Sleep(62);
            beep_igrica (523,100);Sleep(62);
            beep_igrica (622,100);Sleep(62);
            beep_igrica (830,100);Sleep(282);
            beep_igrica (622,100);Sleep(282);
            beep_igrica (233,100);Sleep(62);
            beep_igrica (294,100);Sleep(62);
            beep_igrica (349,100);Sleep(62);
            beep_igrica (466,100);Sleep(62);
            beep_igrica (587,100);Sleep(62);
            beep_igrica (698,100);Sleep(62);
            beep_igrica (932,100);Sleep(282);
            beep_igrica (932,100);Sleep(62);
            beep_igrica (932,100);Sleep(62);
            beep_igrica (932,100);Sleep(62);
            beep_igrica (1046,675);
    }
    pthread_exit(NULL);
 }
void ludzvuk (void)
{
    Beep(300, 10);
}
void dobarzvuk (void)
{
    Beep(3000, 10);
}
void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
void gameover (void)
{
    krajigre_promenljiva = 1;
    print_screen();
    gotoxy(0, ymax + 4);
    cout << "Game over, your score is " << igrac_objekat_x.poeni << ".";
    Beep(420, 200);
    Beep(400, 200);
    Beep(420, 200);
    Beep(400, 200);
    Beep(420, 200);
    Beep(315, 200);
    Beep(370, 200);
    Beep(335, 200);
    Beep(282, 600);
    pthread_exit(NULL);
}
char tipka(void)
{
    if (kbhit()!=0)
        return getch();
    else
        return 0;
}
void clear_console(void)
{
    system("CLS");
}
void clear_matrix(void)
{
    for(int i=0;i<xmax+2;i++)
    {
        for(int j=0;j<ymax+2;j++)
        {
            matrix[i][j]=' ';
        }
    }
}
void print_border(void)
{
    for(int i = xmax + 1; i>=0; i--)
    {
        //gotoxy(i, ymax + 1);
        matrix[i][ymax+1]='_';
    }
    for(int i = ymax + 1; i >= 0; i--)
    {
        //gotoxy(xmax+1,i);
        matrix[xmax+1][i]='|';
    }
}
void print_matrix(void)
{
    static char matrix_old[xmax+2][ymax+2];
    for(int i=0;i<xmax+2;i++)
    {
        for(int j=0;j<ymax+2;j++)
        {
            if(matrix_old[i][j]!=matrix[i][j])
            {
                gotoxy(i,j);
                cout<<matrix[i][j];
            }
        }
    }
    for(int i=0;i<xmax+2;i++)
    {
        for(int j=0;j<ymax+2;j++)
        {
            matrix_old[i][j]=matrix[i][j];
        }
    }
}
void print_screen(void)
{
    clear_matrix();
    print_border();
    for (int i = 0; i < brojac_reaktor; i++)
    {
        //gotoxy (reaktor_objekat.energija_objekat[i].pozicicija_x, reaktor_objekat.energija_objekat[i].pozicija+y);
        matrix[reaktor_objekat[i].pozicija_x][reaktor_objekat[i].pozicija_y]='!';
    }
    for (int i = 0; i < brojac_medic; i++)
    {
        //gotoxy (medic_objekat[i].pozicija_x, pos_medic[i + 1]);
        matrix[medic_objekat[i].pozicija_x][medic_objekat[i].pozicija_y]='+';
    }
    //gotoxy(pos[0], pos[1]);
    matrix[igrac_objekat_x.pozicija_x][igrac_objekat_x.pozicija_y]='X';
    if (igrac_objekat_x.energija < 0)
    {
        igrac_objekat_x.energija = 0;
    }
    //gotoxy(pos_o[0], pos_o[1]);
    matrix[igrac_objekat_o.pozicija_x][igrac_objekat_o.pozicija_y]='O';
    gotoxy(xmax+3,0);
    cout << "Tvoja energija je: " << igrac_objekat_x.energija << "        " <<endl;
    gotoxy(xmax+3, 1);
    cout << "Protivnikova energija je: " << igrac_objekat_o.energija<<"          "<< endl;
    gotoxy(xmax+3, 2);
    cout<< "Score: " << igrac_objekat_x.poeni << endl;
    if(metak_objekat.u_kretanju == true)
    {
         matrix[metak_objekat.pozicija_x][metak_objekat.pozicija_y]='*';
    }

    gotoxy(xmax+3,3);
    cout<<"Level: "<<level<<endl;
    print_matrix();
    return;
}
int igrica (int komanda)
{

    igrac_objekat_x.kretanje_igraca(komanda);
    igrac_objekat_o.target_x=igrac_objekat_x.pozicija_x;
    igrac_objekat_o.target_y=igrac_objekat_x.pozicija_y;
    igrac_objekat_o.kretanje_igraca(nista);
    if(komanda==pucanj_desno || komanda==pucanj_dole || komanda==pucanj_gore || komanda==pucanj_levo)
    {
        metak_objekat.ispali(igrac_objekat_x.pozicija_x,igrac_objekat_x.pozicija_y,komanda);
    }
    metak_objekat.kretanje();
    for (int i = 0; i < brojac_reaktor; i++)
    {
        if ((igrac_objekat_x.pozicija_x == reaktor_objekat[i].pozicija_x) && (igrac_objekat_x.pozicija_y == reaktor_objekat[i].pozicija_y))
        {
            igrac_objekat_x.energija = igrac_objekat_x.energija + reaktor_objekat[i].energija;
            for (int j = 0; j < brojac_reaktor; j++)
            {
                reaktor_objekat[j].pozicija_x = rand() % xmax + 1;
                reaktor_objekat[j].pozicija_y = rand() % ymax + 1;
            }
            brojac_reaktor++;
            return res_reaktor;
        }
    }
    for (int i = 0; i < brojac_reaktor; i++)
    {
        if ((igrac_objekat_o.pozicija_x == reaktor_objekat[i].pozicija_x) && (igrac_objekat_o.pozicija_y == reaktor_objekat[i].pozicija_y))
        {
            igrac_objekat_o.energija = igrac_objekat_o.energija + reaktor_objekat[i].energija;
            for (int j = 0; j < brojac_reaktor; j++)
            {
                reaktor_objekat[j].pozicija_x = rand() % xmax + 1;
                reaktor_objekat[j].pozicija_y = rand() % ymax + 1;
            }
            brojac_reaktor++;
            return res_reaktor;
        }
    }
    for (int i = 0; i < brojac_medic; i++)
    {
        if ((igrac_objekat_x.pozicija_x == medic_objekat[i].pozicija_x) && (igrac_objekat_x.pozicija_y == medic_objekat[i].pozicija_y))
        {
            igrac_objekat_x.energija = igrac_objekat_x.energija + medic_objekat[i].energija;
            for (int j = 0; j < brojac_medic; j++)
            {
                medic_objekat[j].pozicija_x = rand() % xmax + 1;
                medic_objekat[j].pozicija_y = rand() % ymax + 1;
            }
            brojac_medic++;
            return res_medic;
        }
    }
    for (int i = 0; i < brojac_medic; i++)
    {
        if ((igrac_objekat_o.pozicija_x == medic_objekat[i].pozicija_x) && (igrac_objekat_o.pozicija_y == medic_objekat[i].pozicija_y))
        {
            igrac_objekat_o.energija = igrac_objekat_o.energija + medic_objekat[i].energija;
            for (int j = 0; j < brojac_medic; j++)
            {
                medic_objekat[j].pozicija_x = rand() % xmax + 1;
                medic_objekat[j].pozicija_y = rand() % ymax + 1;
            }
            brojac_medic++;
            return res_medic;
        }
    }
    if(igrac_objekat_o.energija<=0)
    {
        igrac_objekat_x.poeni=igrac_objekat_x.poeni+50;
        igrac_objekat_o.energija=100;
        level++;
        igrac_objekat_o.pozicija_x = rand() % xmax + 1;
        igrac_objekat_o.pozicija_y = rand() % ymax + 1;
    }

    if (metak_objekat.pozicija_x == igrac_objekat_o.pozicija_x && metak_objekat.pozicija_y == igrac_objekat_o.pozicija_y)
    {
        metak_objekat.u_kretanju=false;
        igrac_objekat_o.energija=igrac_objekat_o.energija-10;
        igrac_objekat_x.poeni = igrac_objekat_x.poeni + 10;
    }
    if (igrac_objekat_x.pozicija_x == igrac_objekat_o.pozicija_x && igrac_objekat_x.pozicija_y == igrac_objekat_o.pozicija_y)
    {
        gameover();
    }
    print_screen();
    return res_normal;
}
int main (int argc, char *argv[])
{
    igrac_objekat_x.izgled = 'X';
    igrac_objekat_o.izgled = 'O';
    igrac_objekat_x.energija = 200;
    igrac_objekat_o.energija = 100;
    igrac_objekat_x.pozicija_x=0;
    igrac_objekat_x.pozicija_y = 0;
    igrac_objekat_x.tip = human;
    igrac_objekat_o.tip = ai;
    srand(time(NULL));
    igrac_objekat_o.pozicija_x = rand() % xmax + 1;
    igrac_objekat_o.pozicija_y = rand() % ymax + 1;
    for(int i =0;i <maks_broj_reaktor;i++)
    {
        reaktor_objekat[i].izgled = '!';
        medic_objekat[i].energija =-10;
    }
    for(int i =0;i <maks_broj_medica;i++)
    {
        medic_objekat[i].izgled= '+';
        medic_objekat[i].energija = 20;
    }
    reaktor_objekat[0].pozicija_x =  rand() % xmax + 1;
    reaktor_objekat[0].pozicija_y =  rand() % ymax + 1;
    medic_objekat[0].pozicija_x =  rand() % xmax + 1;
    medic_objekat[0].pozicija_y =  rand() % ymax + 1;

    reaktor_objekat[0].pozicija_x = rand() % xmax + 1;
    reaktor_objekat[1].pozicija_x = rand() % ymax + 1;
    medic_objekat[0].pozicija_x = rand() % xmax + 1;
    medic_objekat[0].pozicija_x = rand() % ymax + 1;
    //pos_o[0] = rand() % xmax + 1;
    //pos_o[1] = rand() % ymax + 1;
    pthread_t threads;
    long t;
    pthread_create(&threads, NULL, Muzika, (void *)t);
    int stanje = 0;
    char c;
    print_screen();
    while(1)
    {
        c = tipka();
        if (c == 'w')
        {
            stanje = igrica(gore);
        }
        else if (c == 'a')
        {
            stanje = igrica(levo);
        }
        else if (c == 's')
        {
            stanje = igrica(dole);
        }
        else if (c == 'd')
        {
            stanje = igrica(desno);
        }
        else if (c == 'l')
        {
            stanje = igrica(pucanj_desno);
        }
        else if(c=='j')
        {
                stanje = igrica(pucanj_levo);
        }
        else if(c=='i')
        {
                stanje = igrica(pucanj_gore);
        }
        else if(c=='k')
        {
            stanje = igrica(pucanj_dole);
        }
        else
        {
            stanje = igrica(nista);
            igrica(nista);
            c = 0;
        }
        if (c != 0)
        {
            if (stanje == res_reaktor)
            {
                ludzvuk();
            }
            if (stanje == res_medic)
            {
                dobarzvuk();
            }
        }
        if (igrac_objekat_x.energija <= 0)
        {
            break;
        }
    }
    gameover();
    pthread_exit(NULL);
}
