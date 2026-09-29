#ifndef KONTO1_H_INCLUDED
#define KONTO1_H_INCLUDED
#include <iostream>

class Konto
{

private:
    const int numer;
    std::string nazwa;
    double saldo;
    double oprocentowanie;

public:
    Konto()=delete;
    Konto(const Konto&)=delete;
    Konto(int, std::string, double, double=0.035);
    ~Konto();

    double wplac(double);
    double wyplac(double);
    double dolicz_odsetki();

    friend void wyswietl(const Konto&);
    friend std::ostream& operator<<(std::ostream&, const Konto&);
};


#endif // KONTO1_H_INCLUDED

