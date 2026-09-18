#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    srand(time(NULL));
    cout<<fixed<<setprecision(2);

    // Utworzenie tablicy 300-elementowej przechowujacej liczby rzeczywiste, tablica wyzerowana przez ={}
    const int M=300;
    double tab[M]= {};

    // Alternatywny sposób zerowania tablicy
    /* for(int i=0; i<M; i++)
     {
         tab[i]=0;
     } */

    int n, mniejsze=0;

    cout<<"Program losuje liczby rzeczywiste z zakresu [0-20]."<<endl<<"Ile liczb wylosowac? [1-300]"<<endl;
    cin>>n;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"\nWprowadziles bledne dane. Zostanie wylosowanych 300 liczb."<<endl;
        n=300;
    }

    if(n<1 || n>300)
    {
        cout<<"\nWybrales liczbe poza zakresem tablicy. Zostanie wylosowanych 300 liczb."<<endl;
        n=300;
    }

    cout<<endl;
    // pomocnicza zmienna int do przekonwertowania na double
    int liczba;

    // uzupelnienie tablicy pseudolosowymi liczbami rzeczywistymi z przedzialu [0 - 20]
    for(int i=0; i<n; i++)
    {
        liczba = rand()%2100;
        double liczbaDouble = (double)liczba/100;
        tab[i]=liczbaDouble;
        cout<<tab[i]<<"\t";
    }

    // porownanie elementow tablicy z ostatnim elementem tablicy i wypisanie ile jest mniejszych
    for(int i=0; i<n-1; i++)
    {
        if(tab[i]<tab[n-1])
            mniejsze++;
    }

    cout<<"\nLiczb mniejszych od ostatniego elementu ( "<< tab[n-1] <<" ) jest: "<<mniejsze<<endl;

    return 0;
}
