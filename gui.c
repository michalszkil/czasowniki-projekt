#include <stdio.h>
#include <time.h>
#include "gui.h"
#define MAX 17//Max dlugosc wyrazu
#include"logika.h"

int liczrek;

struct rekord baza;

    time_t start;
    time_t stop;

void dobra(void)
{
    printf("Dobra odpowiedz\n");
}

void bledna(char forma [])
{
    printf("Bledna odpowiedz\nPrawidlowa odpowiedz to \"%s\"\n", forma);
}

void literowka(void)
{
    printf("Literowka? Sprobuj jeszcze raz.\n");
}

void wylosowano1(struct rekord baza)
{
    printf("Wylosowano: infinitive: %s\n", baza.form1);
}
void wylosowano2(struct rekord baza)
{
    printf("Wylosowano: past tense: %s\n", baza.form2);
}
void wylosowano3(struct rekord baza)
{
    printf("Wylosowano: past participle: %s\n", baza.form3);
}
void wylosowano4(struct rekord baza)
{
    printf("Wylosowano: tlumaczenie: %s\n", baza.tlum);
}

void podaj1(void)
{
    printf("Podaj forme infinitive\n");
}

void podaj2(void)
{
    printf("Podaj forme past tense\n");
}

void podaj3(void)
{
    printf("Podaj forme past participle\n");
}

void podaj4(void)
{
    printf("Podaj tlumaczenie\n");
}

void wynik(int a, int b)
{
    printf("Twoj wynik to: %d/%d\n", a, (3*b));
}

void przywitanie(void)
{
    printf("Witaj\n");
}
void wyswietlmenu(void)
{
    printf("Wybierz opcje:\n");
    printf("[1] Rozpoczecie testu\n");
    printf("[2] Wyswietlenie wszystkich zapisanych czasownikow\n");
    printf("[3] Modyfikacja rekordow\n");
    printf("[4] Wyjscie z programu\n");
}

void wylosowano(void)
{
    printf("Wylosowano 20 czasownikow nieregularnych, do kazdego czasownika nalezy dopasowac 3 pozostale formy.\n");
}

void czasstart(void)
{
    time(&start);
}

void czasstop(void)
{
    time(&stop);
    int czas = difftime(stop, start);
    printf("Czas trwania testu: %d minut %d sekund\n", czas/60, czas%60);
}

void menuedycji(void)
{
    printf("Wybierz opcje:\n");
    printf("[1] Dodanie rekordu\n");
    printf("[2] Usuniecie rekordu\n");
    printf("[3] Zamiana rekordu\n");
    printf("[4] Wyjscie z menu edycji rekordow\n");
}

void wybnrusun(void)
{
    printf("Wybierz numer rekordu do usuniecia.0 by anulowac.\n");
}

void blednynr(void)
 {
     printf("Podano bledny numer rekordu.\n");
 }

void wybnrpodmien(void)
 {
     printf("Wybierz numer rekordu do zamiany.0 by anulowac.\n");
 }
void podajrek(void)
{
    printf("Podaj nowy rekord w postaci:Forma1 Forma2 Forma3 Tlumaczenie.\nMaksymalnie 16 znakow.\nWpisz 0 0 0 0 by anulowac.\n");
}

void legenda(void)
{
    printf("%.02s %-16s %-16s %-16s %-16s\n", "Nr","Infinitive", "Past Simple", "Past Participle", "Tlumaczenie");
}

void wyswietlwszystko(void)
{
    int x;
    legenda();
    for(x=1; x<=liczrek; x++)
    {
        wybierz(x);
        printf("%02d %-16s %-16s %-16s %-16s\n", x, baza.form1, baza.form2, baza.form3, baza.tlum);
    }
}

void zadlugi(void)
{
    printf("Podano za długi rekord\n");
}
