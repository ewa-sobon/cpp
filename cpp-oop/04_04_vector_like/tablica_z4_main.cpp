#include <iostream>
#include "tablica_z4.h"
using namespace std;


int main()
{
    cout<<"\n[TEST 1] - testy konstruktorow"<<endl;

    cout<<"\nTWORZE KONSTRUKTOREM DOMYSLNYM I WYPISUJE TABLICE [t]"<<endl;
    Tablica t;
    cout<<"t = "<<t<<"; - rozmiar tablicy: "<<t.rozmiar_tablicy()<<endl;

    cout<<"\nTWORZE KONSTRUKTOREM z parametrem I WYPISUJE TABLICE [t1]"<<endl;
    Tablica t1(4);
    cout<<"t1 = "<<t1<<"; - rozmiar tablicy: "<<t1.rozmiar_tablicy()<<endl;

    cout<<"\nTWORZE KONSTRUKTOREM KOPIUJACYM I WYPISUJE TABLICE [t2] (jako kopia tablicy [t])"<<endl;
    Tablica t2(t);
    cout<<"t2 = "<<t2<<"; - rozmiar tablicy: "<<t2.rozmiar_tablicy()<<endl;

    cout<<"\n\n[TEST 2] - TABLICA [t1] - wypelniam tablice kolejnymi liczbami naturalnymi"<<endl<<endl;
    int a=1;
    for(int i=0; i< t1.rozmiar_tablicy(); i++)
    {
        t1.wstaw_koniec(a);
        a++;
    }
    cout<<"Uzupelniona tablica [t1]: "<<t1<<endl;

    cout<<"\n\n[TEST 3] - TABLICA [t]" <<endl<< "\nTEST AUTOMATYCZNEGO POWIEKSZANIA TABLICY O WARTOSCIACH POCZATKOWYCH default: "<<endl
        <<"wprowadzenie do tablicy 10 elementow"<<endl
        <<"\ntablica poczatkowa t = "<<t<<endl;

    cout<<"\nWypelnianie tablicy: "<<endl;
    cout<<"----------------------------------------------------------";
    for(int i=0; i< 10; i++)
    {
        t.wstaw_koniec(a);
        a++;
    }
     cout<<"----------------------------------------------------------"<<endl;
    cout<<"Koniec aypelniania tablicy."<<endl;

    cout<<"\nUzupelniona tablica t = "<<t<<endl
    <<"Rozmiar tablicy po zmianach: "<<t.rozmiar_tablicy()<<endl;

    cout<<"\n\n[TEST 4] - TABLICA [t] - dodawanie/usuwanie elementow" <<endl;

    cout<<"\nDODAJE PIERWSZY ELEMENT o wartosci 66"<<endl;
    t.wstaw_poczatek(66);
    cout<<"\nTablica po wprowadzeniu danych: "<<t<<endl;

    cout<<"\nUSUWAM PIERWSZY ELEMENT o wartosci 66"<<endl;
    t.usun_poczatek();
    cout<<"\nTablica po wprowadzeniu danych: "<<t<<endl;

    cout<<"\n\n[TEST 5] - POLACZENIE TABLICY [t1] i [t]."<<endl
    <<"\nPRZYPISANIE TEJ WARTOSCI DO TABLICY [t] przez operator="<<endl;

    t=t.polacz(t1);
    cout<<"\nWartosci tablicy [t] po polaczeniu: "<<t<<endl;

    cout<<"\n\nMOZESZ KONTYNUOWAC PRACE NA TABLICY [t]"<<endl;

    char decyzja;
    int x;
    cout<<"\nNacisnij:\n"
        "D - dodanie  koniec\n"
        "U - usuniecie koniec\n"
        "W - wypisz\n"

        "A - usun wszystkie elementy tablicy\n"
        "B - podaj liczbe elementow tablicy\n"
        "C - podaj rozmiar tablicy\n"
        "X - podaj wartosc pierwszego elementu\n"
        "E - podaj wartosc ostatniego elementu\n"
        "F - zamien tablice\n"

        "G - zmien rozmiar tablicy\n"
        "H - zmien liczbe elementow tablicy\n"

        "I - dodanie poczatek\n"
        "Q - usuwanie poczatek\n"
        "S - polaczenie 2 tablic\n"

        "K - koniec programu\n"
        ;
    while (cin>>decyzja && (decyzja=toupper(decyzja))!='K')
    {
        while (cin.get()!= '\n');
        switch(decyzja)
        {
        case 'D':
            cout<<"Podaj wartosc do wstawienia: ";
            cin>>x;
            t.wstaw_koniec(x);

            break;
        case 'U':
            if (t.czypusta())
                cout<<"Tablica pusta!\n";
            else
            {
                t.usun_koniec(x);
                cout<<"Wartosc "<<x<<" usunieta\n";
            }
            break;
        case 'W':
            if (t.czypusta())
                cout<<"Tablica pusta!\n";
            else
                cout<<"Wartosci w tablicy: "<<t<<endl;
            break;

        default:
            cout<<"Niepoprawny wybor\n";
            break;

        case 'A':
            if (t.czypusta())
                cout<<"Tablica pusta!\n";
            else
            {
                t.usun_wszystkie_elementy();
                cout<<"Wszystkie elementy tablicy usuniete\n";
            }
            break;

        case 'B':
            if (t.czypusta())
                cout<<"Tablica pusta!\n";
            else
            {
                cout<<"Tablica zawiera elementow: "<<t.liczba_elementow()<<endl;
            }
            break;

        case 'C':

            cout<<"Tablica ma rozmiar (ilosc elementow jakie przyjmie): "<<t.rozmiar_tablicy()<<endl;

            break;

        case 'X':
            if (t.czypusta())
                cout<<"Tablica pusta!\n";
            else
            {
                cout<<"Pierwszy element tablicy to: "<<t.pierwszy_element()<<endl;
            }
            break;

        case 'E':
            if (t.czypusta())
                cout<<"Tablica pusta!\n";
            else
            {
                cout<<"Ostatni element tablicy to: "<<t.ostatni_element()<<endl;
            }
            break;


        case 'F':
            cout<<"Tablica 1: "<<t1<<endl;
            cout<<"Tablica 2: "<<t<<endl;

            cout<<"ZAMIANA (metoda)"<<endl;

            t.zamien(t1);

            cout<<"Tablica 1: "<<t1<<endl;
            cout<<"Tablica 2: "<<t<<endl;


            break;


        case 'G':

            int nr;
            cout<<"Tablica przed zmiana: "<<t<<endl;
            cout<<"Rozmiar tablicy: "<<t.rozmiar_tablicy()<<"\nPodaj nowy rozmiar tablicy"<<endl;
            cin>>nr;

            if(nr<t.liczba_elementow())
            {
                cout<<"Podany rozmiar jest mniejszy od liczby elementow tablicy. \nRozmiar tablicy zostal zmieniony na "<<t.liczba_elementow()<<" aby uniknac utraty danych.\nJesli chcesz ustawic mniejszy rozmiar tablicy zmniejsz najpierw ilosc elementow tablicy."<<endl;
                nr=t.liczba_elementow();
            }

            t.ustaw_rozmiar(nr);

            cout<<"Tablica po zmianie: "<<t<<endl;
            cout<<"Rozmiar tablicy: "<< t.rozmiar_tablicy()<<endl;

            break;

        case 'H':

            int nn;

            do
            {
                cout<<"Podaj nowa liczbe elementow [liczba>=0]: "<<endl;
                cin>>nn;
            }
            while(nn<0);

            t.ustaw_liczbe_elementow(nn);

            break;


        case 'I':
            cout<<"Podaj wartosc do wstawienia: ";
            cin>>x;
            t.wstaw_poczatek(x);

            break;


        case 'Q':
            if (t.czypusta())
                cout<<"Tablica pusta!\n";
            else
            {
                cout<<"Wartosc "<<t.pierwszy_element()<<" usunieta\n";
                t.usun_poczatek();

            }
            break;

        case 'S':
            if (t.czypusta()||t1.czypusta())
                cout<<"Co najmniej jedna tablica jest pusta! Polaczenie tablic  nie jest mozliwe\n";
            else
            {
                t=t.polacz(t1);
                cout<<"Wartosci tablicy po polaczeniu"<<t<<endl;

            }
            break;


        }

    }


    cout << "Konczymy na dzis!\n";

    return 0;
}

