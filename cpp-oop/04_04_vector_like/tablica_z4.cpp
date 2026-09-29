#include "tablica_z4.h"

Tablica::Tablica(int _rozmiar)
    :rozmiar(_rozmiar>0?_rozmiar:0),tab(rozmiar>0?new int[rozmiar] {}:nullptr)
{ }

Tablica::~Tablica()
{
    delete[] tab;
}

Tablica::Tablica(const Tablica& wzor)
    :rozmiar(wzor.rozmiar>0?wzor.rozmiar:0),tab(rozmiar>0?new int[rozmiar] {}:nullptr),n(rozmiar>0?wzor.n:0)
{
    if(wzor.tab != nullptr)
    {
        for(int i=0; i<n; ++i)
            tab[i]=wzor.tab[i];
    }
}

Tablica& Tablica::operator=(const Tablica& prawy)
{
    if(this==&prawy)
        return *this;
    n=prawy.n;
    rozmiar=prawy.rozmiar;
    delete[] tab;

    if(prawy.tab==nullptr) tab=nullptr;
    else
    {
        tab=new int[rozmiar];
        for(int i=0; i<n; i++)
            tab[i]=prawy.tab[i];
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o,const Tablica& t)
{
    o<<"{";
    for(int i=0; i<t.n; ++i)
    {
        o<<t.tab[i];
        if(i!=t.n-1)
            o<<",";
    }
    o<<"}";
    return o;
}

int& Tablica::operator[](unsigned ind)
{
    return tab[ind];
}

void Tablica::wstaw_koniec(const int& wartosc)
{
    if (czypelna())
    {
        powieksz();
    }

    tab[n++]=wartosc;

}

void Tablica::wstaw_poczatek(const int& wartosc)
{
    if (czypelna())
    {
        powieksz();
    }
        for(int i=n-1; i>0; i--)
    {
        tab[i]=tab[i-1];
    }
    tab[0]=wartosc;
    n++;
}

bool Tablica::usun_koniec(int& wartosc)
{
    if (n>0)
    {
        wartosc=tab[--n];
        return true;
    }
    return false;
}

bool Tablica::usun_poczatek()
{
    if (n>0)
    {
        for(int i=0; i<n-1; i++)
        {
            tab[i]=tab[i+1];
        }

        n--;
        return true;
    }
    return false;
}

bool Tablica::czypelna()
{
    return n==rozmiar;
}

bool Tablica::czypusta()
{
    return n==0;
}

bool Tablica::czyistnieje()
{
    return tab!=nullptr;
}

void Tablica::usun_wszystkie_elementy()
{
    n=0;
}

int Tablica::liczba_elementow()const
{
    return n;
}

int Tablica::pierwszy_element()const
{
    return tab[0];
}

int Tablica::ostatni_element()const
{
    return tab[n-1];
}

int Tablica::rozmiar_tablicy()const
{
    return rozmiar;
}

void Tablica::zamien(Tablica& t)
{
    if(this!=&t)
    {
        Tablica temp(*this);

        *this=t;
        t=temp;
    }
}

void Tablica::powieksz()
{
    if(tab == nullptr)       // ewentualnie if(!czyistnieje())
    {
        rozmiar=4;
        tab= new int[4] {};
        std::cout<<"\nTablica nie istniala. Stworzono tablice o rozmiarze 4."<<std::endl;
    }
    else
    {
        Tablica temp(rozmiar*2);
        std::cout<<"\nTablica zostala powiekszona * 2"<<std::endl;
        for(int i=0; i<n; i++)
        {
            temp.wstaw_koniec(tab[i]);
        }
        (*this).zamien(temp);
    }
}

void Tablica::ustaw_rozmiar(int nr)
{
    if(nr < n){
        nr=n;
    }

    Tablica temp(nr);

    for(int i=0; i<n; i++)
    {
        temp.wstaw_koniec(tab[i]);
    }

    (*this).zamien(temp);
}

void Tablica::ustaw_liczbe_elementow(int nn)
{
    if(nn<=n)
        n=nn;

    else
    {
        if(nn>rozmiar)
        {
            ustaw_rozmiar(nn);
        }
        for(int i=n; i<nn; i++)
        {
            wstaw_koniec({});
        }
    }
}

Tablica Tablica::polacz(const Tablica& prawa)const
{
    if(this==&prawa) return *this;

    Tablica t3(n+prawa.n);

    for(int i=0; i<n; i++)
    {
        t3.wstaw_koniec(tab[i]);
    }
    for(int i=0; i<prawa.n; i++)
    {
        t3.wstaw_koniec(prawa.tab[i]);
    }

    return t3;
}
