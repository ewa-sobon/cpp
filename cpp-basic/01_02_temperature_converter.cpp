#include <iostream>
#include <clocale>

using namespace std;

int main ()
{

    setlocale(LC_ALL, "");
    double temp_C;

    cout << "Podaj temperature w stopniach Celsjusza (°C)." << endl;
    cin >> temp_C;

    double temp_K = temp_C + 273.15;
    double temp_F = 32 + 1.8* temp_C;

    cout << temp_C << "°C to: " << temp_K << "K (Kelvinow) oraz "<< temp_F << "°F (stopni Fahrenheita)."<<endl<<endl;

    cout << "Zauwaz ze:"<<endl<<"przy standardowym cisnieniu atmosferycznym (1012 hPa):"<<
            endl<<"- woda wrze w temperaturze 100°C / 373,15K / 212°F."<<
            endl<<"- woda zamarza w temperaturze 0°C / 273,15K / 32°F.";
    return 0;
}
