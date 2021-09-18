#ifndef LOGIKA_H_INCLUDED
#define LOGIKA_H_INCLUDED

struct rekord{
    char form1[MAX];
    char form2[MAX];
    char form3[MAX];
    char tlum[MAX];
    };

void wybierz(int);
int porownaj(char[], char[]);
void sprawdz(char[], char[]);
void losuj(void);
void test(void);
void usun (int);
void podmien(int);
void dodaj(void);
int liczrekordy(void);

#endif // LOGIKA_H_INCLUDED
