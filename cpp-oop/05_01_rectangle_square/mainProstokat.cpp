#include <iostream>
#include "Prostokat.h"

using namespace std;

int main()
{
    cout <<"\n[TEST 1]" <<endl;
    cout <<"\n[OBIEKT 1] - SPRAWDZAM ZACHOWANIE KONSTRUKTORA dwuargumentowego "<< endl;

    const Prostokat p1{3,4};
    cout <<"\nObiekt zostal stworzony ale wartosci pol obwod i pole nie sa wyliczane w momencie tworzenia obiektu "<< endl <<"WYPISUJE WARTOSCI PRZEZ GETTERY (stworzone sztucznie na potrzebe tego testu):"<<endl;
    cout <<"pole prostokata: "<< p1.get_pole_wartosc() <<"\tobwod prostokata: "<< p1.get_obwod_wartosc()<< endl; // pobrane z pola pole_wartosc

    cout <<"\nWYPISUJE WARTOSCI PRZEZ WLASCIWE METODY DOSTEPU DO POL KLASY PROSTOKAT" <<endl<< "(metody wyliczaja wartosci jesli flaga zmiennej sprawdzajacej jest false): "<< endl;
    cout << p1.pole() <<"\t"<<p1.obwod()<< endl;                                                                // wyliczane w metodzie przy probie dostepu do pol

    p1.wypisz();

    cout<<endl;
    cout <<"\n[TEST 2]" <<endl;
    cout <<"\n[OBIEKT DOMYSLNY Prostokat] SPRAWDZAM ZACHOWANIE KONSTRUKTORA domyslnego"<< endl;

    Prostokat p_bezarg;  //UWAGA! - nie moze byc obiektem const, bo wtedy nie jest mozliwe ustawienie wartosci bokow

    cout <<"\nWYPISUJE WARTOSCI PRZEZ WLASCIWE METODY DOSTEPU DO POL KLASY PROSTOKAT" <<endl;
    cout << p_bezarg.pole()<<"\t"<<p_bezarg.obwod()<< endl;
    p_bezarg.wypisz();

    cout <<"\nZMIENIAM WARTOSCI BOKOW" <<endl;
    p_bezarg.zmien_bok(5, 6);
    cout <<"pole prostokata po zmianie: "<< p_bezarg.pole() <<"\tobwod prostokata: "<< p_bezarg.obwod()<< endl;
    p_bezarg.wypisz();

    cout<<endl;
    cout <<"\n[TEST 3]" <<endl;
    cout <<"\nSPRAWDZAM ZACHOWANIE PODKLASY KWADRAT "<< endl;

    cout <<"\n[OBIEKT Kwadrat] SPRAWDZAM ZACHOWANIE KONSTRUKTORA obiektu Kwadrat"<< endl;
    Kwadrat k1(6);

    cout <<"\nWYPISUJE WARTOSCI PRZEZ WLASCIWE METODY DOSTEPU DO POL KLASY odziedziczonych z klasy Prostokat" <<endl;
    cout <<"pole kwadratu: "<< k1.pole()<<"\tobwod kwadratu: "<< k1.obwod()<<endl;
    k1.wypisz();
    cout <<"\nZMIENIAM WARTOSCI BOKU" <<endl;
    k1.zmien_bok(7);
    cout<<"\nZmiana boku";
    k1.wypisz();
    k1.Prostokat::wypisz();

    cout<<endl;
    cout <<"\n[TEST 4]" <<endl;
    cout <<"\n[OBIEKT Kwadrat domyslny] SPRAWDZAM ZACHOWANIE KONSTRUKTORA domyslnego obiektu Kwadrat"<< endl;
    Kwadrat domyslny;
    domyslny.wypisz();
    domyslny.Prostokat::wypisz();

    cout<<endl;
    cout <<"\nKONIEC PROGRAMU (sprawdzam wywolywanie automatyczne destruktorow)"<< endl<<endl;

    return 0;
}
