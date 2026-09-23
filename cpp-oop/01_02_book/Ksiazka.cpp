#include <iostream>
#include <string>
#include "Ksiazka.h"

using namespace std;

Ksiazka::Ksiazka(string t, string a, int r)
    :tytul(t), autor(a), rok(r)
{}

Ksiazka::~Ksiazka() {}

void Ksiazka::wypisz()const
{
    cout <<"\nTytul: "<<this->tytul
         <<"\nAutor: "<<this->autor
         <<"\nRok wydania: "<<this->rok
         <<"\nDostepnosc: ";
    if(this->czy_dostepna) cout<<"dostepna"<<endl;
    else cout<<"niedostepna"<<endl;
}

string Ksiazka::get_tytul()const
{
    return this->tytul;
}

string Ksiazka::get_autor()const
{
    return this->autor;
}

int Ksiazka::get_rok()const
{
    return this->rok;
}

bool Ksiazka::get_czy_dostepna()const
{
    return this->czy_dostepna;
}


void Ksiazka::set_tytul(string t)
{
    this->tytul=t;
}

void Ksiazka::set_autor(string a)
{
    this->autor = a;
}

void Ksiazka::set_rok(int r)
{
    this->rok =r;
}

void Ksiazka::set_czy_dostepna(bool dostepnosc)
{
    this->czy_dostepna=dostepnosc;
}



