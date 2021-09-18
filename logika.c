#include <stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
#define MAX 17//Max dlugosc wyrazu
#define TAB 3 // Ilosc wylosowanych rekordow - rozmiar tablicy wybranych rekordow - ilosc przykladow do rozwiazania podczas testu
#include "gui.h"
#include "logika.h"

struct rekord baza;

char input [MAX];

int punkty=0;

int numery [TAB];// tablica wylosowanych przykladow

int formy [TAB];// tablica wylosowanych typów jakie bêd¹ podane u¿ytkownikowi

int liczrek;

void wybierz(int x)//wpisuje pobrany rekord do struktury
{
     FILE* fp;
    char c;
    int a=1;
    char form1[MAX];
    char form2[MAX];
    char form3[MAX];
    char tlum[MAX];
    if ((fp=fopen("dane.txt", "r"))!=NULL)
    {
         fseek(fp, 0, SEEK_SET);
         while(a!=x)
         {
             c = fgetc (fp);
             if(c=='\n')
                a++;
         }
        fscanf(fp, "%s %s %s %s\n", form1, form2, form3, tlum);
        strcpy(baza.form1, form1);
        strcpy(baza.form2, form2);
        strcpy(baza.form3, form3);
        strcpy(baza.tlum, tlum);

        fclose(fp);
    }
    else
    printf("Nie udalo sie otworzyc plku tekstowego.");
}

