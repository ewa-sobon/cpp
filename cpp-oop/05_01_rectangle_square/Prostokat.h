#ifndef PROSTOKAT_H_INCLUDED
#define PROSTOKAT_H_INCLUDED

#include <iostream>

class Prostokat
{
protected:
    double bok1{0};
    double bok2{0};

    mutable double pole_wartosc{0};
    mutable bool pole_obliczone{false};

    mutable double obwod_wartosc{0};
    mutable bool obwod_obliczone{false};

public:
    Prostokat()=default;
    Prostokat(double,double);
    ~Prostokat();
    double pole() const;
    double obwod() const;

    void zmien_bok(double, double);

    void wypisz()const;

    double get_pole_wartosc() const; // gettery potrzebne tylko do testow dzialania pol mutable w klasie Prostokat
    double get_obwod_wartosc() const; // gettery potrzebne tylko do testow dzialania pol mutable w klasie Prostokat
};

class Kwadrat :public Prostokat
{
public:
    Kwadrat();
    Kwadrat(double);
    ~Kwadrat();
    void wypisz()const;
    void zmien_bok(double);
};

#endif // PROSTOKAT_H_INCLUDED

