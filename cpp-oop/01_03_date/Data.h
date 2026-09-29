#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <iostream>


class Data
{
private:
    int dzien{8};       // alternatywnie int dzien = 1;
    int miesiac{3};     // alternatywnie int miesiac = 1;
    int rok{2026};      // alternatywnie int rok = 2000;

public:
    Data()=default;
    Data(int d, int m, int r);
    // destruktor jest zbedny bo nie zarzadzam pamiecia dynamiczna;

    int get_dzien()const;
    int get_miesiac()const;
    int get_rok()const;

    void set_dzien(int d);
    void set_miesiac(int m);
    void set_rok(int r);

    void wyswietl()const;

    bool czy_rowne(const Data& d)const;

    bool czy_pozniejsza(const Data& d) const;
};

#endif // DATA_H_INCLUDED


