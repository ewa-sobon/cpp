#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{

    int rok;

    cout << "Podaj rok.\nDla roku przed nasza era wpisz minus przed rokiem (np. -4)" << endl;
    cin>>rok;

    string text;
    if(rok==0)
    {
        cout<<"\nW kalendarzu nie istnial rok 0. Po roku 1 p.n.e nastapil rok 1 n.e.";
        cout<<endl<<endl;
        return 0;
    }

    if(rok>0)
    {
        text = " n.e.";
    }
    else text = " p.n.e.";

    string s_rok = to_string(abs(rok)) + text;

    if(rok>1582)
    {
        if(rok%400 == 0 || (rok%4==0 && rok%100!=0))
        {
            cout<<"\nRok "<<s_rok<<" to rok przestepny.\nObliczenia wedlug kalendarza gregorianskiego, obowiazujacego od 1582 r. n.e.";
        }
        else cout<<"\nRok "<<s_rok<<" nie jest rokiem przestepnym.";
    }

    else if(rok >= 8)
    {
        if(rok%4==0) cout<<"\nRok "<<s_rok<<" byl rokiem przestepnym.\nObliczenia wedlug kalendarza julianskiego, obowiazujacego od 45 r. p.n.e.";
        else cout<<"\nRok "<<s_rok<<" nie byl rokiem przestepnym.";
    }

    else if(rok >= -9)
    {
        cout<<"\nRok "<<s_rok<<" nie byl rokiem przestepnym.\nOkres od 9 r. p.n.e. do 7 r. n.e. to czas wstrzymania dodawania lat przestepnych przez Oktawiana Augusta.\nMialo to na celu zlikwidowanie bledu obliczen popelnionego przez Rzymian.";
    }

    else if(rok >= - 45)
    {
        if(rok%3==0) cout<<"\nRok "<<s_rok<<" byl rokiem przestepnym.\nObliczenia wedlug kalendarza julianskiego, obowiazujacego od 45 r. p.n.e.\nW tych latach, w wyniku bledu Rzymian, rok przestepny liczono co 3 lata.";
        else cout<<"\nRok "<<s_rok<<" nie byl rokiem przestepnym.";
    }
    else
    {
        cout<<"\nLiczenie lat przestepnch zostalo zapoczatkowane po roku 45 p.n.e.\nWprowadzil je cesarz rzymski Juliusz Cezar.";
    }

    cout<<endl<<endl;
    return 0;
}
