//
//  main.cpp
//  PRG-6-15-Overloaded-Hospital
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that computes and displays the charges for a patient's hospital
//  stay. First, the program should ask if the patient was admitted as an inpatient or an
//  outpatient. If the patient was an inpatient, the following data should be entered:
//
//  * The number of days spent in the hospital
//  * The daily rate
//  * Hospital medication charges
//  * Charges for hospital services (lab tests, etc.)
//
//  The program should ask for the following data if the patient was an outpatient:
//
//  * Hospital medication charges
//  * Charges for hospital services (lab tests, etc.)
//
//  The program should use two overloaded functions to calculate the total charges. One
//  of the functions should accept arguments for the inpatient data, while the other function
//  accepts arguments for outpatient information. Both functions should return the
//  total charges.
//
//  Input Validation: Do not accept negative numbers for any data.

#include <iostream>
#include <iomanip>

using namespace std;

// Declare functions
bool inpatientOrOutPatient();
void getInputData(bool, int &, float &, float &, float &);
float calcPayment(int, float, float, float);
float calcPayment(float, float);

float fltTotalCost;

int main()
{
    // Declare variables
    bool booIsInpatient;                    // Used to determine if inpatient or outpatient
    
    int intDaysInHospital;                  // Used to track inpatient visit length
    
    float fltDailyRate;                     // Used to track daily rate of stay
    float fltHospitalMedicationCharges;     // Used to track medication charges (inpatient & outpatient)
    float fltHospitalServicesCharges;       // Used to track hospital service charges (inpatient & outpatient)
    
    //  Use function to query user if patient is inpatient or outpatient
    //  to pass to later overloaded functions
    booIsInpatient = inpatientOrOutPatient();
    
    //  If true, pass booIsInpatient to overloaded function to get user input on length of stay,
    //  daily rate, medication charges, and service charges
    if(booIsInpatient == true)
    {
        getInputData(booIsInpatient, intDaysInHospital, fltDailyRate, fltHospitalMedicationCharges, fltHospitalServicesCharges);
        fltTotalCost = calcPayment(intDaysInHospital, fltDailyRate, fltHospitalMedicationCharges, fltHospitalServicesCharges);
    }
    //  Else, pass booIsInpatient to overloaded fucntion to get user input on
    //  medication charges and service charges
    else
    {
        getInputData(booIsInpatient, intDaysInHospital, fltDailyRate, fltHospitalMedicationCharges, fltHospitalServicesCharges);
        fltTotalCost = calcPayment(fltHospitalMedicationCharges, fltHospitalServicesCharges);
    }
    
    //  Configure output precision for dollar amount
    cout << setprecision(2) << fixed << showpoint;
    
    //  Output total based on user inputs
    cout << "The total balance due by the patient is $" << fltTotalCost << endl;
    
    return 0;
}

//  Function used to get user input and set booIsTrue in main() to true or false
//  based on user input
bool inpatientOrOutPatient()
{
    //  Use string as input to store T/F as well as True/False values
    string strIsInpatient;
    
    //  Redeclare for use in this function, not globally
    //  passing through bool not using reference variable
    bool booIsInpatient;
    
    //  Request user input and define cases and error check
    cout << "Please enter true or false:\n"
    << "Was this admission inpatient?\n";
    cin >> strIsInpatient;
    while(strIsInpatient != "true" && strIsInpatient != "false" &&
          strIsInpatient != "True" && strIsInpatient != "False" &&
          strIsInpatient != "TRUE" && strIsInpatient != "FALSE" &&
          strIsInpatient != "t" && strIsInpatient != "f" &&
          strIsInpatient != "T" && strIsInpatient != "F")
    {
        cout << "Please enter true or false:\n";
        cin.ignore();
        cin.clear();
        cin >> strIsInpatient;
    }
    
    //  Set booIsInpatient to false or true based on user inputs,
    //  define valid cases
    if(strIsInpatient == "false" || strIsInpatient == "False" || strIsInpatient == "FALSE" ||
       strIsInpatient == "f" || strIsInpatient == "F")
    {
        booIsInpatient = false;
    }
    //  Set booIsInpatient to true
    else if(strIsInpatient == "true" || strIsInpatient == "True" || strIsInpatient == "TRUE" ||
            strIsInpatient == "t" || strIsInpatient == "T")
    {
        booIsInpatient = true;
    }
    //  Define exception case and define error message
    else
    {
        cout << "ERROR ASSIGNING INPATIENT/OUTPATIENT";
        return 0;
    }
    
    //  Return validated booIsInpatient
    return booIsInpatient;
}

//  This function gets all other user inputs used to calculate total cost,
//  for both inpatient and outpatient stays by reading. Use reference variables
//  to modify the original variables without having to declare global variables
void getInputData(bool booIsInpatient, int &refDays, float &refRate, float &refCharges, float &refServices)
{
    //  Get user inputs for inpatient stay, data validation,
    //  and ranges are defined
    if(booIsInpatient == true)
    {
        cout << "This is a data request for an inpatient stay.\n"
        << "Please enter the number of days of the patient's stay:\n";
        cin >> refDays;
        while(!cin || refDays <= 0 || refDays > 30)
        {
            cout << "That is not a valid number of days:\n";
            cin.ignore();
            cin.clear();
            cin >> refDays;
        }
        
        cout << "Please enter the hospital's daily rate:\n";
        cin >> refRate;
        while(!cin || refRate <= 0.0f || refRate > 3000.0f)
        {
            cout << "That is not a valid daily rate:\n";
            cin.ignore();
            cin.clear();
            cin >> refRate;
        }
        
        cout << "Please enter the patient's medication charges:\n";
        cin >> refRate;
        while(!cin || refCharges <= 0.0f || refCharges > 30000.0f)
        {
            cout << "That is not a valid total for charges:\n";
            cin.ignore();
            cin.clear();
            cin >> refCharges;
        }
        
        cout << "Please enter the hospital's service charges:\n";
        cin >> refServices;
        while(!cin || refServices <= 0.0f || refServices > 30000.0f)
        {
            cout << "That is not a valid total for charges:\n";
            cin.ignore();
            cin.clear();
            cin >> refServices;
        }
    }
    //  Get user inputs for outpatient stay,
    //  include data validation and range limits
    else if(booIsInpatient == false)
    {
        cout << "This is a data request for an outpatient stay.\n";
        cout << "Please enter the patient's medication charges:\n";
        cin >> refCharges;
        while(!cin || refCharges <= 0.0f || refCharges > 30000.0f)
        {
            cout << "That is not a valid total for charges:\n";
            cin.ignore();
            cin.clear();
            cin >> refCharges;
        }
        
        cout << "Please enter the hospital's service charges:\n";
        cin >> refServices;
        while(!cin || refServices <= 0.0f || refServices > 30000.0f)
        {
            cout << "That is not a valid total for charges:\n";
            cin.ignore();
            cin.clear();
            cin >> refServices;
        }
    }
    //  Error message if booIsInpatient is not defined
    else
    {
        cout << "ERROR BOOL NOT ASSIGNED";
    }
}

//  Overloaded function calculates cost based on inputs validated in previous function
float calcPayment(int Days, float Rate, float Charges, float Services)
{
    fltTotalCost = Days * Rate + Charges + Services;
    
    return fltTotalCost;
}

//  Overloaded function determines outpatient charges based on
//  inputs validated in previous function
float calcPayment(float Charges, float Services)
{
    fltTotalCost = Charges + Services;
    
    return fltTotalCost;
}


