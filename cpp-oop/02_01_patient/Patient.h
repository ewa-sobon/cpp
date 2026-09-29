#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED
#include <iostream>

class Pacjent
{
private:
    const int numer_id; //pole stale!! po utworzeniu obiektu tego pola juz nie mozna zmienic
    double wzrost;
    double waga;

public:
    Pacjent(int, double, double);
    Pacjent(const Pacjent&);
    ~Pacjent();

    void ustaw_wage(double);
    void ustaw_wzrost(double);

    friend void wyswietl(const Pacjent&);
    friend std::ostream& operator<<(std::ostream& out, const Pacjent& p);
    friend double sr_waga(Pacjent* tab[], int n);
};

void wyswietl(Pacjent* tab[], int n);
double sr_waga(Pacjent* tab[], int n);

#endif // PATIENT_H_INCLUDED
