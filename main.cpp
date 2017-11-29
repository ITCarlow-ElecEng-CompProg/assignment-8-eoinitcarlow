/*Eoin Finlay
  Op Amps
  25 Oct 2017*/

//Preprocessor Directives
#include <iostream>

using namespace std;

//Main Function
int main()
{
    //Variable declarations
    char userChoice;

    //Local Function Declarations
    void invert(void);
    void nonInvert(void);
    char menu(void);

    //do while loop, continue while user choice is not q
    do
    {
        //calling menu function
        userChoice = menu();


        //switch case statement to run menu
        switch (userChoice)
        {
            case 'a': invert();//calling invert function
                      break;

            case 'b': nonInvert();//calling non invert function
                      break;

            case 'q': cout << "\n\nGoodbye!!" << endl;//quit program
                      break;

            default : cout << "\n\nInvalid Selection" << endl;
                      break;
        }
    }
    while (userChoice != 'q');

return 0;
}
//menu function header
char menu(void)
{
    //variable declaration
    char choice;

    //Displaying menu options to user and returning choice
    cout << "\nChoose from one of the following options" <<
    "\n\nPress a for an Inverting Op Amp" <<
    "\nPress b for a Non-Inverting Op Amp" <<
    "\nPress q to quit the program\n\n" << endl;

    cin >> choice;

return choice;
}
//invert function header
void invert(void)
{
    //variable declaration
    double Vcc, Vee, Vin, Rin=0, Rf=0, Av, Vout;
    double *Av_ptr, *Vout_ptr;

    //Assigning pointers to an address
    Av_ptr = &Av;
    Vout_ptr = &Vout;

    //invert calculation function declaration
    void invertCal(double, double, double, double, double, double*, double*);

    //Prompting usewr to enter values
    cout << "\n\nEnter value for Vcc: ";
    cin >> Vcc;
    cout << "\n\nEnter value for Vee: ";
    cin >> Vee;
    cout << "\n\nEnter value for Vin: ";
    cin >> Vin;

    //while loop to ensure Rin and Rf are greater than zero
    while ((Rin <=0 )||(Rf <=0 ))
    {
        cout << "\nEnter value greater than zero for Rin: ";
        cin >> Rin;
        cout << "\nEnter value greater than zero for Rf: ";
        cin >> Rf;
    }

    //calling invert calculation function
    invertCal(Vcc, Vee, Vin, Rf, Rin, Av_ptr, Vout_ptr);

    //displaying results
    cout << "\n\nGain = " << Av << endl;
    cout << "\nOutput Voltage = "<<Vout<<"V"<< endl;

return;
}

//invert calculation function header
void invertCal(double Vcc, double Vee, double Vin, double Rf, double Rin, double *Av_ptr, double *Vout_ptr)
{
//changing pointer values by way of an equation
*Av_ptr = -Rf / Rin;

*Vout_ptr = *Av_ptr * Vin;

    //if statement to limit Vcc and Vee if exceed accepted range
    if(*Vout_ptr > Vcc)
    {
       *Vout_ptr = Vcc;
    }

    else if (*Vout_ptr < Vee)
    {
       *Vout_ptr = Vee;
    }

    else
    {
        *Vout_ptr = *Vout_ptr;
    }

return;
}

//non invert function header
void nonInvert(void)
{

    //variable declarations
    double Vcc, Vee, Vin, R1=0, R2=0, Av, Vout;
    double *Av_ptr, *Vout_ptr;

    //assigning pointers to an address
    Av_ptr = &Av;
    Vout_ptr = &Vout;

    //non inver calculation function declaration
    void nonInvertCal(double, double, double, double, double, double*, double*);

    //prompting user to enter values
    cout << "\n\nEnter value for Vcc: ";
    cin >> Vcc;
    cout << "\n\nEnter value for Vee: ";
    cin >> Vee;
    cout << "\n\nEnter value for Vin: ";
    cin >> Vin;

    //while loop to ensure R1 and R2 are greater than zero
    while ((R1 <=0 )||(R2 <=0 ))
    {
        cout << "\nEnter value greater than zero for R1: ";
        cin >> R1;
        cout << "\nEnter value greater than zero for R2: ";
        cin >> R2;
    }

    //calling non invert cal function
    nonInvertCal(Vcc, Vee, Vin, R1, R2, Av_ptr, Vout_ptr);

    //displaying results
    cout << "\n\nGain = " << Av << endl;
    cout << "\nOutput Voltage = " <<Vout<<"V"<< endl;

return;
}
//non invert cal header
void nonInvertCal(double Vcc,double Vee,double Vin,double R1,double R2,double *Av_ptr,double *Vout_ptr)
{

//changing pointer values by way of an equation
*Av_ptr = 1 + (R2/R1);

*Vout_ptr = *Av_ptr * Vin;

    //if statement to ensure Vcc and Vee don't exceed accepted range
    if(*Vout_ptr > Vcc)
    {
       *Vout_ptr = Vcc;
    }

    else if (*Vout_ptr < Vee)
    {
       *Vout_ptr = Vee;
    }

    else
    {
        *Vout_ptr = *Vout_ptr;
    }

return;

}






