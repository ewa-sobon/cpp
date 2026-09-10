#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{

    srand(time(NULL));
    double dobre=0;
    float ocena;

    struct Para
    {
        int x;
        int y;
    };

    int a, b;

    Para wylosowane[10]={}; // tablica dobrych odpowiedzi
    Para bledy[10]={};      // tablica blednych odpowiedzi

    int p1=0, p2=0;         // p1 - ilosc pozycji zajetych w tablicy dobrych odp, p2 - ilosc pozycji w tablicy blednych odp

                    bool losuj = false;

    for(int i=1; i<=10; i++)
    {
        do
        {
            a = 2 + rand()% 9; //usuwam mnozenie *1
            b = 2 + rand()% 9;

            if(p1>0)
            {
                losuj = false;
                for(int j=0; j<p1; j++)
                {
                    if((a==wylosowane[j].x&&b==wylosowane[j].y) || (a==wylosowane[j].y&&b==wylosowane[j].x))
                        losuj=true;
                }
            }
        }
        while (losuj);

        int iloczyn;
        cout<<"\nIle wynosi "<<a<<" * "<<b<<" ?"<<endl;
        cin>>iloczyn;

        if(iloczyn == a*b)
        {
            dobre++;
            cout<<"Bardzo dobrze."<<endl;

            for(int i=0; i<=p1; i++)
            {
                if(wylosowane[i].x==0)
                {
                    wylosowane[i].x=a;
                    wylosowane[i].y=b;
                }
            }

            p1++;
        }
        else
        {
            cout<<"Poprawna odp to: "<<a*b<<endl;

             for(int i=0; i<=p2; i++)
            {
                if(bledy[i].x==0)
                {
                    bledy[i].x=a;
                    bledy[i].y=b;
                }
            }
            p2++;
        }
    }

    if(dobre == 10) ocena =5.0;

    else if(dobre == 9) ocena =4.5;

    else if(dobre == 8) ocena =4.0;

    else if(dobre ==7) ocena = 3.5;

    else if(dobre == 6) ocena =3.0;

    else ocena = 2.0;


    cout<<"\nLiczba prawidlowych odpowiedzi: "<<dobre<<". Jest to "<< (dobre/10)*100 <<"%." <<endl;
    cout<<"Twoja ocena to: "<<ocena<<endl;

   if(p1>0){
    cout<<"\nTwoje prawidlowe odpowiedzi: "<<endl;
    for(int i=0; i<p1; i++)
    {
        cout<<wylosowane[i].x<<" * "<<wylosowane[i].y<< " = "<<wylosowane[i].x*wylosowane[i].y<<endl;
    }
   }

    if(p2>0){
    cout<<"\nDo nauki: "<<endl;
    for(int i=0; i<p2; i++)
    {
        cout<<bledy[i].x<<" * "<<bledy[i].y<< " = "<<bledy[i].x*bledy[i].y<<endl;
    }
    }
    return 0;
}
