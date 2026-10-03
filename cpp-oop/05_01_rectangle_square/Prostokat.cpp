#include <iostream>
#include "Prostokat.h"

using namespace std;

Prostokat::Prostokat(double a, double b)
    : bok1{a}, bok2{b}, pole_wartosc{0}, pole_obliczone{false}, obwod_wartosc{0}, obwod_obliczone{false}
{
    cout<<"Konstruktor Prostokat"<<endl;
}

Prostokat::~Prostokat()
{
    cout<<"Destruktor Prostokat"<<endl;
}

double Prostokat::pole() const
{
    if (!pole_obliczone)
    {
        pole_wartosc = bok1 * bok2;
        pole_obliczone = true;
    }
    return pole_wartosc;
}

double Prostokat::obwod() const
{
    if (!obwod_obliczone)
    {
        obwod_wartosc = 2 * bok1 + 2 * bok2;
        obwod_obliczone = true;
    }
    return obwod_wartosc;
}

void Prostokat::zmien_bok(double a, double b)
{
    bok1=a;
    bok2=b;

    if (pole_obliczone)     // jesli nie jest wyliczone to nie ruszam, jesli jest wyliczone to aktualizuje
    {
        pole_wartosc = bok1 * bok2;
    }

    if (obwod_obliczone)         // jesli nie jest wyliczone to nie ruszam, jesli jest wyliczone to aktualizuje
    {
        obwod_wartosc = 2 * bok1 + 2 * bok2;

    }
}

void Prostokat::wypisz()const
{
    cout <<"\nWYPISYWANIE METODA PROSTOKAT"<< endl;
    cout <<"bok: "<<bok1;
    cout <<",\tbok: "<<bok2;
    cout<<",\tpole: "<< pole() <<",\tobwod: "<< obwod() << endl;
}

   double Prostokat::get_pole_wartosc() const{
    return pole_wartosc;
    }

    double Prostokat::get_obwod_wartosc() const{
    return obwod_wartosc;
    }

Kwadrat::Kwadrat()
    :Prostokat()
{
    cout<<"Konstruktor bezargumentowy Kwadrat"<<endl;
}

Kwadrat::Kwadrat(double a)
    :Prostokat(a,a)
{
    cout<<"Konstruktor Kwadrat"<<endl;
}


Kwadrat::~Kwadrat()
{
    cout<<"Destrktor Kwadrat"<<endl;
}

void Kwadrat::wypisz()const
{
    cout <<"\nWYPISYWANIE METODA KWADRAT"<< endl;
    cout <<"bok: "<<bok1<<",\tpole: "<< pole() <<",\tobwod: "<< obwod() << endl;
}

void Kwadrat::zmien_bok(double a)
{
    Prostokat::zmien_bok(a,a);
}
