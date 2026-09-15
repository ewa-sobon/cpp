#include <iostream>
#include <ctime>
using namespace std;


bool leap_year(int year_)
{
    return (year_%400 == 0 || (year_%4==0 && year_%100!=0));
}

bool date_ok(int year_, int month_, int day_)
{
    int year_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(leap_year(year_))
    {
        year_days[1]=29;
    }

    return !(year_<1900 || (month_<1 || month_>12) || day_<1 || day_>year_days[month_-1]);

}

int main()
{

    time_t now = time(nullptr);
    tm* date = localtime(&now);

    int now_day = date->tm_mday;
    int now_month = date->tm_mon + 1; // Array positions start at 0, so we add 1
    int now_year = date->tm_year + 1900; // Add 1900 to get the correct year

    int year_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int birth_year, birth_month, birth_day;

    cout << "Enter your date of birth [YYYY MM DD]: " << endl;

    bool again=false;

    do
    {
        again=false;
        cin >> birth_year >> birth_month >> birth_day;

        if(birth_year>now_year || (birth_year==now_year && birth_month > now_month) || (birth_year==now_year && birth_month == now_month && birth_day>now_day))
        {
            cout<<"You haven't been born yet."<<endl;
            cout<<"Enter a valid date of birth [YYYY MM DD]: " << endl;
            again=true;
            continue;
        }

        if(birth_year<1909)
        {
            cout<<"You would be older than the oldest person in the world."<<endl;
            cout<<"Enter a valid date of birth [YYYY MM DD]: " << endl;
            again=true;
            continue;
        }

        if (!(date_ok(birth_year, birth_month, birth_day)))
        {
            cout<<"Enter a valid date of birth [YYYY MM DD]: " << endl;
            again=true;
        }
    }
    while(again);


    int user_years = 0;
    int user_months = 0;
    int user_days = 0;

    if(leap_year(now_year))
    {
        year_days[1]=29;
    }

    if(now_month > birth_month)
    {
        user_years = now_year - birth_year;

        if(now_day >= birth_day)
        {
            user_months = now_month - birth_month;
            user_days = now_day - birth_day;
        }

        else //now_day < birth_day
        {
            user_months = now_month - birth_month -1;
            user_days = now_day + year_days[now_month -1 - 1] - birth_day;
        }
    }

    else if(now_month < birth_month)
    {
        user_years = now_year - birth_year -1;

        if(now_day > birth_day)
        {
            user_months = 12 - now_month + birth_month;
            user_days = now_day - birth_day;
        }
        else //now_day < birth_day
        {
            user_months = 12 - now_month + birth_month -1;
            user_days = now_day + year_days[now_month -1 - 1] - birth_day;
        }
    }
    else // now_month = user_months
    {
        if(now_day >= birth_day)
        {
            user_years = now_year - birth_year;
            user_months = 0;
            user_days = now_day - birth_day;
        }

        else //now_day < birth_day
        {
            user_years = now_year - birth_year -1;
            user_months = 0;
            user_days = now_day + year_days[now_month -1 - 1] - birth_day;
        }
    }

    if(user_months==0 && user_days==0)
    {
        cout<<"\nYou are "<<user_years<<" years old. Today is your birthday. HAPPY BIRTHDAY!"<<endl;
    }

    else
    {
        cout<<"\nYou are "<<user_years<<" years, "<<user_months<<" months, and "<<user_days<<" days old."<<endl;

        int days = 0;

        if(now_month>birth_month)
        {
            days = year_days[now_month-1]-now_day; //days remaining in the current month

            for(int i=now_month; i<12; i++)       // remaining months of this year
            {
                days+=year_days[i];
            }

            if(leap_year(now_year+1))
            {
                year_days[1]=29;
            }
            else
            {
                year_days[1]=28;
            }

            for(int i=0; i<(birth_month-1); i++) // months of the next year until birth month
            {
                days+=year_days[i];
            }

            days+= birth_day; // days in the birth month
        }

        else if(now_month<birth_month)
        {
            days = year_days[now_month-1]-now_day; //days remaining in the current month

            for(int i=now_month; i<(birth_month-1); i++) // remaining months until birth month
            {
                days+=year_days[i];
            }

            days+= birth_day; //days in the birth month
        }

        else
        {
            if(now_day>birth_day)
            {
                days = 365 - now_day + birth_day;
            }
            else
            {
                days = birth_day - now_day;
            }
        }

        cout<<"\nDays until your next birthday:"<<days<<" days."<<endl;
    }

    cout<<"\nBased on age criteria in Poland:"<<endl;
    if(user_years>=35)
    {
        cout<<"- You are an adult. You can legally buy alcohol."<<endl
            <<"- You can run for the Sejm (lower house of parliament)."<<endl
            <<"- You can run for the Senate."<<endl
            <<"- You can run for President."<<endl;
    }

    else if(user_years>=30)
    {
        cout<<"- You are an adult. You can legally buy alcohol."<<endl
            <<"- You can run for the Sejm (lower house of parliament)."<<endl
            <<"- You can run for the Senate."<<endl;
    }

    else if(user_years>=21)
    {
        cout<<"- You are an adult. You can legally buy alcohol."<<endl
            <<"- You can run for the Sejm (lower house of parliament)."<<endl;
    }

    else if(user_years>=18)
    {
        cout<<"- You are an adult. You can legally buy alcohol."<<endl;
    }

    else
    {
        cout << "- You are a minor. You cannot legally buy alcohol and you do not have voting rights." << endl;
    }

    return 0;
}
