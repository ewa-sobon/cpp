#ifndef KSIAZKA_H_INCLUDED
#define KSIAZKA_H_INCLUDED
#include <iostream>
#include <string>



class Ksiazka
{
private:
    std::string tytul="Przykladowy tytul.";
    std::string autor="Brak Autora";
    int rok=0;
    bool czy_dostepna=true;

public:
    Ksiazka()=default;
    Ksiazka(std::string t, std::string a, int r);
    ~Ksiazka();

    void wypisz()const;
    std::string get_tytul()const;
    std::string get_autor()const;
    int get_rok()const;
    bool get_czy_dostepna()const;

    void set_tytul(std::string t);
    void set_autor(std::string a);
    void set_rok(int r);
    void set_czy_dostepna(bool dostepnosc);
};


#endif // KSIAZKA_H_INCLUDED
