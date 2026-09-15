#include <iostream>
using namespace std;

int main()
{
    int h;

    do
    {
        cout<<"Podaj wysokosc figury. Dopuszczalna wartosc h > 2 oraz h < 16."<<endl;
        cin>>h;

        if(h<3 || h>15)
        {
            cout<<"\nPodales nieprawidlowa wartosc."<<endl;
        }
    }
    while(h<3 || h>15);

    cout<<endl<<endl;

    cout<<"TROJKAT PROSTOKATNY"<<endl;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<h; j++)
        {
            if(j<=i) cout<<"*";
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    cout<<"TROJKAT PROSTOKATNY ODWROCONY"<<endl;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<h; j++)
        {
            if(j>=h-i-1) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    cout<<"TROJKAT ROWNORAMIENNY"<<endl;
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<2*h; j++)
        {
            if(j>h-i && j<h+i) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    cout<<"PROSTOKAT PUSTY"<<endl;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<h; j++)
        {
            if(i==0 || i==h-1 || j==0 || j==h-1) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    cout<<"DELTOID"<<endl;
    for(int i=1; i<=h/2; i++)
    {
        for(int j=1; j<2*h; j++)
        {
            if(j>h-i && j<h+i) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    for(int i=h/2; i<h; i++)
    {
        for(int j=1; j<2*h; j++)
        {
            if(j>i && j<h*2-i)cout<<"*";
            else cout<<" ";

        }
        cout<<endl;
    }

    cout<<endl;

    return 0;
}
