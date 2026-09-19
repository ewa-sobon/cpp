#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n;
    srand(time(NULL));

    cout<<"Program losuje liczby z przedzialu [-5, 5]"<<endl;

    do
    {
        cout<<"\nIle liczb wylosowac? (Dopuszczalny zakres [1 - 1000])"<<endl;
        cin>>n;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            n=0;  //ustawiam n poza zakresem, zeby petla sie wykonala jeszcze raz
        }

    }
    while(n<1 || n>1000);

    int *tab = new int[n];

    int powtorzenia[11]= {}; // tyle unikalnych wartosci mozemy otrzymac, tablica powtorzen nie bedzie wieksza

    int licznik = 0;

    cout<<endl;
    for(int i=0; i<n; i++)
    {
        tab[i]=rand()%11 -5;
        cout<<tab[i]<<'\t';
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(tab[i]==tab[j])
            {
                bool istnieje=false;
                for(int k=0; k<licznik; k++)
                {
                    if(powtorzenia[k]==tab[i])
                    {
                        istnieje=true;
                        break;
                    }
                }

                if(!istnieje)
                {
                    powtorzenia[licznik]=tab[i];
                    licznik++;
                }
            }
        }
    }


    if(licznik > 0)
    {
        cout<<"\nW TABLICY WYSTEPUJA POWTARZAJACE SIE WARTOSCI: \n{ ";
        for(int i=0; i<licznik; i++)
        {
            cout<<powtorzenia[i]<<"  ";
        }
        cout<<"}"<<endl;
    }

    else
    {
        cout<<endl<<"\nW tablicy nie wystepuja powtarzajace sie wartosci."<<endl;
    }

    delete[] tab;
    tab=nullptr;

    return 0;
}
