#include <iostream>
#include <iomanip>
#include "MacierzN.h"

using namespace std;

int main()
{
    int n=0;
    do
    {
        cout<<"Podaj wymiar n macierzy kwadratowej. [n>1]"<<endl;
        cout<<"Wprowadzam ograniczenie wielkosci macierzy. [n<5]"<<endl;
        cin>>n;
        if(n<2 || n>4) cout<<"\nPodany wymiar jest nieprawidlowy"<<endl;

    }
    while(n<2 || n > 4);


    cout<<"\nTWORZE MACIERZ [M1] Z WYZEROWANYMI WARTOSCIAMI POL"<<endl;
    MacierzN m1(n);
    cout<<m1;

    cout<<"\nTWORZE MACIERZ [M2] PRZEZ KONSTRUKTOR KOPIUJACY"<<endl;
    MacierzN m2(m1);
    cout<<m2;

    cout<<"\nPodaj wartosci pol macierzy [M1] (przeciezenie operatora>>): "<<endl;
    cout<<"Jesli wprowadzisz bledne dane, dla pola przypisana zostanie wartosc [44]"<<endl;
    cin>>m1;
    cout<<"\nWYPISANIE MACIERZY [M1]"<<endl;
    cout<<m1;

    m2=m1;

    cout<<"\nPRZECIAZENIE OPERATORA= (m2=m1): "<<endl
        <<"WYPISANIE MACIERZY"<<endl<<m1<<endl<<m2;

    cout<<"\nPodaj nowe wartosci pol macierzy 2: "<<endl;
    cout<<"Jesli wprowadzisz bledne dane, dla pola przypisana zostanie wartosc [44]"<<endl;
    cin>>m2;

    int liczba;

    cout<<"Podaj liczbe calkowita przez ktora chcesz pomnozyc macierz [M1]: " << endl;
    cout<<"Jesli wprowadzisz bledne dane, macierz zostanie pomnozona przez [10]" << endl;
    cin>>liczba;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        liczba = 10;
    }

    cout<<"Macierz [M1]: "<<endl
        <<m1<<"\nMacierz [M2]"<<endl
        <<m2<<"\nSuma macierzy"<<endl<<m1+m2<<endl
        <<"Roznica macierzy: "<<endl<<m1-m2<<endl
        <<"Iloczyn macierzy [M1] i liczby "<<liczba<<endl<<m1*liczba<<endl;
    return 0;
}

