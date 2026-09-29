#ifndef MACIERZN_H_INCLUDED
#define MACIERZN_H_INCLUDED
#include <iostream>

class MacierzN
{

private:
    int n;
    int *tablica;

public:
    MacierzN(int nn);
    ~MacierzN();
    MacierzN(const MacierzN&);

    friend std::ostream& operator<<(std::ostream& o, const MacierzN& m);

    friend std::istream& operator>>(std::istream& i, MacierzN& m);

    MacierzN& operator=(const MacierzN&);

    friend MacierzN operator+(const MacierzN&, const MacierzN&);

    friend MacierzN operator-(const MacierzN&, const MacierzN&);

    friend MacierzN operator*(const MacierzN&, int liczba);
};

#endif // MACIERZN_H_INCLUDED


