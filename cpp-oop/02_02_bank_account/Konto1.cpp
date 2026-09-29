#include <iostream>
#include "Konto1.h"
#include <string>
using namespace std;


Konto::Konto(int nr, string nn, double sld, double proc)
    :numer{nr}, nazwa{nn}, saldo{sld}, oprocentowanie{proc}
{}

Konto::~Konto()
{
    cout<<"Destruktor konta nr: "<<this->numer<<endl;
}


double Konto::wplac(double kwota)
{
    this->saldo=this->saldo+kwota;
    return this->saldo;
}

double Konto::wyplac(double kwota)
{
    if(kwota>saldo) cout<<"Stan konta wynosi "<< this->saldo <<"\nStan konta jest zbyt niski. Nie mozna wyplacic podanej kwoty."<<endl;
    else this->saldo=this->saldo-kwota;
    return this->saldo;
}

double Konto::dolicz_odsetki()
{

    this->saldo=this->saldo+(this->saldo*this->oprocentowanie);

    return this->saldo;
}

void wyswietl(const Konto& k)
{
    cout<<"Klient: "<<k.nazwa<<"\tnr konta: "<<k.numer<<"\tstan konta: "<<k.saldo<<" PLN\toprocentowanie: "<<k.oprocentowanie*100<<"%"<<endl;
}

std::ostream& operator<<(std::ostream& o, const Konto& k)
{
    o<<"Klient: "<<k.nazwa<<"\tnr konta: "<<k.numer<<"\tstan konta: "<<k.saldo<<" PLN\toprocentowanie: "<<k.oprocentowanie*100<<"%"<<endl;
    return o;
}

