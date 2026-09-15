#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


bool czy_trojkat(double a_, double b_, double c_)
{
    return (a_+b_>c_ && a_+c_>b_ && b_+c_>a_);
}

bool czy_prostokatny(double a_, double b_, double c_)
{
    double a2 = a_*a_;
    double b2 = b_*b_;
    double c2 = c_*c_;

    return (a2+b2==c2 || b2+c2==a2 || a2+c2==b2);
}

int main()
{


    double a, b, c;

    cout << "Podaj dlugosci bokow trojkata"<< endl;

    do
    {
        cin>> a >> b >> c;

        if((a<=0 || b<=0 || c<=0))
        {
            cout<<"Podaj prawidlowe dlugosci bokow a, b, c > 0: "<<endl;
        }

    }
    while(a<=0 || b<=0 || c<=0);


    if(czy_trojkat(a, b, c))
    {

        cout<<"Z podanych odcinkow mozna zbudowac trojkat."<<endl;

        double ob = a + b + c;
        double p_ob = ob/2;

        double p = sqrt(p_ob*(p_ob-a)*(p_ob-b)*(p_ob-c));

          cout<<"Pole trojkata wynosi: "<<fixed<<setprecision(2)<<p<<" [j2]\nObwod trojkata wynosi: "<<ob<<" [j]."<<endl;

        if(czy_prostokatny(a, b, c))
        {
            cout<<"\nTrojkat jest prostokatny."<<endl;
        }
        else
        {
            cout<<"\nTrojkat nie jest prostokatny."<<endl;
        }
    }

else {cout<<"Z podanych odcinkow nie mozna zbudowac trojkat."<<endl;}
    return 0;
}
