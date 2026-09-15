#include <iostream>
using namespace std;

int main()
{

    int a, b;
    bool poprawne = true;


    do
    {
        cout<<"Podaj 2 liczby calkowite dodatnie."<<endl;
        cin>>a>>b;

        poprawne = true;

        if(cin.fail() || a<=0 || b<=0)
        {
            cout<<"Podales bledne dane."<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
            poprawne = false;
        }

    }
    while(!poprawne);

    int liczba1=a, liczba2=b;

    while(a != b)
    {
        if(b>a)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int r=a-b;
        a = b;
        b = r;
    }

    cout<<"\nNWD liczb "<<liczba1<<" i "<<liczba2<<" to: "<<a<<endl;

    return 0;
}
