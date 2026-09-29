#include <iostream>
#include "MacierzN.h"
#include <iomanip>
using namespace std;  // wiem ze dzieki temu nie musze pisac std::. Pisze mimo to ¿eby utrwaliæ sk³adnie ogóln¹


MacierzN::MacierzN(int nn)
    :n{nn}
{
    tablica = new int [n*n];

    for(int i=0; i<n*n; i++)
        tablica[i] = 0;
}

MacierzN::MacierzN(const MacierzN& wzor)
    :n{wzor.n}
{
    tablica = new int [n*n];
    for(int i=0; i<n*n; i++)
        tablica[i] = wzor.tablica[i];
}


MacierzN::~MacierzN()
{
    delete[] tablica;
    cout << "destruktor zwalnia pamiec przydzielona dynamicznie dla tablicy" << endl;
}


std::ostream& operator<<(std::ostream& o, const MacierzN& m)
{
    for(int i=0; i<m.n; i++)
    {
        o<<"[";
        for(int j=0; j<m.n; j++)
        {
            o<< setw(6)<<m.tablica[i*m.n+j]<< "\t";
        }
        o<< "]"<<endl;
    }
    return o;
}

std::istream& operator>>(std::istream& ci, MacierzN& m)
{

    int element;
    for(int i=0; i<m.n; i++)
    {
        for(int j=0; j<m.n; j++)
        {

            cout<<"Podaj element [" << i << "][" << j << "]" <<endl;
            ci>>element;
            if(ci.fail())
            {
                ci.clear();
                ci.ignore(10000, '\n');
                element = 44;
            }

            m.tablica[i*m.n+j]=element;

        }
    }

    return ci;

}

MacierzN& MacierzN::operator=(const MacierzN& mWzor)
{
    if(this!=&mWzor)

    {
        if(n!=mWzor.n)
        {
            delete[] tablica;
            n=mWzor.n;
            tablica = new int [n*n];
        }
        {
            for(int i=0; i<mWzor.n; i++)
            {
                for(int j=0; j<mWzor.n; j++)
                {
                    tablica[i*n+j]=mWzor.tablica[i*n+j];
                }
            }
        }
    }
    return *this;
}


MacierzN operator+(const MacierzN& ml, const MacierzN& mp)
{


    MacierzN wynik(ml.n);

    if(ml.n!=mp.n)
    {
        cout<<"Nie da sie dodac macierzy, tworze pusta macierz";
        return wynik;
    };

    for(int i=0; i<ml.n; i++)
    {
        for(int j=0; j<ml.n; j++)
        {
            wynik.tablica[i*ml.n+j]=ml.tablica[i*ml.n+j]+mp.tablica[i*ml.n+j];
        }
    }

    return wynik;
}


MacierzN operator-(const MacierzN& ml, const MacierzN& mp)
{
    MacierzN wynik(ml.n);

    if(ml.n!=mp.n)
    {
        cout<<"Nie da sie odjac macierzy, tworze pusta macierz";
        return wynik;
    };

    for(int i=0; i<ml.n; i++)
    {
        for(int j=0; j<ml.n; j++)
        {
            wynik.tablica[i*ml.n+j]=ml.tablica[i*ml.n+j]-mp.tablica[i*ml.n+j];
        }
    }
    return wynik;
}

MacierzN operator*(const MacierzN& ml, int liczbaP)
{
    MacierzN wynik(ml.n);
    for(int i=0; i<ml.n; i++)
    {
        for(int j=0; j<ml.n; j++)
        {
            wynik.tablica[i*ml.n+j]=ml.tablica[i*ml.n+j]*liczbaP;
        }
    }

    return wynik;
}

