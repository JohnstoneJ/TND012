// ===============================================================
// Julia Johnstone
// 9901175720
// ===============================================================

#include <iostream>

using namespace std;

int main()
{
    //declare variables
    const int SIZE = 200; //max value of array
    const int STOP = 0;

    int howMany;
    int a, b, c;
    int value;
    int seq[SIZE]= {0};

    bool invalid_input = false;

    //a do-while loop who repeats the the question for user input
    do
    {
        howMany = 0;
        int found=0;

        //ask for user input
        cout <<endl<< "Enter a list: " << endl;
        cin >> value; // read

        //if the user input is negative
        invalid_input= (value <0);
        if ( invalid_input )
        {
            cout << "Exiting ...!" << endl;
        }
        while (invalid_input);


        while ((value >= STOP) && (howMany < SIZE))
        {   if (howMany == SIZE) break;
            seq[howMany] = value; //store value in the array
            ++howMany; //increment sequence's size
            cin >> value; // read next value

        }

        // bubble sort
        for (int pass = 1; pass <= howMany-1; pass++)
            for(int i =0; i < howMany-1; i++)
            {
                if(seq[i] > seq[i+1])
                {
                    //swap
                    int number = seq[ i ];
                    seq[ i ] = seq[ i + 1 ];
                    seq[ i + 1 ] = number;
                }
            }

        cout <<endl;

        for(int i = 0; i < howMany-2; i++)//select an element
        {
            for(int j=i+1; j <howMany-1; j++)//select an element in front of the considered element
            {
                for(int k =i+2; k<howMany; k++)
                {
                    a = seq[i];
                    b = seq[j];
                    c = seq[k];

                    //conditions of Pythagoras
                    bool pythagoras =((a*a + b*b == c*c)  && a!=0);

                    //if Pythagoras triple is found
                    if( pythagoras == true )
                    {
                        cout <<"("<< a <<", "<<b<<", " <<c<<")"<<endl;
                        found = 1; //found

                    }
                }
            }
        }
        // triple not found
        if(found==0)
        {
            cout << "No triples found!!"<< endl;
        }
    }

    while (invalid_input==false);


}
