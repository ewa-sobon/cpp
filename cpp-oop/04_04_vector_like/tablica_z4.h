#ifndef TABLICA1_H_INCLUDED
#define TABLICA1_H_INCLUDED
#include <iostream>

class Tablica
{
private:
    int rozmiar{0};
    int *tab{nullptr};
    int n{0};
public:
    Tablica()=default;
    Tablica(int);
    Tablica(const Tablica&);
    ~Tablica();

    void wstaw_koniec(const int&); //zmieniam na void, bo nie potrzebuje juz false. Zawsze bedzie true
    void wstaw_poczatek(const int&);

    bool usun_koniec(int&);
    bool usun_poczatek();

    Tablica& operator=(const Tablica&);
    int& operator[](unsigned);

    friend std::ostream& operator<<(std::ostream&,const Tablica&);

    bool czypelna();
    bool czypusta();
    bool czyistnieje();

    void usun_wszystkie_elementy();
    int liczba_elementow()const;
    int rozmiar_tablicy()const;
    int pierwszy_element()const;
    int ostatni_element()const;

    void zamien(Tablica& t);

    void powieksz();

    void ustaw_rozmiar(int nr);

    void ustaw_liczbe_elementow(int nn);

    Tablica polacz(const Tablica& prawa)const;
};
#endif

