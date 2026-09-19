#include <iostream>
using namespace std;


int fibRek(int n)
{

    if(n==0)
    {
        cout<<"F(0) = 0"<<endl;
        return 0;
    }
    else if(n==1)
    {
        cout<<"F(1) = 1"<<endl;
        return 1;
    }
    else
    {
        int wynik = fibRek(n-1) + fibRek(n-2);
        cout<<"F("<<n<<") = "<<wynik<<endl;
        return wynik;
    }
}



int main()
{
    int n;

    cout<<"Podaj numer liczby Fibonacciego z zakresu [0 - 20]"<<endl;
    cout<<"Zakres zostal ograniczony celowo, aby uzytkownik nie starcil cierpliwosci czekajac na wynik."<<endl;
    cin>>n;

    if(n<0 || n>20)
    {
        cout<<"\nWybrales numer poza zakresem. Numer zostal ustawiony na n=10."<<endl;
        n=10;
    };

    cout<<endl<<"TAK WYGLADAJA OBLICZENIA:"<<endl<<fibRek(n)<<" - to wyraz ciagu Fibonacciego o indeksie "<<n<<endl;

    return 0;
}
