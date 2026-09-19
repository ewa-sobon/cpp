#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


void wczytaj(int *tab, int n)
{
    srand(time(NULL));

    for(int i=0; i<n; i++)
    {
        tab[i]=rand()%501 - 250;
    }
}

void wypisz(int *tab, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<tab[i]<<'\t';
    }
}

int ileParzystych(int *tab, int n)
{
    int parzyste =0;

    for(int i=0; i<n; i++)
    {
        if(tab[i]%2==0)
            parzyste++;
    }
    return parzyste;
}

int szukaj(int*tab,int n,int a)
{
    for(int i=0; i<n; i++)
    {
        if(tab[i]==a) return i;
    }
    return -1;
}

int maxWartosc(int*tab, int n)
{
    int max = tab[0];
    for(int i=1; i<n; i++)
    {
        if(tab[i]>max)
        {
            max=tab[i];
        }
    }
    return max;
}

int maxIndeks(int*tab, int n)
{
    int max = tab[0];
    int maxI = 0;
    for(int i=1; i<n; i++)
    {
        if(tab[i]>max)
        {
            max=tab[i];
            maxI = i;
        }
    }
    return maxI;
}

int sumaParzystych(int* tab, int n)
{

    int suma=0;

    for(int i=0; i<n; i++)
    {
        if(tab[i]%2==0)
        {
            suma=suma+tab[i];
        }
    }
    return suma;
}

double sredniaParzystych(int* tab, int n)
{
    return (double)sumaParzystych(tab, n)/ileParzystych(tab, n);
}

void sortuj(int*tab, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(tab[j]>tab[j+1])
            {
                int temp = tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}


int main()
{
    int n;
    do
    {
        cout<<"Podaj liczbe elementow tablicy: dopuszczalny zakres [1 - 400] "<<endl;
        cin>>n;

        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            n=0;
        }
    }
    while(n<1 || n>400);

    int*tab = new int[n];

    wczytaj(tab, n);

    cout<<"\nWYPISANA TABLICA"<<endl;
    wypisz(tab, n);

    int iloscParzystych = ileParzystych(tab, n);
    cout<<endl<<"\nParzystych jest: "<<iloscParzystych<<endl;

    int a;

    cout<<"\nJakiej liczby szukasz? ";
    cin>>a;

    int indeksSzukaj = szukaj(tab, n, a);

    if(indeksSzukaj == -1)
    {
        cout<<"\nLiczba " <<a<<" nie wystepuje w tablicy"<<endl;
    }
    else cout<<"\nLiczba "<<a<<" znajduje sie w tablicy na pozycji tab["<<indeksSzukaj<<"]"<<endl;

    cout<<"\nWartosc maksymalna w tablicy to "<<maxWartosc(tab, n)<<". Znajduje sie na indeksie "<<maxIndeks(tab, n)<<"."<<endl;

    if(iloscParzystych)
    {cout<<"\nSuma parzystych elementow to: "<<sumaParzystych(tab, n)<<". Ich srednia arytmetyczna to: "<<sredniaParzystych(tab, n)<<"."<<endl;}

    sortuj(tab, n);

    cout<<"\nPOSORTOWANA TABLICA"<<endl;
    wypisz(tab,n);

    cout<<endl;

    delete[] tab;
    tab=nullptr;

    return 0;
}
