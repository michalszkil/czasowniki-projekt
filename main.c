#include <stdio.h>
#define ROZMIAR 3
#define MAX 17
#include "gui.h"
#include "logika.h"

extern struct rekord baza;

extern char input [MAX];//Tu przetrzymywane s¹ dane wprowadzone przez u¿ytkownika

extern int punkty;//Ilosc punktow zdobyta podczas testu

extern int liczrek;//Liczba rekordow
int main()
{
    liczrek=liczrekordy();
   // printf("%d\n\n", liczrek); // test liczenia rekordow
    int koniec=0;
    przywitanie();
    wyswietlmenu();
    while(!koniec)
    {

        char x;//Wybor opcji z menu
        int nrrek;//Wybor rekordu w menu edycji
        scanf("%c", &x);
        fflush(stdin);//Ochrona przed kilkukrotnym wybraniem tej samej opcji
        switch(x)
        {
        case '1':
            losuj();
            wylosowano();
            czasstart();
            test();
            czasstop();
            wyswietlmenu();
            break;
        case '2':
            wyswietlwszystko();
            wyswietlmenu();
            break;
        case '3':
            menuedycji();
            scanf(" %c", &x);
            fflush(stdin);//Ochrona przed kilkukrotnym wybraniem tej samej opcji
            switch(x)
            {
            case '1':
                dodaj();
                break;
            case '2':
                wyswietlwszystko();
                wybnrusun();
                while(1)//Ochrona przed podaniem zlego numeru
                {
                    if(1==scanf("%d", &nrrek)&& nrrek>=1 && nrrek<=liczrek)
                    {
                        fflush(stdin);
                        usun(nrrek);
                        break;
                    }
                    if(nrrek==0)
                        break;
                    else
                    blednynr();
                    fflush(stdin);
                }
                //printf("\n\n\n\n%d\n\n\n\n", nrrek); //test numeru rekordu
                break;
            case '3':
                wyswietlwszystko();
                wybnrpodmien();
                while(1)//Ochrona przed podaniem zlego numeru
                {
                    if(1==scanf("%d", &nrrek)&& nrrek>=1 && nrrek<=liczrek)
                    {
                        fflush(stdin);
                        podmien(nrrek);
                        break;
                    }
                    if(nrrek==0)
                        break;
                    else
                    blednynr();
                    fflush(stdin);
                }
                break;
            case '4':
                break;
            default:
                break;
            }
            wyswietlmenu();
            break;
        case '4':
            koniec=1;
            break;
        default:
            break;

        }
    }
    return 0;
}
