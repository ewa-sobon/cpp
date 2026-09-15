#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main()
{
    srand(time(NULL));
    const int M =20;
    int tab[M];

    cout<<"TABLICA Z WYLOSOWANYMI WARTOSCIAMI: "<<endl;

    for(int i=0; i<M; i++)
    {
        tab[i] = rand()%1000 + (-500);
        cout<<tab[i]<<'\t';
    }

// sortowanie tablicy

    bool posortowane = true;  // zmienna pomocnicza do sprawdzenia czy tablica jest juz posortowana

    for(int i=0; i<M-1; ++i)
    {

        posortowane = true;

        for(int j=0; j<M-i-1; j++)
        {
            if(tab[j]>tab[j+1])
            {
                int temp = tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
                posortowane = false;

            }
        }

        if(posortowane)
        {
            break;  //jesli tablica jest posortowana program nie sprawdza kolejnych pozycji
        }
    }

    cout<<endl<<"POSORTOWANA TABLICA"<<endl;

    for(int i=0; i<M; i++)
    {
        cout<<tab[i]<<'\t';
    }


    return 0;

}
