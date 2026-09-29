#include <iostream>
#include <iomanip>
#include "Patient.h"

using namespace std;

int main()
{
    cout<<"\nTworze obiekt PACJENT A"<<endl;
    Pacjent A(111110, 1.72, 55.5);
    wyswietl(A);

    cout<<"\nTworze obiekt PACJENT B"<<endl;
    Pacjent B(111111, 1.65, 51.5);
    wyswietl(B);

    cout<<"\nTworze obiekt PACJENT C przez konstruktor kopiujacy z PACJENT B"<<endl;
    Pacjent C=B;
    wyswietl(C);

    cout<<"\nZmieniam PACJENT A przez settery"<<endl;
    A.ustaw_wzrost(1.7);
    A.ustaw_wage(58);
    wyswietl(A);

    cout<<"\nZAPISANI PACJENCI - wypisane przy pomocy operator<<"<<endl;
    cout<<B<<A<<C;


    cout<<"\nTWORZE TABLICE PACJENTOW"<<endl;
    Pacjent* tab[3]= {new Pacjent{1, 1.65, 50.5},
                 new Pacjent{2, 1.75, 60.5},
                 new Pacjent{3, 1.85, 80.5}
    };

    wyswietl(tab, 3);


    cout<<"\nSrednia waga pacjentow z tablicy: ";
    cout<<setprecision(1)<<fixed<< sr_waga(tab, 3)<<" kg";
    cout<<endl;

    cout<<"\nZWALNIAM PAMIEC PRZYDZIELONA DYNAMICZNIE"<<endl;

    for(int i=0; i<3; i++)
    {
        delete tab[i];
        tab[i]=nullptr;
    }

    cout<<"\nKONIEC PROGRAMU - AUTOMATYCZNE USUWANIE OBIEKTOW A, B I C"<<endl;

    return 0;
}
