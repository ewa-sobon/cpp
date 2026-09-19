#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    int n, nP=0;

    do
    {
        cout<<"Podaj ilosc elementow tablicy [ilosc > 0 i ilosc < 1000]: ";
        cin>>n;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            n=0;
        }

    }
    while(n < 1 || n > 999);

    int*tab = new int[n];

    cout<<"\nTablica glowna"<<endl;
    for(int i=0; i<n; i++)
    {
        tab[i]=rand()%1000 + 1;
        cout<<tab[i]<<'\t';
        if(tab[i]%2==0)
        {
            nP++;
        }
    }

    cout<<endl;

    cout<<"\nTablica parzystych"<<endl;
    int*tabP = new int[nP];
    int j=0;

    for(int i=0; i<n; i++)
    {

        if(tab[i]%2==0)
        {
            tabP[j]=tab[i];
            cout<<tabP[j]<<'\t';
            j++;
        }
    }

    cout<<endl;

    delete[] tab;
    tab = nullptr;
    delete[] tabP;
    tabP = nullptr;

    return 0;
}