int porownaj(char input[], char wzor[])//Funkcja porownujaca wpisany wyraz ze wzorcowym. Zwraca 0 przy blednej odpowiedzi, 1 gdy uzytkownik dostaje drug¹ szanse na wpisanie, 2 gdy odpowiedz jest poprawna.
{
    int err;//licznik bledow
    int err1;//licznik bledow
    int err2;//licznik bledow
    int a;//nr porownywanego znaku
    int diff=abs(strlen(input)-strlen(wzor));//modul z roznicy dlugosci
    if(strlen(input)==strlen(wzor))
    {
        err=0;
        for(a=0;a<strlen(wzor);a++)
            {
                if(input[a]!=wzor[a])
                {
                    err++;
                }
            }
        if(err>3)
        {
            return 0;
        }
        if(err==1 || err==2 || err==3)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    if (diff>2)
    {
            return 0;
    }
    else //if (abs(strlen(input)-strlen(wzor))<2)
    {
       if(strlen(input)<strlen(wzor))
       {
            err1=0;
            err2=0;
            for(a=0;a<strlen(input);a++)
                {
                    if(input[a]!=wzor[a])
                    {
                        err1++;
                    }
                }
            for(a=strlen(wzor)-1;a>=diff;a--)
                {
                    if(input[(a-diff)]!=wzor[a])
                    {
                        err2++;
                    }
                }
           if(err1<=2 || err2<=2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
       else //  if(strlen(input)>strlen(wzor))
       {
            err1=0;
            err2=0;
            for(a=0;a<strlen(wzor);a++)
                {
                    if(input[a]!=wzor[a])
                    {
                        err1++;
                    }
                }
            for(a=strlen(input)-1;a>=diff;a--)
                {
                    if(input[a]!=wzor[(a-diff)])
                    {
                        err2++;
                    }
                }
            if(err1<=2 || err2<=2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

void sprawdz(char input[],char wzor[])// Funkcja wyswietla odpowiednie komunikaty o poprawnosci odpowiedzi, ew. prosi o ponowne wpisanie wyrazu.
{
    scanf("%s", input);
    if(porownaj(input,wzor)==2)
    {
        punkty++;
        dobra();
    }
    else if(porownaj(input, wzor)==1)
    {
        literowka();
        scanf("%s", input);
        if(porownaj(input, wzor)==2)
        {
            dobra();
            punkty++;
        }
        if(porownaj(input, wzor)==1)
        bledna(wzor);

        if(porownaj(input, wzor)==0)
        bledna(wzor);
    }
    else if(porownaj(input, wzor)==0)
    bledna(wzor);
}

void losuj(void)//Losuje zestawy czasownikow z bazy danych oraz forme ktora zostanie podana uzytkownikowi.
{
    int i;
    int j;
    srand(time(NULL));
    for(i=0; i<TAB; i++)
    {
        int flaga=0; // sprawdzam czy wartosc sie powtorzyla
        int x;
        while(!flaga)
        {
            flaga=1;
            x = rand() % liczrek + 1;
            for (j=0;j<i;j++)
            {
                if (x == numery[j])
                {
                flaga=0;
                break;
                }
            }

        }
        numery[i]=x;
        formy[i]= rand() % 4 + 1;
        //printf("%d %d\n", numery[i], formy[i]);// test losowania
    }
}

void podaj(int x)//Funkcja kieruje sprawdzaniem odpowiednich form czasownika i wyswietlaniem odpowiednich komunikatow w zaleznosci od formy ktora wylosowano.
{
    if(x==1)
    {
        podaj2();
        sprawdz(input, baza.form2);
        podaj3();
        sprawdz(input, baza.form3);
        podaj4();
        sprawdz(input, baza.tlum);
    }
    if(x==2)
    {
        podaj1();
        sprawdz(input, baza.form1);
        podaj3();
        sprawdz(input, baza.form3);
        podaj4();
        sprawdz(input, baza.tlum);
    }
    if(x==3)
    {
        podaj1();
        sprawdz(input, baza.form1);
        podaj2();
        sprawdz(input, baza.form2);
        podaj4();
        sprawdz(input, baza.tlum);
    }
    if(x==4)
    {
        podaj1();
        sprawdz(input, baza.form1);
        podaj2();
        sprawdz(input, baza.form2);
        podaj3();
        sprawdz(input, baza.form3);
    }
}

void test(void)//Pobiera do struktury odpowiedni rekord i wyswietla odpowiedznie komunikaty przed sprawdzeniem czasownikow jak rowniez podaje wynik punktowy
{
    int i;
    for(i=0; i<TAB; i++)
    {
        wybierz(numery[i]);
        if(formy[i]==1)
            wylosowano1(baza);
        if(formy[i]==2)
            wylosowano2(baza);
        if(formy[i]==3)
            wylosowano3(baza);
        if(formy[i]==4)
            wylosowano4(baza);
            podaj(formy[i]);

    }
    wynik(punkty, TAB);
    punkty=0;
}


void usun(int x)//Usuwa wybrany rekord
{
     FILE *fp, *nowy;
    char c;
    int a=1;
    int blok=0;// blokada przed zostawianiem pustch linijek w pliku
    if ((fp=fopen("dane.txt", "r"))!=NULL)
    {
        nowy = fopen("nowedane.txt", "w");
        c=getc(fp);
        while (c != EOF)
        {

            if (c == '\n')
            a++;
            if(a==x && c == '\n' && x!=1 && x!=liczrek)
                 putc(c, nowy);
            if (a<x)
            {
                putc(c, nowy);
            }
            if (a>x && blok!=0)
            {
                putc(c, nowy);
            }
            if(a>x)
            {
                blok++;
            }

            c = getc(fp);
        }
    liczrek--;
    fclose(fp);
    fclose(nowy);
    remove("dane.txt");
    rename("nowedane.txt", "dane.txt");
    }
    else
    printf("Nie udalo sie otworzyc plku tekstowego.");
}

int liczrekordy(void)//Funkcja liczaca ilosc rekordow w pliku tekstowym
{
    FILE* fp;
    char c;
    int a=1;
    int blok=0;//Flaga wprowadzona dla unikniecia sytuacji w ktorej \n na koncu ostatniego rekordu niepotrzebnie zwieksza liczbe rekordow
    if ((fp=fopen("dane.txt", "r"))!=NULL)
    {
         fseek(fp, 0, SEEK_SET);
         while(c!=EOF)
         {
             c = fgetc (fp);
             if(c=='\n')
             {
                  a++;
                  blok=1;
             }
             if(c==EOF && blok==1)
             {
                  a--;
             }
             if(c!='\n'&& c!=EOF)
             {
                  blok=0;
             }

         }
        fclose(fp);
    }
    else
    printf("Nie udalo sie otworzyc plku tekstowego.");
    return a;
}

void podmien(int x)//Funkcja podmienia rekord
{
    char form1[MAX];
    char form2[MAX];
    char form3[MAX];
    char tlum[MAX];
    int koniec=1;
    podajrek();
    fflush(stdin);
    scanf("%16s %16s %16s %16s", form1, form2, form3, tlum);
    //printf("%s %s %s %s\n", form1, form2, form3, tlum);// test
    if(strcmp(form1,"0")==0 && strcmp(form2,"0")==0 && strcmp(form3,"0")==0 && strcmp(tlum,"0")==0)
    koniec=1;
    if (!koniec)
   {

     FILE *fp, *nowy;
    char c;
    int a=1;
    int blok=0;// Blokada przed wpisaniem nowego rekordu wiecej razy niz potrzeba.
    if ((fp=fopen("dane.txt", "r"))!=NULL)
    {
        nowy = fopen("nowedane.txt", "w+");
        c=getc(fp);
        while (c != EOF)
        {
            if (c == '\n')
            a++;
            if(a==x && blok==0)
            {
                if(x!=1)
                {
                    fprintf(nowy, "\n");
                }
                fprintf(nowy,"%s %s %s %s", form1, form2, form3, tlum);
                fflush(stdin);
                blok=1;
            }
            if (a<x || a>x)
            {
                putc(c, nowy);
            }
            c = getc(fp);
        }
    fclose(fp);
    fclose(nowy);
    remove("dane.txt");
    rename("nowedane.txt", "dane.txt");
    }
    else
    printf("Nie udalo sie otworzyc plku tekstowego.");
   }

}

void dodaj(void)//Funkcja dodaje nowy rekord
{
    char form1[MAX];
    char form2[MAX];
    char form3[MAX];
    char tlum[MAX];
    podajrek();
    fflush(stdin);
    int koniec=0;
    scanf("%16s %16s %16s %16s", form1, form2, form3, tlum);
   // printf("%s %s %s %s\n", form1, form2, form3, tlum); //test
   if(strcmp(form1,"0")==0 && strcmp(form2,"0")==0 && strcmp(form3,"0")==0 && strcmp(tlum,"0")==0)
    koniec=1;
    if (!koniec)
   {
       FILE *fp, *nowy;
    char c;
    if ((fp=fopen("dane.txt", "r"))!=NULL)
    {
        nowy = fopen("nowedane.txt", "w+");
        c=getc(fp);
        while (c != EOF)
        {
            putc(c, nowy);
            c = getc(fp);
        }
        if(c!='\n')
        fprintf(nowy, "\n");

        fprintf(nowy,"%s %s %s %s", form1, form2, form3, tlum);
        fflush(stdin);
        liczrek++;
    fclose(fp);
    fclose(nowy);
    remove("dane.txt");
    rename("nowedane.txt", "dane.txt");
    }
    else
    printf("Nie udalo sie otworzyc plku tekstowego.");
   }

}
