#include <iostream>
#include "Data.h"
using namespace std;


Data::Data(int d, int m, int r)
    :dzien{d}, miesiac{m}, rok{r}
{}

int Data::get_dzien()const
{
    return dzien;
}

int Data::get_miesiac()const
{
    return miesiac;
}

int Data::get_rok()const
{
    return rok;
}

void Data::set_dzien(int d)
{
    dzien=d;
}

void Data::set_miesiac(int m)
{
    miesiac=m;
}

void Data::set_rok(int r)
{
    rok=r;
}

void Data::wyswietl()const
{
    if(dzien<10)
    {
        cout<<"0"<<dzien;
    }
    else
    {
        cout<<dzien;
    }
    cout<<".";
    if(miesiac<10)
    {
        cout<<"0"<<miesiac;
    }
    else
    {
        cout<<miesiac;
    }
    cout<<"."<<rok;

}

bool Data::czy_rowne(const Data& d)const
{
    return(dzien==d.dzien && miesiac==d.miesiac && rok==d.rok);
}

bool Data::czy_pozniejsza(const Data& d)const
{
    if(this->rok < d.rok) return false;
    if(this->rok > d.rok) return true;

    if(this->miesiac < d.miesiac) return false;
    if(this->miesiac > d.miesiac) return true;

    return this->dzien > d.dzien;
}


