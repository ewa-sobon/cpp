#include <iostream>
#include <ctime>

#include "Data.h"
using namespace std;

int main()
{
    cout<<"\n[DATA 1] INICJOWANIE DATY KONSTRUKTOR DOMYSLNY"<<endl;
    Data d1;
    d1.wyswietl();
    cout<<endl;

    cout<<"\n[DATA 2] INICJOWANIE DATY KONSTRUKTOR Z ARGUMENTAMI"<<endl;
    Data d2(1, 4, 2026);
    d2.wyswietl();
    cout<<endl;

    cout<<"\nZmiana parametrow DATA 2 za pomoca SETTEROW."<<endl;
    d2.set_dzien(3);
    d2.set_miesiac(6);
    d2.set_rok(1987);

    cout<<"\nWYSWIETLENIE DAT PO ZMIANACH:"<<endl
        <<"[DATA 1] - bez zmian: ";
    d1.wyswietl();
    cout<<endl;

    cout<<"[DATA 2] - zmieniona: ";
    d2.wyswietl();
    cout<<endl;

    cout<<"\nPOROWNANIE DAT. Data podana w argumencie to data 2"<<endl;
    if(d1.czy_rowne(d2))
    {
        cout <<"Daty sa takie same"<<endl;
    }

    else
    {
        if(d1.czy_pozniejsza(d2))
        {
            cout<<"Data ";
            d1.wyswietl();
            cout<<" jest pozniejsza od daty ";
            d2.wyswietl();
            cout<<endl;
        }
        else
        {
            cout<<"Data ";
            d1.wyswietl();
            cout<<" jest wczesniejsza od daty ";
            d2.wyswietl();
            cout<<endl;
        }
    }

    cout<<"\n[DATA 3] POROWNUJE TAKIE SAME DATY"<<endl;
    Data d3(8, 3, 2026);

    if(d1.czy_rowne(d3))
    {
        cout <<"Daty sa takie same."<<endl;
    }

    else
    {
        if(d1.czy_pozniejsza(d3)) cout<<"Data pierwsza jest pozniejsza od drugiej."<<endl;
        else cout<< "Data pierwsza jest wczesniejsza od drugiej."<<endl;
    }

    string odmiana_miesiecy[12]= {"stycznia", "lutego", "marca", "kwietnia", "maja", "czerwca", "lipca", "sierpnia", "wrzesnia", "pazdziernika", "listopada", "grudnia"};

    cout<<"\n[DATA 4] INICJOWANIE OBIEKTU DATA Z DZISIEJDZEJ DATY"<<endl;

    time_t treaz = time(nullptr);
    tm* data = localtime(&treaz);

    Data dzisiaj(data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    cout<<"Testujesz ten program dnia "<<dzisiaj.get_dzien()<<". "<<odmiana_miesiecy[dzisiaj.get_miesiac() -1]<<" "<<dzisiaj.get_rok()<<" roku."<<endl;
    cout<<"Napisalam go dnia "<<d1.get_dzien()<<". "<<odmiana_miesiecy[d1.get_miesiac() - 1]<<" "<<d1.get_rok()<<" roku."<<endl;

    return 0;
}


