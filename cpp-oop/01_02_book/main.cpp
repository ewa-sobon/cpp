#include <iostream>
#include <string>
#include "Ksiazka.h"

using namespace std;

int main()
{
    cout<< "\n          TESTOWANIE KLASY: KSIAZKA          "<< endl;
    cout<< "============================================="<< endl;

    cout<<"\n[TEST 1] Ksiazka A - domyslna (konstruktor domyslny):"<<endl;
    Ksiazka A;
    A.wypisz();

    cout<<"\n[TEST 2] Ksiazka B - z paramatrami (konstruktor z przekazanymi parametrami):"<<endl;
    Ksiazka B("Nowy wspanialy swiat", "Aldous Huxley", 1931);
    B.wypisz();

    cout<<"\n[TEST 3] Modyfikacja Ksiazka A - za pomoca setterow: "<<endl;
    A.set_autor("Charles Duhigg");
    A.set_tytul("Sila nawyku");
    A.set_rok(2012);
    A.wypisz();
    cout<<"\n---------------------------------------------"<<endl;
    cout<<"Zmiana dostepnosci:"<<endl;
    A.set_czy_dostepna(false);
    A.wypisz();

    cout<<"\n[TEST 4] Testowanie pojedynczych getterow (dla Ksiazka B):"<<endl;
    cout<<"Tytul (get): "<<B.get_tytul()<<endl;
    cout<<"Autor (get): "<<B.get_autor()<<endl;
    cout<<"Rok wydania (get): "<<B.get_rok()<<endl;
    cout<<"Dostepnosc (get): ";
    if(B.get_czy_dostepna())
    {
        cout<<"TAK"<<endl;
    }
    else
    {
        cout<<"NIE"<<endl;
    }
    cout<<endl;
    return 0;
}
