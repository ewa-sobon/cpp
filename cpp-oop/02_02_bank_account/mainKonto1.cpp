#include <iostream>
#include <iomanip>
#include "Konto1.h"
#include <string>
using namespace std;

int main()
{
    cout<<fixed<<setprecision(2);

    Konto k1(11111, "Adam Nowak", 100, 0.03);
    Konto k2(11112, "Piotr Kowalski", 1000);
    Konto k3(11113, "Patryk Janusz", 465.34, 0.045);

    wyswietl(k1);
    wyswietl(k2);
    wyswietl(k3);

    double kwota=0;
    int odp=-1;

    do
    {
        cout<<"Co chcesz zrobic? Wplata - wybierz 1, Wyplata - wybierz 2, Zakoncz - wybierz 3"<<endl;

        do
        {
            cin>>odp;
            if((odp!=3 && odp!=1 && odp != 2) || cin.fail())
            {
                cout<<"Wprowadz poprawne dane"<<endl<<"Wplata - wybierz 1, Wyplata - wybierz 2, Zakoncz - wybierz 3"<<endl;

                cin.clear();
                cin.ignore(10000, '\n');
                odp=-1;
            }
        }
        while((odp!=3 && odp!=1 && odp != 2) ||  cin.fail());

        if(odp==1)
        {
            cout<<"Podaj kwote wplaty. Maksymalna wplata to 10 000"<<endl;
            do
            {
                cin>>kwota;

                if(kwota < 1 || kwota > 10000 || cin.fail())
                {
                    cout<<"Wprowadz poprawna kwote"<<endl;

                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }

            }
            while(kwota < 1 || kwota > 10000 || cin.fail());
            k1.wplac(kwota);
        }

        if(odp==2)
        {
            cout<<"Podaj kwote wyplaty"<<endl;
            do
            {
                cin>>kwota;

                if(kwota < 1 || cin.fail())
                {
                    cout<<"Wprowadz poprawna kwote"<<endl;

                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }

            }
            while(kwota < 1 || cin.fail());

            k1.wyplac(kwota);
        }
    }
    while(odp!=3);

    cout<<"\nPO WPLACIE/WYPLACIE STAN KONTA"<<endl;
    wyswietl(k1);

    int odp1 = -1;

    cout<<"\nCZY DOLICZYC ODSETKI? TAK - wybierz 1 / NIE - wybierz 0"<<endl;

    do
    {
        cin>>odp1;
        if((odp1!=1 && odp1!=0) || cin.fail())
        {
            cout<<"Wprowadz poprawne dane"<<endl<<"TAK - wybierz 1 / NIE - wybierz 0"<<endl;

            cin.clear();
            cin.ignore(10000, '\n');
            odp1 = -1;
        }
    }
    while((odp1!=1 && odp1!=0) || cin.fail());

    if(odp1 == 1)
    {
        cout<<"\nStan konta poczatkowy "<<endl;
        wyswietl(k1);
        k1.dolicz_odsetki();
        cout<<"\nStan konta po doliczeniu odsetek "<<endl;
        wyswietl(k1);
        cout<<endl;
    }
    else
    {
        cout<<"\nOdsetki nie zostaly doliczone. "<<endl;
    }


    cout<<"\nWYPISANIE KLIENTOW za pomoca operatora<<"<<endl;
    cout<<k1<<k2<<k3;

    cout<<"\nKONIEC PROGRAMU - AUTOMATYCZNE USUWANIE OBIEKTOW"<<endl;
    return 0;
}

