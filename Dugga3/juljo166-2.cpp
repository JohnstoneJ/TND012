// ===============================================================
// Julia Johnstone
// 9901175720
// ===============================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**************************************
* Declaration of Debit_Note data type *
***************************************/

struct Debit_Note
{
    string license_plate;
    int dayOfMonth;
    int fee;
};

/*****************************
* Function declarations      *
******************************/
//Read data for an debit note
Debit_Note get();
int read_debit_notes(Debit_Note V[], int n, string &month);
void sort_days(Debit_Note V[], int n);
void sort_license_plates( Debit_Note V[], int n);
void do_invoice (Debit_Note V[], int n, string &month);

/******************************
* MAIN                        *
******************************/

int main()
{
    //DECLARE THE NEEDED CONSTANTS and VARIABLES HERE
    const int SIZE = 500;
    string month;

    Debit_Note DB[SIZE];
    int howMany = 0;

    // Read all debit notes
    howMany = read_debit_notes(DB, SIZE, month);

    //sort days of the month for each car, earliest date first
    sort_days(DB, howMany);

    //sort the license plates in alphabetical order
    sort_license_plates(DB, howMany);

    //display each invoice
    do_invoice (DB, howMany, month);

    return 0;
}

/*************************************
* Function definitions               *
**************************************/

// Read data for an debit note
Debit_Note get()
{
    Debit_Note dn;

    cin >> dn.license_plate >> dn.dayOfMonth >> dn.fee;

    return dn;

}
//Read debit notes data and store them in array V
//At most n records can be read
//Return the number of debit notes data read and stored in array V
int read_debit_notes(Debit_Note V[], int n, string &month)
{
    Debit_Note dn;
    int counter = 0; //count number of debit notes read

    cout << "Enter month followed by debit notes: ";
    cin >> month;

    dn = get();

    while (dn.license_plate != "STOP")
    {
        V[counter] = dn;
        ++counter;

        if(counter == n) // test if there is free slots in array V
        {
            break;
        }
        dn = get(); //read next debit note
    }
    return counter;
}

//sorting days of the month for each car, earliest date first
void sort_days(Debit_Note V[], int n)
{
    Debit_Note dn;
    int j, k;
    for (j = 1; j < n; j++)
    {
        for (k = 0; k < n - j; k++)
            if (V[k].dayOfMonth > V[k + 1].dayOfMonth)
            {
                dn = V[k];
                V[k] = V[k + 1];
                V[k + 1] = dn;
            }
    }
}

//bubble sorting the license plates in alphabetical order
void sort_license_plates(Debit_Note V[], int n)
{
    Debit_Note dn;
    int j, k;
    for (j = 1; j < n; j++)
    {
        for (k = 0; k < n - j; k++)
            if (V[k].license_plate > V[k + 1].license_plate)
            {
                dn = V[k];
                V[k] = V[k + 1];
                V[k + 1] = dn;
            }
    }
}

//display each invoice
void do_invoice ( Debit_Note V[], int n, string &month)
{
    cout << "Creating invoices . . ." << endl << endl;
    for(int i = 0; i < n; ++i)
    {
        //test if there are identical license plates
        if (((V[i-1].license_plate != V[i].license_plate)&&
                (V[i-1].license_plate != V[i+1].license_plate))
                || ((V[i].license_plate == V[i+1].license_plate)&&
                    (V[i-1].license_plate != V[i].license_plate)))
        {
            cout << "Invoice: " << V[i].license_plate;
            cout << endl << "Dates: " << month << "/" << V[i].dayOfMonth;
            // counting together the dates of identical license plates
            // summarizing the fee of the dates of identical license plates
            for (int k = i+1; k < n-1; k++)
            {
                if(( V[i].license_plate == V[k].license_plate ) && ( i!=k ) && ( i < k ))
                {
                    V[i].fee = V[i].fee + V[k].fee;
                    cout <<" " << month << "/" << V[k].dayOfMonth;
                }
            }
            cout << endl << "Amount to pay: " << V[i].fee << endl;
            cout << setw(40) << setfill('=') << "-"<< endl << endl;
        }
    }
}


