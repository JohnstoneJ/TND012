// ===============================================================
// Julia Johnstone
// 990117-5720
// ===============================================================

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //declare variables
    int date, year, month, day;

    int const SMALLEST_YEAR = 1000;
    int const HIGHEST_YEAR = 9999;

    bool invalid_input = false;

    string inValid = "Invalid date!!";

    //a do-while loop who repeats the the question for user input
    do
    {
        //Ask user for date
        cout << endl << "Enter a date: " ;
        cin >> date;

        //if the user input is negative
        invalid_input= (date<0);
        if ( invalid_input )
        {
            cout << "Bye ..." << endl;
        }
        while (invalid_input);

        //separate year from date
        year = date/ 10000;
        year = int(year);
        //separate month from date
        month = date / 100 % 100;
        //separate year from date
        day = date % 100;

        //if the year is valid
        if((year >= SMALLEST_YEAR) && ((12>=month)&& (month>0)) && (HIGHEST_YEAR >= year))
        {
            //check how many days the month can have
            switch(month)
            {
            case 2:
                //leap year
                if ( (( (year % 4 == 0) && (year % 100 != 0) &&(day<=29)) ||
                        ((year % 400 == 0 ) &&(day<=29))) || ((0<day )&&(day<=28)))
                {
                    cout << "Date "<< date << " is valid!!" << endl;
                }
                else
                {
                    cout<< inValid <<endl;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(0<day && day<=30)
                {
                    cout << "Date "<< date << " is valid!" << endl;
                }

                else
                {
                    cout<< inValid <<endl;
                }
                break;
            default:
                if((0<day && day<=31))
                {
                    cout << "Date "<< date << " is valid!!" << endl;
                }
                else
                {
                    cout<< inValid <<endl;
                }
            }
        }
        else
        {
            cout<< inValid << endl;
        }
    }
    while(invalid_input == false);
    return(0);
}
