#include <iostream>
#include "Patient.h"

using namespace std;


Pacjent::Pacjent(int nr, double wz, double wg)
    :numer_id{nr}, wzrost{wz}, waga{wg}
{}

Pacjent::Pacjent(const Pacjent& p)
    :numer_id{p.numer_id+1}, wzrost{p.wzrost}, waga{p.waga} // id+1 bo kopiowanie numeru który ma byc unikalny jest bez sensu.
{}

Pacjent::~Pacjent()
{
    cout<<"Usuwam dane pacjenta o numerze identyfikacyjnym: "<<this->numer_id<<endl;
}

void    Pacjent::ustaw_wage(double wg)
{

    this->waga=wg;
}

void    Pacjent::ustaw_wzrost(double wz)
{

    this->wzrost=wz;
}

void wyswietl(const Pacjent& p)
{
    cout<<"Pacjent numer id: "<<p.numer_id<<"\twzrost[m]: "<<p.wzrost<<"\twaga[kg]: "<<p.waga<<endl;
}

ostream& operator<<(ostream& out, const Pacjent& p)
{
    out<<"Pacjent numer id: "<<p.numer_id<<"\twzrost[m]: "<<p.wzrost<<"\twaga[kg]: "<<p.waga<<endl;
    return out;
}

void wyswietl(Pacjent* tab[], int n)
{
    for(int i=0; i<n; i++)
    {
        wyswietl(*tab[i]);
    }
}


double sr_waga(Pacjent* tab[], int n)
{
    double suma = 0.0;
    for(int i=0; i<n; i++)
    {
        suma = suma + tab[i]->waga;
    }
    return suma/n;
}

